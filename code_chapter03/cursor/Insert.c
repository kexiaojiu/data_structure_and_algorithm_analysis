#include <Cursor.h>

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    
    TmpCell = CursorAlloc();
    if(TmpCell == 0)
        FatalError("Out of space!!!")
    
    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}
