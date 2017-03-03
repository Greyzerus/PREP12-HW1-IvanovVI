#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "SEIL.h"
#include "RepeatStr.h"



/* Вывести все повторяющиеся строки. Вариант через список.
Можно использовать массив структур... Хотя realloc медленный.
Копия структуры из header-a
typedef struct StringEntryInList SEIL;
struct StringEntryInList {	//String Entry In List
	char* Str;	// String
	int StrLen;
	_Bool Rpt;	// String Repeat Flag
	SEIL* Ptr;	// Next list entry pointer
};*/

int main (int argc, char* argv[])
{
    FILE* f=fopen ("input.txt", "r");
    if (f == NULL)
    {
        printf ("File input.txt is empty, or doesn't exist\n");
        exit (-1);
    }
	SEIL *cur, *_cur, *first; // Current element, (temp)cur for cycles, first
	first = FSetE (f);
	cur=first;
	while ( * (PreLastPtr (cur)) != EOF) // Set element from file
    {
	    	cur -> Ptr = FSetE (f);
	    	cur = cur -> Ptr;
    }
    * (PreLastPtr(cur)) = '\0';
	cur = first;
	while (cur -> Ptr != NULL)
	{
		if (cur -> Rpt != 0)
		{
            cur = cur -> Ptr;
            continue;
		}
		_cur = cur -> Ptr;
		while (_cur -> Ptr != NULL)
		{
            if (strcmp (cur -> Str, _cur -> Str) == 0)
            {
                cur -> Rpt = 1;
                _cur -> Rpt = 1;
            }
            _cur = _cur -> Ptr;
		}
		if (cur -> Rpt)
            puts (cur -> Str);
        cur = cur -> Ptr;
    }
    return 0;
}
