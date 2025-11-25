#!/bin/bash

# gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o a.out

# if [ $? -ne 0 ]; then 
#     echo "Compilation failed, Please check your c files."
#     exit 1
# fi

# TEST_DIR="./test_files"

# if [ ! -d "$TEST_DIR" ]; then
#     echo "Test directory $TEST_DIR does not exist"
#     exit 1
# fi

# BUFFER_SIZES=(1 10 2480 100000000 )

# for BUFFER_SIZE in "${BUFFER_SIZES[@]}"; do
#     echo "=============================================="
#     echo "=== Testing with BUFFER_SIZE = $BUFFER_SIZE ==="
#     echo "=============================================="
#     export BUFFER_SIZE

#     for FILE in "$TEST_DIR"/*; do 
#         if [ -f "$FILE" ]; then
#             echo "=== Test: $FILE ==="
#             ./a.out < "$FILE"
#             echo ""
#         else
#             echo "No files found in $TEST_DIR"
#         fi
#     done
# done

# rm a.out 

# echo "Testing completed"









gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o a.out

if [ $? -ne 0 ]; then 
    echo "Compilation failed, Please check your C files."
    exit 1
fi

TEST_DIR="./test_files"

if [ ! -d "$TEST_DIR" ]; then
    echo "Test directory $TEST_DIR does not exist."
    exit 1
fi

BUFFER_SIZES=(1 10 2480 100000000)

for BUFFER_SIZE in "${BUFFER_SIZES[@]}"; do
    echo "=============================================="
    echo "=== Testing with BUFFER_SIZE = $BUFFER_SIZE ==="
    echo "=============================================="
    export BUFFER_SIZE

    for FILE in "$TEST_DIR"/*; do 
        if [ -f "$FILE" ]; then
            echo ""
            echo "--- Test: $FILE ---"
            echo "[Normal Execution]"
            ./a.out < "$FILE"

            echo ""
            echo "[Valgrind Test]"
            valgrind --leak-check=full --show-leak-kinds=all \
                     --errors-for-leak-kinds=all \
                     --track-origins=yes \
                     --quiet \
                     ./a.out < "$FILE"

            VAL=$?
            if [ $VAL -eq 0 ]; then
                echo "✔ No leaks detected"
            else
                echo "❌ Memory leak detected"
            fi
            echo ""
        fi
    done
done