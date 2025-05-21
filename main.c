#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("test.txt", "r");

  if (file == NULL) {
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  char buffer[size + 1];
  char content[size + 1];

  while (fgets(buffer, size + 1, file) != NULL) {
    strcat(content, buffer);
  }

  printf("%s\n", content);

  fclose(file);
  return 0;
}
