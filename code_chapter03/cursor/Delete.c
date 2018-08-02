#include <Cursor.h>

/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void
Delete(ElementType X, List L)
{
    Position P. TmpCell;
    
    P = FindPrevious(X, L);
    
    if(!IsLast(P, L))
    {
        TmpCell = CursorSpace[P].Next；
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);    
    }    
}
