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

#ifndef CHUNKS_H
#define CHUNKS_H

#include "dictionary_structs.h"


/*
  Function to initialize chunks for the dictionary. This performs any
  necessary setup (like perhaps reading a block with information on
  it).

  Return value is 0 on success.
 */

int initialize_chunks();


/*
  Function to fetch the chunk of memory for the given id, and store it
  in buffer. Buffer must have a size of at least 128 bytes.

  Return value is 0 on success.
 */

int fetch_chunk(uint32 id, void *buffer);


/*
  This function is the same as fetch_chunk, but it always fetches the
  root chunk.

  Return value is 0 on success.
 */

int fetch_root(void *buffer);


/*
  This function returns the id of the root.
 */

uint32_t fetch_root_id();


/*
  Function to create a new chunk in the index. Buffer is a pointer to
  whatever memory you wish to store in this new chunk. If buffer is
  NULL nothing is written to the chunk by this function.

  Returns the id of the new chunk.
 */

uint32_t create_chunk(void *buffer);

#endif
