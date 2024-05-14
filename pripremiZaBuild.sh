#!/bin/sh

cd schedulers

input_file=$1
cfile="${input_file}.c"
hfile="${input_file}.h"

cp $cfile ../scheduler.c
cp $hfile ../scheduler.h

echo Built $input_file