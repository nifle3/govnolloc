#include "govnolloc.h"

#include <unistd.h>

extern void *govnolloc(size_t size) {
  struct block *new_block = NULL;
  void *result = NULL;
  int size_with_header;

  size_with_header = size + sizeof(struct block);
  new_block = (struct block *)sbrk(size_with_header);

  if ((void *)new_block != (void *)-1) {
    new_block->size = size;
    new_block->is_free = false;

    if (last_block != NULL) {
      new_block->prev = last_block;
    }
    last_block = new_block;

    result = (void *)(last_block + 1);
  }

  return result;
}

extern void poop(void *ptr);
