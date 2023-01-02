#!/bin/bash
# Format newly added files using clang-format

for i in $(git status | grep Problems | xargs)
do
  echo "Formating: $i"
  clang-format -i $i
done
