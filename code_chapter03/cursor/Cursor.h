#ifndef _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType x, List L);
Position FindPrevious(ElementType x, List L);
void Insert(ElementType x, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif /* _Cursor_H */

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];
