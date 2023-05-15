## Before the beginning

### install libxml2

### on linux

### `sudo apt-get install libxml2-dev`

### on macOS

### `brew install libxml2`

## To build

### `gcc index.c compare_strings.c swap.c my_qsort.c experiment.c -o index -lxml2`

## To run

### `./index`

## If you want to build tests

### `gcc test.c swap.c my_qsort.c -o test`