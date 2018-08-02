#include <Cursor.h>

/* Return Position of X in L; 0 if not found */
/* Uses a header node */

Position
Find(ElementType X, List L)
{
    Position P;
    
    P = CursorSpace[L].Next;
    while(P && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;
        
    return P;
}
