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

#include <libsconf/stack.h>

int libsconf_stack_push(libsconf_stack_s *stack, libsconf_hash_map_s *hm)
{
    if (stack->size < LIBSCONF_MAX_STACK_SIZE - 1)
    {
        stack->stack[stack->size] = hm;
        ++(stack->size);

        return 0;
    }

    return -1;
}

libsconf_hash_map_s *libsconf_stack_pop(libsconf_stack_s *stack)
{
    if (stack->size > 0)
        return stack->stack[--(stack->size)];

    return NULL;
}

libsconf_hash_map_s *libsconf_stack_top(libsconf_stack_s *stack)
{
    return stack->stack[stack->size - 1];
}
