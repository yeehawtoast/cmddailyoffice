#!/bin/bash

# Get the directory where the script is located
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Delete .out, .o, and compiled C programs, excluding .sh files
find "$DIR" -type f \( -name "*.out" -o -name "*.o" -o -executable \) ! -name "*.sh" -exec rm -f {} \;

echo "Cleaned up .out, .o files, and compiled C programs (excluding .sh files) from $DIR."
