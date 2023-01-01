#!/bin/bash
# Format newly added files using clang-format
# Note: must run before git add

for i in $(git diff README.md | grep '+' | cut -d'|' -f2 -s)
do
  echo "Formating: $i"
  clang-format -i ./Problems/$i.cpp
done
