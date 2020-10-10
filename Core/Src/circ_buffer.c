#include "circ_buffer.h"


cbuff_handle cbuff_init(uint16_t* buffer, size_t size)
{
    cbuff_handle cbuff = malloc(sizeof(cbuff_handle));
    cbuff->buffer = buffer;
	cbuff->max = size;

    cbuff_reset(cbuff);

    return cbuff;
}

bool cbuff_full(cbuff_handle circ_buff)
{
    return circ_buff->full;
}

bool cbuff_empty(cbuff_handle circ_buff)
{
    return (!circ_buff->full && (circ_buff->head == circ_buff->tail));
}

static void advance_pointer(cbuff_handle circ_buff)
{
	if(circ_buff->full)
   	{
		circ_buff->tail = (circ_buff->tail + 1) % circ_buff->max;
	}

	circ_buff->head = (circ_buff->head + 1) % circ_buff->max;
	circ_buff->full = (circ_buff->head == circ_buff->tail);
}

static void retreat_pointer(cbuff_handle circ_buff)
{
	circ_buff->full = false;
	circ_buff->tail = (circ_buff->tail + 1) % circ_buff->max;
}

void cbuff_put(cbuff_handle circ_buff, uint16_t data)
{
    circ_buff->buffer[circ_buff->head] = data;

    advance_pointer(circ_buff);
}

int cbuff_get(cbuff_handle circ_buff, uint16_t* data)
{
    int ret = -1;

    if(!cbuff_empty(circ_buff))
    {
        *data = circ_buff->buffer[circ_buff->tail];
        retreat_pointer(circ_buff);

        ret = 0;
    }

    return ret;
}

size_t cbuff_size(cbuff_handle circ_buff)
{
	size_t size = circ_buff->max;

	if(!circ_buff->full)
	{
		if(circ_buff->head >= circ_buff->tail)
		{
			size = (circ_buff->head - circ_buff->tail);
		}
		else
		{
			size = (circ_buff->max + circ_buff->head - circ_buff->tail);
		}
	}

	return size;
}

size_t cbuff_capacity(cbuff_handle circ_buff)
{
    return circ_buff->max;
}


void cbuff_reset(cbuff_handle circ_buff)
{
    circ_buff->head = 0;
	circ_buff->tail = 0;
    circ_buff->full = false;
}

void cbuff_free(cbuff_handle circ_buff)
{
    free(circ_buff);
}