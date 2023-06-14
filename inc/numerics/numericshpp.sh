#!/bin/bash

# Create the file with the command structure
filename="numerics"
cat > "${filename}.hpp" << EOF

#ifndef $(echo "$filename" | tr '[:lower:]' '[:upper:]')_HPP
# define $(echo "$filename" | tr '[:lower:]' '[:upper:]')_HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- N U M E R I C S  N A M E S P A C E -------------------------------------------

	namespace numerics {

EOF

# Input file
input_file="numerics.txt"
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

# Remove the trailing space
output="${output% }"

echo $output

commands=($output)  # List of commands

for command in "${commands[@]}"; do

    echo $command

    # append 
    cat >> "${filename}.hpp" << EOF
        const std::string $command(irc::connection& conn);
EOF

done

cat >> "${filename}.hpp" << EOF

    }
}

#endif
EOF
