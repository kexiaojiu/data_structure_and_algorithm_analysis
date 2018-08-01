#include <List.h>

/* Insert(after legal position P) */
/* Header implemention assumed */
/* Parameter L is unused in this implementation */
void 
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of space!!!")
    
    TmpCell->Element = X;
    TpmCell->Next = P->Next;
    P->Next = TmpCell 
}
