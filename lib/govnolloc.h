#pragma once

#include <stdbool.h>
#include <stddef.h>

struct block {
  bool is_free;
  size_t size;
  struct block *prev;
};

struct block *last_block = NULL;

extern void *govnolloc(size_t size);

extern void poop(void *ptr);
