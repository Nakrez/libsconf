/**
** @file libsconf.h
** @brief Main header of libsconf
** @date 04/28/2013
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

#ifndef LIBSCONF_H
# define LIBSCONF_H

# include <stdlib.h>

/**
** @brief   The configuration state is the structure that contains your
            configuration. Thanks to it you will be allowed to import/save
            a configuration from/in a file and manage it
*/
typedef struct
{
    /**
    ** @brief The path of the file where libsconf read/write your configuration
    */
    char *path;
} libsconf_t;

/**
** @brief   Create a new configuration state
**
** @return  The allocated configuration state, NULL if it failed
*/
libsconf_t *libsconf_new();

int libsconf_open(libsconf_t *conf);
int libsconf_save(libsconf_t *conf);

/**
** @brief   Delete a configuration state previously allocated with @a
            libsconf_new()
**
** @param   conf    The configuration state you want to free
*/
void libsconf_free(libsconf_t *conf);

#endif /* !LIBSCONF_H */
