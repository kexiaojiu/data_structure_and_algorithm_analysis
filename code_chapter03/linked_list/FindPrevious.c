#include <List.h>

/* If X is not found, then Next field of returned position is NULL */
/* Assumes a header */

Position 
FindPrivious(ElementType X, List L)
{
    Position P;
    
    P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}
