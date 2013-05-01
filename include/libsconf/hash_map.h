/**
** @file hash_map.h
** @brief Internal hash map of libsconf
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

#ifndef HASH_MAP_H
# define HASH_MAP_H

# include <stdlib.h>
# include <string.h>

# include <libsconf/data_hash.h>

libsconf_hash_map_s *lsc_hash_map_new();

libsconf_data_s *lsc_hash_map_get(libsconf_hash_map_s *hm, const char *key);

int lsc_hash_map_insert(libsconf_hash_map_s *hm, char *key,
                        libsconf_data_s *data);

void lsc_hash_map_free(libsconf_hash_map_s *hm);

#endif /* !HASH_MAP_H */
