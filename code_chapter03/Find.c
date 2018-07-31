#include <List.h>

/* Return Position of X in L; NULL if not found */
Position 
Find(ElementType X, List L)
{
    Position P;
    
    P = L->Next;
    while(P != NULL && P->Element != X)
        P = P->Next;
    return P;
}
