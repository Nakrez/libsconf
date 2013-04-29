/**
** @file data_type.h
** @brief All data type used in libsconf
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

#ifndef LIBSCONF_DATA_TYPE_H
# define LIBSCONF_DATA_TYPE_H

# include <stdio.h>

/* Internal data of libsconf */
# include <libsconf/data.h>

/* Internal data list of libsconf */
# include <libsconf/data_list.h>

/* Internal token of libsconf */
# include <libsconf/data_token.h>

/**
** @brief   The configuration state is the structure that contains your
            configuration. Thanks to it you will be allowed to import/save
            a configuration from/in a file and manage it
            Be carefull all intern_* of libsconf_t are internal variables of
            configuration you must not modify it by hand
*/
typedef struct
{
    /**
    ** @brief The path of the file where libsconf read/write your configuration
    */
    char *path;

    FILE *intern_file;

    libsconf_token_t intern_tok;
} libsconf_t;

#endif /* !LIBSCONF_DATA_TYPE_H */
