/**
** @file data_hash.h
** @brief Internal data type for libsconf hash map
** @date 05/01/2013
** @author Baptiste COVOLATO <b.covolato@gmail.com>
**
** Copyright (C) 2013 Baptiste COVOLATO
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
*/

#ifndef DATA_HASH_H
# define DATA_HASH_H

# include <libsconf/data.h>

typedef struct libsconf_hash_data
{
    char *key;
    libsconf_data_s *data;
    struct libsconf_hash_data *next;
} libsconf_hash_data_s;

typedef struct libsconf_hash_map
{
    libsconf_hash_data_s **map;
    unsigned size;
    unsigned total_size;
} libsconf_hash_map_s;

#endif /* !DATA_HASH_H */
