#include <assert.h>
#include <libsconf/libsconf.h>

int main()
{
    libsconf_t *conf = libsconf_new();

    conf->path = strdup("test.cfg");

    if (libsconf_import(conf))
        assert(0);

    assert(!strcmp(libsconf_get_data(conf, "test_var"), "data"));

    libsconf_free(conf);

    return 0;
}
