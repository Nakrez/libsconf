#include <assert.h>
#include <libsconf/libsconf.h>

int main()
{
    libsconf_t *conf = lsc_new();

    conf->path = strdup("test.cfg");

    if (libsconf_import(conf))
        assert(0);

    assert(!strcmp(lsc_get_string(conf, "test_var"), "data"));
    assert(lsc_get_string(conf, "test_non_exist") == NULL);

    assert(lsc_var_exists(conf, "test_map.map") != DATA_NONE);
    assert(lsc_var_exists(conf, "test_map.non_exist") == DATA_NONE);

    lsc_free(conf);

    return 0;
}
