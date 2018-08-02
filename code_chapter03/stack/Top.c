#include <Stack.h>

ElementType
Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return 0; /* Return value used to avoid warning */
}
