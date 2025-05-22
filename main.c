#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_file_content(char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    // TODO: Handle error
    return "ERROR";
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  char buffer[size + 1];
  char *content = malloc(size + 1);

  while (fgets(buffer, size + 1, file) != NULL) {
    strcat(content, buffer);
  }

  fclose(file);

  return content;
}

int main() {
  char *content = get_file_content("site/test.txt");

  printf("%s", content);

  return 0;
}
