#!/bin/bash

cmake --build ./build
echo -----------------------------
./build/Nigromante/test/test $1
