#!/bin/bash

cmake build
make -C build
echo "  **STARTING PROGRAM EXECUTION**"
echo ""
./build/Homework-App
echo ""
echo "  **PROGRAM EXECUTION FINISHED**"

