#ifndef _SEIL_
#define _SEIL_

typedef struct StringEntryInList SEIL;

struct StringEntryInList {	//String Entry In List
	char* Str;	// String
	int Rpt;	// String Repeat Flag
	SEIL* Ptr;	// FIFO pointer
};

#endif
