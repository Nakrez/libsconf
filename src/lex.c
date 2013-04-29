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

#include <libsconf/lex.h>

static int is_separator(char c)
{
    return c == ' ' || c == '\n' || c == '\t';
}

static int is_token_char(char c, libsconf_t *conf)
{
    switch (c)
    {
        case '=':
            conf->intern_tok.type = TOK_ASSIGN;
            return 1;
        case '{':
            conf->intern_tok.type = TOK_BEGIN_MAP;
            return 1;
        case '}':
            conf->intern_tok.type = TOK_END_MAP;
            return 1;
        case '[':
            conf->intern_tok.type = TOK_BEGIN_LIST;
            return 1;
        case ']':
            conf->intern_tok.type = TOK_END_LIST;
            return 1;
        case ',':
            conf->intern_tok.type = TOK_SEP_LIST;
            return 1;
        default:
            return 0;
    }
}

int libsconf_lex(libsconf_t *conf, libsconf_token_type_e default_tok)
{
    char buf[512];
    char read = 0;

    int pos = 0;

    conf->intern_tok.type = default_tok;

    while ((fread(&read, 1, 1, conf->intern_file)) > 0)
    {
        if (is_separator(read))
        {
            /* No token found yet */
            if (!pos)
                continue;
            else /* token finish */
                break;
        }
        else if (is_token_char(read, conf))
            break;

        buf[pos++] = read;
    }

    /* Store the content of the token if needed */
    if (conf->intern_tok.type == TOK_DATA || conf->intern_tok.type == TOK_ID)
    {
        if ((conf->intern_tok.content = calloc(1, pos + 1)) == NULL)
            return -1;

        strncpy(conf->intern_tok.content, buf, pos);
    }

    return !!feof(conf->intern_file);
}
