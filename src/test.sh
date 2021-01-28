#!/bin/bash

export CPP=g++
export CC=gcc
make clean
make
./pl-0 ./../pl0-programs/einfach-1 > /dev/null 2>/dev/null ; echo $?
./pl-0 ./../pl0-programs/syntaxfehler-1 > /dev/null 2>/dev/null ; echo $?
./pl-0 ./../pl0-programs/semantikfehler-1 > /dev/null 2>/dev/null ; echo $?
