#!/bin/bash

cmake --build ./build/release
echo -----------------------------
./build/release/Nigromante/test/test $1
