

#include "utils.h"
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

FileBuffer *read_file(const char *filename) {
  // create buff
  FileBuffer *file_buff = malloc(sizeof(FileBuffer));
  if (!file_buff) {
    perror("failed to allocate file buffer");
    return NULL;
  }

  // access file
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("failed to open file %s");
    free(file_buff);
    return NULL;
  }

  // determine file size
  fseek(file, 0, SEEK_END);
  // set that to file buffer's size
  file_buff->size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // set file buffer's data
  file_buff->data = malloc(file_buff->size);
  if (!file_buff->data) {
    perror("memory allocation error for file data");
    fclose(file);
    free(file_buff);
    return NULL;
  }

  // read and validate file
  size_t bytes_read = fread(file_buff->data, 1, file_buff->size, file);
  fclose(file);
  if (bytes_read != file_buff->size) {
    perror("error on file read");
    free(file_buff->data);
    free(file_buff);
    return NULL;
  }
  return file_buff;
}
