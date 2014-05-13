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

/* This struct must be 128 bytes! */
typedef struct DictEntry {
    uint32_t stroke;
    uint32_t flags;

    /* Parent index */
    uint32_t parent;

    /* Children -- same stroke number */
    uint32_t left;
    uint32_t right;

    /* For next stroke */
    uint32_t root;

    /* String information -- length is 0 if there is no entry here. */
    uint32_t length;
    char entry[96]; /* Stored strings are not NULL terminated. */

    uint32_t next;  /* id for next chunk of the string if necessary. */
} DictEntry;


/* May need several string entries to fit entry. Linked list. Also 128 bytes. */
typedef struct StringEntry {
    char entry[124];
    uint32_t next;  /* id for next chunk of the string if necessary. */
} StringEntry;

#endif
