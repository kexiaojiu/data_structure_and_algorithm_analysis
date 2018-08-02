#include <Cursor.h>

/* Return true if L is empty */
int
IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}
