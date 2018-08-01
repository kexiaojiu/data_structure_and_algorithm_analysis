#include <List.h>

/* Make list empty */
List 
MakeEmpty(List L)
{
    L->next = NULL;
    return L;
}
