# 42_Get_next_line
This project implements a function called `get_next_line()`, which returns a line from a file, followed by a newline character. The `get_next_line()` function should work with any buffer size.

## How to use

To use the `get_next_line()` function, follow these steps:

1. Include the `get_next_line.h` file in your code.
2. Define the buffer size that you want to use.
3. Call the `get_next_line()` function with the file descriptor and a pointer to a buffer.

The `get_next_line()` function will return a pointer to the line that was read, or `NULL` if there are no more lines to read.

## Example

```c
#include <stdio.h>
#include "get_next_line.h"

int main() {
  char *line = NULL;
  int fd = open("test.txt", O_RDONLY);

  // Reads the first line of the file
  line = get_next_line(fd);
  if (line == NULL) {
    printf("Error reading the file.\n");
    return 1;
  }

  // Prints the line
  printf("Line 1: %s\n", line);

  // Reads the second line of the file
  line = get_next_line(fd);
  if (line == NULL) {
    printf("Error reading the file.\n");
    return 1;
  }

  // Prints the line
  printf("Line 2: %s\n", line);

  // Closes the file
  close(fd);

  return 0;
}

