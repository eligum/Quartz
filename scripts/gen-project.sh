#!/bin/sh

if [ ! -d Quartz ]; then
    cd ..
    if [ ! -d Quartz ]; then
        echo "Execute this script from the project-root or the scripts directory."
        exit 1
    fi
fi

premake5 gmake || echo "'premake5' executable could not be found, make sure it is in your PATH." && exit 1
