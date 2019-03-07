#!/bin/bash

read_file() {
  local filename=$1
  while IFS= read -r var
  do
    echo "$var"
  done < "$filename"
}


