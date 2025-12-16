#!/bin/bash
rm -rf debug
cmake -S . -B debug -DCMAKE_BUILD_TYPE=Debug
cmake --build ./debug --config Debug
lldb-20 ./debug/test/test



