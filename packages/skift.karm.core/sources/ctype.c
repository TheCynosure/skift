/* Copyright © 2018-2019 MAKER.                                               */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <ctype.h>

int islower(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1;
    }

    return 0;
}

int isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }

    return 0;
}

int isalpha(int c)
{
    if (islower(c) || isupper(c))
    {
        return 1;
    }

    return 0;
}

int isdigit(int c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }

    return 0;
}