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
    filename="${command}.hpp"  # Filename based on command name

    # Create the file with the command structure
    cat > "$filename" << EOF

#ifndef $(echo "$filename" | tr '[:lower:]' '[:upper:]')
# define $(echo "$filename" | tr '[:lower:]' '[:upper:]')

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class $command {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			$command(void);

			/* destructor */
			virtual ~$command(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			virtual bool execute(void) = 0;

			/* evaluate command */
			virtual bool evaluate(void) = 0;

            /* create command */
            irc::auto_ptr<irc::cmd> create(void);

		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			$command(const $command&);

			/* copy assignment operator */
			$command& operator=(const $command&);

	};

}

#endif
EOF

    echo "Created file: $filename"
done
