#!/bin/bash

cmake --build ./build/debug --config Debug
echo -----------------------------
lldb-20 ./build/debug/Nigromante/test/test
