#!/bin/bash
# Format newly added files using clang-format

for i in $(git status | grep -v "deleted" | grep -Eo "(Problems|Templates).*\.cpp")
do
  echo "Formating: $i"
  clang-format -i $i
done
