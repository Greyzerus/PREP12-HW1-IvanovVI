#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SEIL.h"

#define BUF_BLOCK 10


char* PreLastPtr (SEIL* cur)
{
    return (cur -> Str + (strlen (cur -> Str) - 1) * sizeof (char) );
}

char* FScanStr (FILE* f)
{
    int  i = 0, N;
    N=BUF_BLOCK;
    char* buf = (char*) malloc (BUF_BLOCK * sizeof(char));
    while ((buf [i] = fgetc(f)) != '\n' )
    {
        if (++i == N)
        {
            N += BUF_BLOCK;
            buf = (char*) realloc (buf, sizeof(char)*N);
        }
        if (buf[i-1] == EOF)
        {
            break;
        }
    }
    buf[i] = '\0';
    return (buf);
}

SEIL* FSetE (FILE* f)
{
    SEIL* _SEIL = (SEIL*) malloc(sizeof (SEIL));
    _SEIL -> Rpt = 0;
    _SEIL -> Ptr = NULL;
    _SEIL -> Str = FScanStr (f);
    //_SEIL -> StrLen = strlen (_SEIL -> Str); // Ofcourse I could return this int in FScanStr, but this way is more readable
    return (_SEIL);
}
