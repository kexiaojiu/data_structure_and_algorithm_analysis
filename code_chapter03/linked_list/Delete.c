#include <List.h>

/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void 
Delete(ElementType X, List L)
{
    Position P, TemCell;
    
    P = FindPrevious(X, L);
    
    if(!(IsLast(P, L))) /* Assumption of header use X if found, delete it */
    {
        TemCell = P->Next;
        P->Next = TemCell->Next; /* Bypass deleted cell */    
    }
}
