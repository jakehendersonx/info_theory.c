
#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>
#include <stdint.h>
// struct for representing file, likely image file
typedef struct {
  uint8_t *data;
  size_t size;
} FileBuffer;
// defs for read write and free of file buffer
FileBuffer *read_file(const char *filename);
void free_file_buffer(FileBuffer *buffer);
int write_file(const char *filename, const uint8_t *data, size_t size);

#endif
