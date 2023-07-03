#!/bin/bash

# Create a new detached screen session named "irssi"
screen -dmS irssi

# Split the first window vertically
screen -S irssi -X split -v

# Select the first split and run irssi with the first configuration
screen -S irssi -p 0 -X exec irssi -c ~/.irssi-1/

# Split the second window horizontally
screen -S irssi -X split -h

# Select the newly created split and run irssi with the second configuration
screen -S irssi -p 1 -X exec irssi -c ~/.irssi-2/

# Split the third window vertically
screen -S irssi -X split -v

# Select the last split and run the ircserv executable
screen -S irssi -p 2 -X exec ./ircserv

# Switch to the first split
screen -S irssi -p 0 -X focus

# Attach to the "irssi" screen session
screen -r irssi
