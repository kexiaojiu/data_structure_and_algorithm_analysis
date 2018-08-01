#include <List.h>

/* Delete List */

void
DeleteList(List L)
{
    Position P, Tmp;
    
    P = L->Next; /* Header assumed */
    L->Next = NULL;
    while(P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;    
    }
}
