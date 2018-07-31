[toc]
---
# 第3章 表、栈和队列
## 3.1 抽象数据类型
抽象数据类型（abstract data type, ADT）是一些操作的集合，诸如并（union）、交（intersection）、测定大小（size）以及取余（complement）.

---
## 3.2 表ADT
我们将处理一般的形如${A_1},{A_2},{A_3},...,{A_N}$的表.该表的大小为$N$.常见的操作集合有PrintList、MakeEmpty、Find（返回关键字首次出现的位置）、Insert（从表的某个位置插入某个关键字）、Delete（从表的某个位置删除某个关键字）、FindKth（返回某个位置上的元素）。
### 3.2.1 表的简单数组实现
虽然数组是动态指定的，但还是需要对表的大小的最大值进行估计，通常需要估计大一些，从而会浪费大量的空间。做插入和删除操作耗时较长。一般简单数组一般不用来实现表这种结构。
### 3.2.2 链表
链表由一系列不必在内存中相连的结构构成，每一个结构均含有表元素和指向包含该元素后继元的结构的指针。我们称之为Next指针。最后一个单元的Next指针指向NULL。
<center>![001](https://i.imgur.com/tOydQ87.jpg)</center>  
### 3.2.3 程序实现的细节
我们通常会留出一个标志结点，称为表头（Header）或者哑结点（dummy node）.
 <center>![002](https://imgur.com/hsQMm43.jpg)</center>
链表ADT的类型声明如下
```
#ifndef _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

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

#endif /* _LIST_H */

struct Node
{
    ElementType Element;
    Position Next;
}
```
* 使得表为空
```
#include <List.h>

/* Make list empty */
List 
MakeEmpty(List L)
{
    L->next = NULL;
    return L;
}
```
* 测试空表函数
```
#include <List.h>

/* Return true if L is empty */
int 
IsEmpty(List L)
{
    return L->Next == NULL;
}
```
* 测试当前元素是否是表的最后一个元素
```
#include <List.h>

/* Retyrn true if P is the last position in List L */
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}
```
* Find函数，返回某个元素在表中的位置
```
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
```

---
## 3.3 栈ADT

---

## 3.4 队列ADT

