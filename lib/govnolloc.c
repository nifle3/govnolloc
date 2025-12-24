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

static void erase_trail(void) {
  int mem_to_erase = 0;
  struct block *cur_block;

  cur_block = last_block;

  while (cur_block != NULL && cur_block->is_free) {
    mem_to_erase -= cur_block->size + sizeof(struct block);
    cur_block = cur_block->prev;
  }

  last_block = cur_block;
  if (mem_to_erase < 0) {
    sbrk(mem_to_erase);
  }
}

extern void poop(void *ptr) {
  struct block *cur_block = NULL;

  if (ptr == NULL) {
    return;
  }

  cur_block = (struct block *)ptr - 1;
  cur_block->is_free = true;
  erase_trail();
}
