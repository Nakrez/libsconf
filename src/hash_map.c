/**
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

# include <libsconf/hash_map.h>

static unsigned int hash_string(const char* s)
{
    unsigned h = 0;
    unsigned g;

    while (*s != 0)
    {
        h = (h << 4) + *s++;
        if ((g = h & 0xf0000000) != 0)
            h = (h ^ (g >> 24)) ^ g;
    }
    return h;
}

static void insert_in_table(libsconf_hash_map_s *hm,
                            libsconf_hash_data_s *data)
{
    unsigned hash = hash_string(data->key) % hm->total_size;

    data->next = hm->map[hash];
    hm->map[hash] = data;
}

static int hash_map_resize(libsconf_hash_map_s *hm)
{
    libsconf_hash_data_s **table = NULL;
    libsconf_hash_data_s *llist = NULL;
    libsconf_hash_data_s *temp = NULL;
    unsigned old_size = hm->total_size;

    table = hm->map;

    if ((hm->map = calloc(hm->total_size * 2,
                          sizeof (libsconf_hash_data_s *))) == NULL)
    {
        hm->map = table;
        return -1;
    }

    hm->total_size *= 2;

    for (unsigned i = 0; i < old_size; ++i)
    {
        llist = table[i];

        while (llist)
        {
            temp = llist->next;

            insert_in_table(hm, llist);

            llist = temp;
        }
    }

    free(table);

    return 0;
}

libsconf_hash_map_s *lsc_hash_map_new()
{
    libsconf_hash_map_s *hm = NULL;

    if ((hm = malloc(sizeof (libsconf_hash_map_s))) == NULL)
        return NULL;

    /* Default size */
    hm->size = 0;
    hm->total_size = 10;

    if ((hm->map = calloc(hm->total_size,
                          sizeof (libsconf_hash_data_s *))) == NULL)
    {
        free(hm);
        return NULL;
    }

    return hm;
}

libsconf_data_s *lsc_hash_map_get(libsconf_hash_map_s *hm, const char *key)
{
    libsconf_hash_data_s *llist = hm->map[hash_string(key) % hm->total_size];

    while (llist)
    {
        if (!strcmp(key, llist->key))
            return llist->data;

        llist = llist->next;
    }

    return NULL;
}

int lsc_hash_map_insert(libsconf_hash_map_s *hm, char *key,
                        libsconf_data_s *data)
{
    /* FIXME : rezise before map full */
    if (hm->size == hm->total_size - 1)
         if (hash_map_resize(hm) < 0)
             return -1;

    unsigned place = hash_string(key) % hm->total_size;

    libsconf_hash_data_s *llist = NULL;

    llist = hm->map[place];

    while (llist)
    {
        if (!strcmp(key, llist->key))
        {
            llist->data = data;
            return 0;
        }

        llist = llist->next;
    }

    if ((llist = calloc(1, sizeof (libsconf_hash_data_s))) == NULL)
        return -1;

    llist->key = key;
    llist->data = data;
    llist->next = hm->map[place];

    hm->map[place] = llist;

    ++(hm->size);

    return 0;
}

void lsc_hash_map_free(libsconf_hash_map_s *hm)
{
    libsconf_hash_data_s *llist = NULL;
    libsconf_hash_data_s *temp = NULL;

    if (hm)
    {
        for (unsigned i = 0; i < hm->total_size; ++i)
        {
            llist = hm->map[i];

            while (llist)
            {
                /* FIXME : free data */
                temp = llist->next;

                libsconf_data_free(llist->data);
                free(llist);

                llist = temp;
            }
        }

        free(hm->map);
        free(hm);
    }
}
