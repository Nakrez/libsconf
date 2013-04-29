#include <libsconf/list.h>

libsconf_list_t *libsconf_list_new()
{
    libsconf_list_t *ret_val = NULL;

    if ((ret_val = malloc(sizeof (libsconf_list_t))) == NULL)
        return NULL;

    ret_val->size = 0;
    ret_val->begin = NULL;
    ret_val->end = NULL;

    return ret_val;
}

static void list_destroy(libsconf_list_t *list)
{
    struct libsconf_data_list *temp = NULL;

    while (list->begin)
    {
        temp = list->begin->next;

        if (list->begin->data)
        {
            free(list->begin->data->data);
            free(list->begin->data);
        }

        free(list->begin);

        list->begin = temp;
    }
}

void libsconf_list_free(libsconf_list_t *list)
{
    if (list)
    {
        list_destroy(list);
        free(list);
    }
}
