#!/bin/bash
#!/bin/bash

input_file="_numerics.txt"
output=""

# Check if the input file exists
if [ ! -f "$input_file" ]; then
    echo "Input file '$input_file' not found."
    exit 1
fi

# Read each line from the input file
while IFS= read -r line; do
    # Extract the command name and code from the line
    command=$(echo "$line" | awk -F '[(]' '{gsub(/[[:space:]]/, "", $1); print $1}')
    code=$(echo "$line" | awk -F '[(]' '{gsub(/[[:space:]()]/, "", $2); print $2}')

    # Convert command to lowercase and replace non-alphanumeric characters with underscores
    command_lowercase=$(echo "$command" | tr '[:upper:]' '[:lower:]' | tr -cs '[:alnum:]' '_')

    # Generate the final converted string
    converted_string="${command_lowercase}${code}"

    # Append the converted string to the output with a comma separator
    output+="$converted_string "

done < "$input_file"

# Remove the trailing comma
output="${output% }"

echo $output

commands=($output)  # List of commands

for command in "${commands[@]}"; do
    filename="${command}.cpp"  # Filename based on command name

    # Create the file with the command structure
    cat > "$filename" << EOF
#include "$command.hpp"

/* default constructor */
irc::$command::$command(void) {
    return;
}

/* destructor */
irc::$command::~$command(void) {
    return;
}

/* execute command */
bool irc::$command::execute(void) {
    return false;
}

/* evaluate command */
bool irc::$command::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::$command::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::$command());
}
EOF

    echo "Created file: $filename"
done
