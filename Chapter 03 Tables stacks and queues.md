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
* MakeEmpty函数使得表为空
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
* IsEmpty函数测试空表
```
#include <List.h>

/* Return true if L is empty */
int 
IsEmpty(List L)
{
    return L->Next == NULL;
}
```
* IsLast函数测试当前元素是否是表的最后一个元素
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
* FindPrevious函数找出含有X元素的表元的前驱元$P$
```
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
```
* Delete函数删除表L中的某个元素X，只删除第一次出现的X，如果X不在表中就什么都不做
```
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
        free(TemCell);    
    }
}
```
* Insert插入函数，将要插入的元素与表L和位置P一起传入
```
#include <List.h>

/* Insert(after legal position P) */
/* Header implemention assumed */
/* Parameter L is unused in this implementation */
void 
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of space!!!")
    
    TmpCell->Element = X;
    TpmCell->Next = P->Next;
    P->Next = TmpCell 
}
```
* DeleteList删除链表
```
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
```
### 3.2.4 常见错误
* memory access violation或segmentation violation通常意味着有指针变量包含了伪地址。**无论何时只要确定一个指向，那么就必须保证该指针不是NULL**
* 涉及何时使用或者何时不使用malloc来获取一个新的单元.
### 3.2.5 双链表（doubly linked list）
下表是一个双链表
<center>![003](https://imgur.com/765yWxU.png)</center>
### 3.2.6 循环链表
下表是一个循环链表
<center>![004](https://imgur.com/CK3P420.png)</center>
### 3.2.7 例子
#### 3.2.7.1 多项式ADT
令$F\left( X \right) = \sum\nolimits_{i = 0}^N {{A_i}{X^i}} $，令大部分系数非零，那么我们可以用一个简单数组来存储这些系数，然后可以编写一些对多项式进行加、减、乘、微分以及其他操作的例程。
* 多项式ADT的数组实现的类型声明
```
typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;
```
* 将多项式初始化为零的过程
```
#include <Polynomial.h>

void
ZeroPolynomial(Polynomial Poly)
{
    int i;
    
    for(i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}
```
* 两个多项式相加
```
#include <Polynomail.h>

void
AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
    int i;
    ZeroPolynomial(PolySum);
    
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
    
    for(i = PolySum->HighPower; i >= 0; i--)
    {
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }    
}
```
* 两个多项式相乘
```
#include <Polynomail.h>

void
MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
    int i, j;
    ZeroPolynomial(PolyProd);
    
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    
    if(PolyProd->HighPower > MaxDegree)
        Error("Exceeded array size.");
    else
        for(i = 0; i < Poly1->HighPower; i++)
            for(j = 0; j <Poly2->HighPower; j++)
                PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j]; 
}
```
#### 3.2.7.2 基数排序（radix sort）
如果我们有$N$个整数，范围从1到$M$（或者从0到$M-1$），我们可以利用这个信息得到一个快速的排序，叫做桶排序（bucket sort）。我们留置一个数组，称之为Count，大小为$M$，并初始化为零。于是，Count有$M$个单元或者桶，开始都是空的。当$A_i$被读入时候，Count[$A_i$]增加1。在所有的输入被读进去以后，扫描数组Count，打印输出排好序的表。该算法花费$O(M+N)$。如果$M = \Theta (N)$，则桶式排序为$O(N)$。
#### 3.2.7.3 多重表
假设大学有40000名学生和2500门课程，需要生成两类报告，一类是列出每个班的注册者，一类是列出每个学生注册的班级。如果用二维数组实现，则需要1亿项数据，平均每个学生注册三门课程，有效数据只有120000项，大约占0.1%。下面是注册问题的多重表实现。
<center>![005](https://imgur.com/dDxFWLu.png)</center>

### 3.2.8 链表的游标实现
如果需要链表但是不能使用指针，那么可以使用游标(cursor)。
* 链表游标的实现声明
```
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
```
* CursorAlloc和CursorFree
```
#include <Cursor.h>

static Position
CursorAlloc(void)
{
    Position P;
    
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    
    return P;    
}

static void
CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[P].Next = P;    
}
```
* IsEmpty函数测试一个链表是否为空函数-游标实现
```
#include <Cursor.h>

/* Return true if L is empty */
int
IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}
```
* IsLast测试P是否是链表的末尾的函数---游标实现
```
#include <Cursor.h>

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int
IsLast(Position P, List L)
{
    return CursorSpace[P].Next == 0；
}
```
* Find---游标实现
```
#include <Cursor.h>

/* Return Position of X in L; 0 if not found */
/* Uses a header node */

Position
Find(ElementType X, List L)
{
    Position P;
    
    P = CursorSpace[L].Next;
    while(P && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;
        
    return P;
}
```
* Delete删除链表---游标实现
```
#include <Cursor.h>

/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void
Delete(ElementType X, List L)
{
    Position P. TmpCell;
    
    P = FindPrevious(X, L);
    
    if(!IsLast(P, L))
    {
        TmpCell = CursorSpace[P].Next；
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);    
    }    
}
```
* Insert插入操作---游标实现
```
#include <Cursor.h>

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    
    TmpCell = CursorAlloc();
    if(TmpCell == 0)
        FatalError("Out of space!!!")
    
    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}
```
---
## 3.3 栈ADT
### 3.3.1 栈模型
栈（stack）是限制插入和删除只能在一个位置上进行的表，该位置是表的末端，叫做栈的顶（top）。对栈的基本操作有Push（进栈）和Pop（出栈）。最后插入的元素可以通过使用Top例程在执行Pop之前进行考查。对空栈进行Pop或者Top一般认为是栈ADT的错误。当运行Push时空间用尽是一个实现错误，但不是ADT错误。
<center>![006](https://imgur.com/kQSbBdN.png)</center>
<center>栈模型：通过Push向栈输入，通过Pop从栈输出</center>
### 3.3.2 栈的实现
#### 3.3.2.1 栈的链表实现
* 栈ADT链表实现的类型声明
```
#ifndef _Stack_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif /* _Stack_h*/

/*Stack implementation is a linked list with a header */
struct Node
{
    ElementType Element;
    PtrToNode Next;    
};
```
* 测试栈是否空栈的例程---链表实现
```
#include <Stack.h>
int
IsEmpty(Stack S)
{
    return S->Next == NULL;    
}
```
* 创建一个空栈的例程---链表实现
```
#include <Stack.h>

Stack
CreateStack(void)
{
    Stack S;
    
    S = malloc(sizeof(struct Node));
    if(NULL == S)
        FatalError("Out of space!!!");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void
MakeEmpty(Stack S)
{
    if(NULL == S)
        Error("Must use Create first");
    else
        while(!IsEmpty(S))
            Pop(S);
}
```
* Push进栈的例程---链表实现
```
#include <Stack.h>

void 
Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    if(NULL == TmpCell)
        FatalError("Out of space!!!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}
```
* 返回栈顶元素的例程--- 链表实现
```
#include <Stack.h>

ElementType
Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return 0; /* Return value used to avoid warning */
}
```
* 从栈弹出元素的例程---链表实现
```
#include <Stack.h>

void
Pop(Stack S)
{
    PtrToNode FirstCell;
    
    if(IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}
```
#### 3.3.2.2 栈的数组实现

### 3.3.3 应用
---

## 3.4 队列ADT

