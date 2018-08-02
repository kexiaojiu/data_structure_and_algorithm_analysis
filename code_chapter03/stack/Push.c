#include <Stack.h>

void 
Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    if(NULL == TmpCell)
        FatalError("Out of space!!!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}
