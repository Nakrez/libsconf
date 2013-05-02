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

# include <stdio.h>
# include <stdlib.h>

# include <libsconf/data_type.h>
# include <libsconf/hash_map.h>
# include <libsconf/parse.h>

/**
** @brief   Create a new configuration state
**
** @return  The allocated configuration state, NULL if it failed
*/
libsconf_t *libsconf_new();

/**
** @brief   Load a configuration from a file (in @a conf->path)
**
** @param   conf    The libsconf state where to load the file
**
** @return  0 if everything went well, -1 if @a conf->path is NULL, -2 if
**          opening the file failed
*/
int libsconf_import(libsconf_t *conf);

int libsconf_export(libsconf_t *conf);

/**
** @brief   Delete a configuration state previously allocated with @a
**          libsconf_new()
**
** @param   conf    The configuration state you want to free
*/
void libsconf_free(libsconf_t *conf);

libsconf_data_type_e lsc_var_exists(libsconf_t *conf, char *key);

char *libsconf_get_string(libsconf_t *conf, char *key);

#endif /* !LIBSCONF_H */
