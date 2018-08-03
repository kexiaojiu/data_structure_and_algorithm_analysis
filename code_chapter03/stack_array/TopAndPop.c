#include <Stack.h>

ElementType
TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Empty stack");
    return 0;
}
