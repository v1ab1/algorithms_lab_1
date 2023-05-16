## Before the beginning

### install libxml2

### on linux

### `sudo apt-get install libxml2-dev`

### on macOS

### `brew install libxml2`

### on Windows

### `pacman -S mingw-w64-x86_64-libxml2`

## To build

### `gcc index.c compare_strings.c swap.c my_qsort.c experiment.c xmlReader.c -o ../index -lxml2`

## To run

### `./index`

## If you want to build tests

### `gcc test.c swap.c my_qsort.c -o ../test`