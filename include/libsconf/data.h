/**
** @file data.h
** @brief Internal data of libsconf
** @date 04/29/2013
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

#ifndef LIBSCONF_DATA_H
# define LIBSCONF_DATA_H

typedef enum
{
    DATA_NONE,
    DATA_VALUE,
    DATA_LIST,
    DATA_HASH
} libsconf_data_type_e;

typedef struct
{
    libsconf_data_type_e type;
    void *data;
} libsconf_data_s;

void libsconf_data_free(libsconf_data_s *data);

#endif /* !DATA_H */
