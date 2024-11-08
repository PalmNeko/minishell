#!/bin/bash

ENVS="$(env | awk -F'=' '{print $1}')"

# echo $ENVS
for i in $ENVS; do
    unset $i
done

unset _
/usr/bin/env