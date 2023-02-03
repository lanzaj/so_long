#!/bin/bash

# array to store the numbers
numbers=($(seq 1 1000))

# shuffle the array
for i in $(seq 999 -1 1); do
  j=$((RANDOM % (i+1)))
  tmp=${numbers[$i]}
  numbers[$i]=${numbers[$j]}
  numbers[$j]=$tmp
done

# print the numbers, separated by ", "
echo "${numbers[0]}"
for i in "${numbers[@]:1}"; do
  echo -n ", $i"
done
echo ""
