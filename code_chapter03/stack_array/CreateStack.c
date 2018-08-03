#include <Stack.h>

StackCreateStack(int MaxElements)
{
    Stack S;
    
    if(MaxElements < MinStackSize)
        Error("Stack size is too small.");
    
    S = malloc(sizeof(struct StackRecord));
    if(NULL == S)
        FatalError("Out of Space!");
    S->Capacity = MaxElements;
    MakeEmpty(S);
    
    return S;
}
