#include <Stack.h>

void
Pop(Stack S)
{
    PtrToNode FirstCell;
    
    if(IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}
