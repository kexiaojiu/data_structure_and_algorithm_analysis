#include <Stack.h>

Stack
CreateStack(void)
{
    Stack S;
    
    S = malloc(sizeof(struct Node));
    if(NULL == S)
        FatalError("Out of space!!!");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void
MakeEmpty(Stack S)
{
    if(NULL == S)
        Error("Must use Create first");
    else
        while(!IsEmpty(S))
            Pop(S);
}
