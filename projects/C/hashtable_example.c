#include "uthash.h"

struct my_struct
{
	int id; /*key*/
	char name[10];
	UT_hash_handle hh; /*make this structure hashable*/
}
