#!/bin/bash

set -e 

BUILD_DIR="build"

# Check for existing directory and remove if so
if [ -d "$BUILD_DIR" ]; then
	rm -rf "$BUILD_DIR"
fi

# Make it 
cmake -B "$BUILD_DIR"
(cd $BUILD_DIR && make)
