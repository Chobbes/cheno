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

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdint.h>


/*
  Look up the id of a stroke, 0 if there is no stroke.

  start_id is the id of the chunk to start the search (last stroke's
  id), and stroke is the binary representation of the stroke to look
  up.

  Return value is the id of the stroke.
 */

uint32_t lookup_stroke(uint32_t start_id, uint32_t stroke);


/*
  Get the string for the given dictionary entry's id. The string is
  stored in buffer, and buffer_size represents the amount of bytes
  that can be stored in the buffer safely.

  Returns the number of bytes written into the buffer. The id must be
  to a DictEntry chunk.
 */

size_t extract_string(uint32_t id, char *buffer, size_t buffer_size);

#endif
