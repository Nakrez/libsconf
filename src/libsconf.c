/*
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

#include <libsconf/libsconf.h>

libsconf_t *libsconf_new()
{
    libsconf_t *conf = NULL;

    if ((conf = malloc(sizeof (libsconf_t))) == NULL)
        return NULL;

    conf->path = NULL;
    conf->intern_stack.size = 0;

    if ((conf->intern_root = lsc_hash_map_new()) == NULL)
    {
        free(conf);
        return NULL;
    }

    return conf;
}

void libsconf_free(libsconf_t *conf)
{
    if (conf)
    {
        free(conf->path);
        lsc_hash_map_free(conf->intern_root);
        free(conf);
    }
}

int libsconf_import(libsconf_t *conf)
{
    int ret_val = 0;

    if (conf->path == NULL)
        return -1;

    if ((conf->intern_file = fopen(conf->path, "r")) == NULL)
        return -2;

    ret_val = libsconf_parse(conf);

    fclose(conf->intern_file);

    return ret_val;
}

libsconf_data_type_e lsc_var_exists(libsconf_t *conf, char *key)
{
    int len = strlen(key);
    char *dup_key = alloca(len);
    return DATA_NONE;
}

char *libsconf_get_string(libsconf_t *conf, char *key)
{
    libsconf_data_s *ret_data = lsc_hash_map_get(conf->intern_root, key);

    if (ret_data->type == DATA_VALUE)
        return ret_data->data;

    return NULL;
}
