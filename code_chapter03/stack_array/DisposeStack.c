#include <Stack.h>

void
DisposeStack(Stack S)
{
    if(NULL != S)
    {
        free(S->Array);
        free(S);
    }
}
