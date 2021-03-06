/* Copyright © 2018-2019 MAKER.                                               */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <skift/types.h>
#include <skift/atomic.h>

static bool atomic_enabled = 0;
static uint atomic_depth = 0;

void sk_atomic_enable()
{
    atomic_enabled = true;
}

void sk_atomic_disable()
{
    atomic_enabled = false;
}

void sk_atomic_begin()
{
    if (atomic_enabled)
    {
        asm volatile("cli");
        atomic_depth++;
        
    }
}

void sk_atomic_end()
{
    if (atomic_enabled)
    {
        atomic_depth--;

        if (atomic_depth == 0)
        {
            asm volatile("sti");
        }
    }
}