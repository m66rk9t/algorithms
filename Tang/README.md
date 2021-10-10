## 数据结构（C语言版）-汤文学课后作业

#### 01 有两个线性表，编写实现La-Lb以及La∩Lb的函数。

```c
void Subtraction(List *La, List *Lb, List *Lc)
{
    datatype elem;
    int ins_pos = 0;
    
    InitList(Lc);
    
    for (int i = 0; i < ListLength(La); i++)
    {
        elem = GetElem(La, i);
        if (LocateElem(Lb, elem) == -1)
            ListInsert(Lc, ins_pos++, elem);
    }
}

void Intersection(List *La, List *Lb, List *Lc)
{
    datatype elem;
    int ins_pos = 0;
    
    InitList(Lc);
    
    for (int i = 0; i < ListLength(La); i++)
    {
        elem = GetElem(La, i);
        if (LocateElem(Lb, elem) != -1)
            ListInsert(Lc, ins_pos++, elem);
    }
}
```

#### 02 设元素为1，2，3，4，5。进栈顺序约定：值小的元素先进栈，但在两次进栈之间，可做出栈运算。写出5种可以得到的出栈序列和5中不可以得到的出栈序列。

```
（1）5种合法的出栈序列：
①1、2、3、4、5进，5、4、3、2、1出，则（5，4，3，2，1）。
②1进1出，2进2出，3进3出，4进4出，5进5出，则（1，2，3，4，5）。
③1进1出，2进2出，3进3出，4、5进5、4出，则（1，2，3，5，4）。
④1进1出，2进2出，3、4、5进5、4、3出，则（1，2，5，4，3）。
⑤1进1出，2、3、4、5进5、4、3、2出，则（1，5，4，3，2）。
（2）5种非法的出栈序列：
①（5，1，2，3，4），若5先出，那么5之前的元素（1、2、3、4）进栈后不能出栈，而5之前的元素进栈顺序不符合约定。
②（5，4，1，2，3），同①。
③（5，4，3，1，2），同①。
④（4，1，2，3，5），若4先出，那么4之前的元素（1、2、3）进栈后不能出栈，而4之前的元素进栈顺序不符合约定。
⑤（4，2，1，3，5），同④。
```

#### 03 设单链表：H→x→y→x，H→x→y→z→y→x为对称形式（表长=n）。使用栈操作，写出判断表H是否对称的算法：xyz(H)。

```c
bool xyz(LinkedList *H)
{ //H为指向单链表头节点指针的指针，解引用后为头节点的指针
    SeqStack ss;         //声明一个顺序栈
    Elem temp;           //栈元素，临时变量，储存出栈元素值
    Node *pNode;         //指向链表节点的指针
    unsigned int n = 0U; //链表长度
    InitStack(&ss);      //初始化栈

    pNode = (*H)->next; //指向链表H的首节点
    n = ListLength(H);  //计算链表长度

    for (int i = 0; i < n / 2; i++) //将链表前半部分节点的数据入栈
    {
        Push(&ss, &(pNode->data)); //入栈
        pNode = pNode->next;       //获取下一个节点
    }

    if (n % 2 != 0) //重置指针pNode
        pNode = pNode->next;

    while (pNode) //遍历链表剩余节点与出栈元素比较
    {
        Pop(&ss, &temp);         //出栈
        if (temp == pNode->data) //比较
            pNode = pNode->next; //获取下一个节点
        else
            return false; //非对称
    }

    DestoryStack(&ss); //销栈

    return true; //对称
}
```

#### 04 FORTRAN语言中，数组元素按列优先存储，设每个元素占L个单元，首元素的地址为b，试确定：
+ `A[n] =(A[1]...A[n])`
+ `A[m][n](m行n列)`
+ `A[m][n][p]`
#### 分别计算三个数组中某一元素地址：`LOC(A[i])`，`LOC(A[i][j])`，`LOC(A[i][j][k])`。

```
LOC(A[i]) = b + i * L
LOC(A[i][j]) = b + (j * n + i) * L
LOC(A[i][j][k]) = b + (j * m * p + k * m + i) * L 
```

#### 05 设矩阵 

<img src="https://latex.codecogs.com/svg.image?A=\begin{Bmatrix}1&0&0&0&2\\0&3&0&0&4\\0&0&0&5&0\\0&0&0&6&0\\0&0&0&0&7\\\end{Bmatrix}(1<=i,j<=5)" title="A=\begin{Bmatrix}1&0&0&0&2\\0&3&0&0&4\\0&0&0&5&0\\0&0&0&6&0\\0&0&0&0&7\\\end{Bmatrix}(1<=i,j<=5)" />

+ 若将A视为一个上三角矩阵时，请画出A的按行优先存储的压缩存储表S，并写出A中元素`A[i][j]`与S中元素`S[k]`之间的关系。

|S|0|`A[1][1]`|`A[1][2]`|....|`A[i][j]`|...|`A[5][5]`|
|-|-|-|-|-|-|-|-|
|k=|0|1|2|...|(i-1)(2\*n-i)/2 + j|...|n(n+1)/2|

`k = (i-1)(2\*n-i)/2 + j (i<=j&&i>=1&&i<=5&&j>=1&&j<=5)`

+ 若将A视为一个稀疏矩阵时，请画出A的三元组表和十字链表结构。

|row|col|val|
|-|-|-|
|1|1|1|
|1|5|2|
|2|2|3|
|2|5|4|
|3|4|5|
|4|4|6|
|5|5|7|

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/1.png)

#### 06 设银行一天营业业务表头H：

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/02.png)

+ 试用广义表形式表示H，并用Gethead()和Gettail()函数提取d2。

```
广义表形式表示H：
由H = (A, B, X), A = (a1, D, a3), B = (b1, b2, b3), D = (d1, d2, d3)
可得H = ((a1, (d1, d2, d3), a3), (b1, b2, b3), X)

取表H中的d2：
由Gethead((d2, d3)) = d2, Gettail(D) = (d2, d3), Gethead((D, a3)) = D, Gettail(A) = (D, a3), Gethead(H) = A
可得 Gethead(Gettail(Gethead(Gettail(Gethead(H))))) = d2
```

+ 画出表H的单链以及双链结构。