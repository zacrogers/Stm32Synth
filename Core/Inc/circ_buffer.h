#ifndef _CIRC_BUFFER_H
#define _CIRC_BUFFER_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__cplusplus)
  extern "C" {                 // Make sure we have C-declarations in C++ programs
#endif

struct circular_buffer
{
	uint16_t* buffer;
	size_t    head;
	size_t    tail;
	size_t    max;
	bool      full;
};

typedef struct circular_buffer* cbuff_handle;

cbuff_handle cbuff_init(uint16_t* buffer, size_t size);

bool         cbuff_full(cbuff_handle circ_buff);

bool         cbuff_empty(cbuff_handle circ_buff);

void         cbuff_put(cbuff_handle circ_buff, uint16_t data);

int          cbuff_get(cbuff_handle circ_buff, uint16_t* data);

size_t       cbuff_size(cbuff_handle circ_buff);

size_t       cbuff_capacity(cbuff_handle circ_buff);

void         cbuff_reset(cbuff_handle circ_buff);

void         cbuff_free(cbuff_handle circ_buff);


#if defined(__cplusplus)
  }
#endif

#endif /* _CIRC_BUFFER_H */
