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

#include <libsconf/parse.h>

static int internal_of_hash_map(libsconf_t *conf);

static libsconf_data_s *data(libsconf_t *conf)
{
    libsconf_data_s *ret_val;
    int ret;

    if ((ret_val = malloc(sizeof (libsconf_data_s))) == NULL)
        return NULL;

    ret = libsconf_lex(conf, TOK_DATA);

    if (ret)
        goto error;
    else if (conf->intern_tok.type == TOK_DATA &&
             conf->intern_tok.content != NULL)
    {
        ret_val->type = DATA_VALUE;
        ret_val->data = conf->intern_tok.content;
    }
    else if (conf->intern_tok.type == TOK_BEGIN_MAP)
    {
        ret_val->type = DATA_HASH;

        /* Create new hash map */
        libsconf_stack_push(&conf->intern_stack, lsc_hash_map_new());

        /* Parsing new hash map */
        if (internal_of_hash_map(conf) == 1)
            goto error;

        if (ret || conf->intern_tok.type != TOK_END_MAP)
            goto error;

        ret_val->data = libsconf_stack_pop(&conf->intern_stack);
    }
    else /* TODO handle list*/
        goto error;

    return ret_val;

error:
    free(ret_val);
    return NULL;
}

static int variable(libsconf_t *conf)
{
    /* When variable is called checked on TOK_ID already made */
    int ret;
    char *var_name = conf->intern_tok.content;
    libsconf_data_s *new_data = NULL;
    libsconf_hash_map_s *hm = NULL;

    if (var_name == NULL)
        goto error;

    ret = libsconf_lex(conf, TOK_ID);

    /* Checking if we have assignation */
    if (ret || conf->intern_tok.type != TOK_ASSIGN)
        goto error;

    if (!(new_data = data(conf)))
        goto error;

    /* Insert extracted data in the current map */
    hm = libsconf_stack_top(&conf->intern_stack);
    lsc_hash_map_insert(hm, var_name, new_data);

    return 0;

error:
    /* TODO clean up */
    return -1;
}

static int internal_of_hash_map(libsconf_t *conf)
{
    int ret;

    ret = libsconf_lex(conf, TOK_ID);

    while (!ret && conf->intern_tok.type == TOK_ID)
    {
        if (variable(conf))
            goto error;

        ret = libsconf_lex(conf, TOK_ID);
    }

    if (ret)
        return 1;
    else
        return 0;

error:
    return -1;
}

int libsconf_parse(libsconf_t *conf)
{
    libsconf_stack_push(&conf->intern_stack, conf->intern_root);

    if (internal_of_hash_map(conf) == 1)
        return 0;
    else
        return -1;
}
