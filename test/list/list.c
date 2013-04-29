#include <libsconf/list.h>

int main()
{
    libsconf_list_t *list = libsconf_list_new();

    libsconf_list_free(list);

    return 0;
}
