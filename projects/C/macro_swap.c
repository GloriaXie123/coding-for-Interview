#include <stdio.h>

/*define a macro to interchange two argument of type t*/

#define swap(t, x, y) \
	{                   \
		t _z;             \
		_z = y;           \
		x = y;            \
		y = _z;           \
	}
