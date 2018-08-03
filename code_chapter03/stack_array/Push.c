#include <Stack.h>

void 
Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Full stack");
    else
        S->Array[++S->TopOfStack] = X;
}
