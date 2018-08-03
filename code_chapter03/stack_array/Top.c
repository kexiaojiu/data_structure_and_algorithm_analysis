#include <Stack.h>

ElementType
Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty stack");
    return 0;
}
