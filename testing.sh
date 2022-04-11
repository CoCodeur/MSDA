#!/bin/bash

cd build
cmake ..
cmake --build . --config Testing
ctest -C Testing 


