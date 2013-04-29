#include <libsconf/libsconf.h>

int main()
{
    libsconf_t *conf = libsconf_new();

    conf->path = strdup("./test/test.cfg");

    if (libsconf_import(conf))
        return 1;

    libsconf_free(conf);

    return 0;
}
