#!/bin/bash

cmake --build ./build
echo -----------------------------
./build/test/test
