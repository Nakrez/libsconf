#include <stdio.h>
#include <assert.h>
#include <libsconf/hash_map.h>

void itoa(int num, char *buf)
{
    sprintf(buf, "a%d", num);
}

static libsconf_data_s *create_data(char *data)
{
    libsconf_data_s *data_ = NULL;

    data_ = malloc(sizeof (libsconf_data_s));

    data_->type = DATA_VALUE;
    data_->data = data;

    return data_;
}

int main()
{
    libsconf_hash_map_s *hm = lsc_hash_map_new();

    for (unsigned int i = 0; i < 50; ++i)
    {
        char *str = malloc(32);
        itoa(i, str);
        assert(!lsc_hash_map_insert(hm, str, create_data(str)));
    }

    for (unsigned int i = 0; i < 50; ++i)
    {
        char str[32];
        itoa(i, str);

        libsconf_data_s *ret = lsc_hash_map_get(hm, str);

        assert(ret);
        assert(!strcmp(str, ret->data));
    }

    lsc_hash_map_free(hm);

    return 0;
}
