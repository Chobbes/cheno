/*
  The MIT License (MIT)

  Copyright (C) 2014 Calvin Beck

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation files
  (the "Software"), to deal in the Software without restriction,
  including without limitation the rights to use, copy, modify, merge,
  publish, distribute, sublicense, and/or sell copies of the Software,
  and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/

#include "dictionary.h"
#include "chunks.h"

#include <stdint.h>


uint32_t lookup_stroke(uint32_t start_id, uint32_t stroke)
{
    if (0 == start_id) {
	start_id = fetch_root_id();
    }

    /* Fetch the starting entry. */
    DictEntry entry;
    if (fetch_chunk(start_id, &entry)) {
	return 0;  /* Failed to get chunk. */
    }

    /* Search starting from the root of the next stroke. */
    uint32_t id = entry.root;
    while (0 != id) {
	if (fetch_chunk(id, &entry)) {
	    return 0;  /* Failed to get chunk. */
	}

	/* Binary search */
	if (entry.stroke == stroke) {
	    return id;  /* Found the stroke! */
	}
	else if (entry.stroke < stroke) {
	    id = entry.left;
	}
	else {
	    id = entry.right;
	}
    }

    return id;
}
