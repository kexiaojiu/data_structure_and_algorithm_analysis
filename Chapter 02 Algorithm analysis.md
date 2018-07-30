<h1>Algorithm analysis</h1>
[toc]   
---

# 第2章 算法分析
## 2.1 数学基础
全书将使用下面四个定义 
（1）定义1
如果存在正常数$c$和$n_0$使得当$N \geqslant {n_0}$时$T\left( N \right) \leqslant cf\left( N \right)$，则记为$T\left( N \right) = O\left( {f\left( N \right)} \right)$.
（2）定义2
如果存在正常数$c$和$n_0$使得当$N \geqslant {n_0}$时$T\left( N \right) \leqslant cg\left( N \right)$，则记为$T\left( N \right) = \Omega \left( {f\left( N \right)} \right)$.
（3）定义3
$T\left( N \right) = \Theta \left( {h\left( N \right)} \right)$当且仅当$T\left( N \right) = O\left( {h\left( N \right)} \right)$且$T\left( N \right) = \Omega \left( {h\left( N \right)} \right)$.
（4）定义4
如果$T\left( N \right) = O\left( {p\left( N \right)} \right)$且$T\left( N \right) \ne \Omega \left( {p\left( N \right)} \right)$，则$T\left( N \right) = o\left( {p\left( N \right)} \right)$
## 2.2 运行时间计算
### 2.2.1 法则1-FOR循环
一次for循环运行时间至多是该for循环内语句（包含测试）的运行时间乘以迭代的次数.
### 2.2.2 法则2-嵌套的FOR循环
从里到外分析这些循环，在一组嵌套循环内部的一条语句总的运行时间为该语句的运行时间乘以该组所有的for循环的大小的乘积.
### 2.2.3 法则3-顺序语句
将各个语句的运行时间求和即可.
### 2.2.4 法则4-IF/ELSE语句
对程序片段
```
if(condition)
    S1
else
    S2
```
一个if/else语句的运行时间从不超过判断再加上S1和S2中运行时间长者的总的运行时间.
## 2.3 最大子序列和问题
给定整数$A_1$,$A_2$,$A_3$,$A_1$,...,$A_N$（可能有负数），求$\sum\limits_{k = i}^j {{A_k}} $的最大值（假定所有整数均为负数，则最大子序列和为0）
* 算法1
```
int
MaxSubsequenceSum(const int A[], int N)
{    
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for(i = 0; i < N; i++)
        for(j = i; j < N; j++)
        {
            ThisSum = 0;
            for(k = i; k <= j; k++)
                ThisSum += A[k];
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    return MaxSum;
}
```
* 算法2
```
int
MaxSubsequenceSum(const int A[], int N)
{
    int ThisSum, MaxSum, i, j;
    MaxSum = 0;
    for(i = 0; i < N; i++)
    {
        ThisSum = 0;
        for(j = i; j < N; j++)
        {
            ThisSum += A[j];
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;    
}
```
* 算法3
```
static int
MaxSubSum(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if(Left == Right) /*Base case*/
        if(A[Left] > 0)
            return A[Left];
        else
            return 0;
    
    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);
    MaxLeftBorderSum = 0; MaxRightBorderSum = 0;
    for(i = Center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        if( LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    for(i = Center + 1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        if( RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum =RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum)
}

int
MaxSubsequenceSum(const int A[], int N)
{
    return MaxSubSum(A, 0, N - 1);    
}
```
* 算法4
```
int
MaxSubsequenceSum(const int A[], int N)
{
    int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;
    for(j = 0; j < N; j++)
    {
        ThisSum += A[j];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }    
    return MaxSum;
}
```
## 2.4 运行时间中的对数
某些分治算法将以$O\left( {\log N} \right)$时间运行。除了分治算法，可将对数最常见的规律概括为下列一般法则：如果一个算法用常数时间（$O\left( 1 \right)$）将问题的大小削减为其一部分，那么该算法就是$O\left( {\log N} \right)$。另一方面，如果使用常数时间只是把问题减少一个常数，那么这种算法就是$O\left( N \right)$.
### 2.4.1 对分查找（Binary search）
给定一个整数$X$和整数$A_0,A_1,A_2,...,A_{N-1}$，后者已经预算排序并在内存中， 求使得$A_i=X$的夏标$i$

