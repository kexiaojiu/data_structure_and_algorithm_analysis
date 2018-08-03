#include <Stack.h>

void
Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty stack");
    else
        S->TopOfStack--;
}
