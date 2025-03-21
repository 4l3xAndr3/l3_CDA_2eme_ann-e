#!/bin/bash
OUTPUT_FILE="results.csv"
echo "Method,Threads,Allow_Migration,Execution_Time" > $OUTPUT_FILE

for method in 1 2 3; do
    for threads in 1 2 4 8 16 32 64 128 256 512 1024; do
        for migration in 0 1; do
            echo "Running method=$method threads=$threads migration=$migration"
            EXEC_TIME=$(./min_calculator $method $threads $migration | awk '{print $4}')
            echo "$method,$threads,$migration,$EXEC_TIME" >> $OUTPUT_FILE
        done
    done
done