#!/bin/bash

cmake --build ./debug --config Debug
echo -----------------------------
lldb-20 ./debug/test/test
