/**
** @file libsconf.h
** @brief Main header of libsconf
** @date 04/28/2013
** @author Baptiste COVOLATO <b.covolato@gmail.com>
**
** @license
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

#ifndef LIBSCONF_H
# define LIBSCONF_H

typedef struct
{
    char *path;
} libsconf_t;

libsconf_t *libsconf_new();

int libsconf_open(libsconf_t *conf);
int libsconf_save(libsconf_t *conf);

void libsconf_free(libsconf_t *conf);

#endif /* !LIBSCONF_H */
