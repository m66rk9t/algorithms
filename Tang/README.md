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

#### 04 FORTRAN语言中，数组元素按列优先存储，设每个元素占L个单元，首元素的地址为b，如有以下三个数组，试分别确定三个数组中某一元素的地址：`LOC(A[i])`，`LOC(A[i][j])`，`LOC(A[i][j][k])`。

+ `A[n] = (A[1]...A[n])`
+ `A[m][n](m行n列)`
+ `A[m][n][p]`

```
LOC(A[i]) = b + i * L
LOC(A[i][j]) = b + (j * n + i) * L
LOC(A[i][j][k]) = b + (j * m * p + k * m + i) * L 
```

#### 05 设矩阵 

<img src="https://latex.codecogs.com/svg.image?A=\begin{Bmatrix}1&0&0&0&2\\0&3&0&0&4\\0&0&0&5&0\\0&0&0&6&0\\0&0&0&0&7\\\end{Bmatrix}(1<=i,j<=5)" title="A=\begin{Bmatrix}1&0&0&0&2\\0&3&0&0&4\\0&0&0&5&0\\0&0&0&6&0\\0&0&0&0&7\\\end{Bmatrix}(1<=i,j<=5)" />

+ 若将A视为一个上三角矩阵时，请画出A的按行优先存储的压缩存储表S，并写出A中元素`A[i][j]`与S中元素`S[k]`之间的关系。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/01.png)

`k = (i-1)(10-i)/2 + j (i<=j&&i>=1&&i<=5&&j>=1&&j<=5)`

+ 若将A视为一个稀疏矩阵时，请画出A的三元组表和十字链表结构。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/02.png)

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/03.png)

#### 06 设银行一天营业业务表头H：

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/04.png)

+ 试用广义表形式表示H，并用`Gethead()`和`Gettail()`函数提取d2。

```
广义表形式表示H：
由H = (A, B, X), A = (a1, D, a3), B = (b1, b2, b3), D = (d1, d2, d3)
可得H = ((a1, (d1, d2, d3), a3), (b1, b2, b3), X)

取表H中的d2：
由Gethead((d2, d3)) = d2, Gettail(D) = (d2, d3), Gethead((D, a3)) = D, Gettail(A) = (D, a3), Gethead(H) = A
可得Gethead(Gettail(Gethead(Gettail(Gethead(H))))) = d2
```

+ 画出表H的单链以及双链结构。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0501.png)

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0502.png)

#### 07 已知二叉树BT如下：

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0601.png)

+ 写出按先序、中序、后序遍历方法对BT遍历的结果。

```
DLR(先序遍历):(25, 36, 52, 81, 15, 42, 74, 63, 21, 45, 31, 88)
LDR(中序遍历):(52, 36, 15, 42, 81, 25, 74, 21, 63, 31, 88, 45)
LRD(后序遍历):(52, 42, 15, 81, 36, 21, 88, 31, 45, 63, 74, 52)
树BT相应满二叉树节点个数为63个。
```

+ 画出BT的先、中、后序线索二叉树。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0602.png)

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0603.png)

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0604.png)

#### 08 若后序线索二叉树中某p节点存在右子树，写出求p之右子树在后序下第一节点指针的算法（实线为指针，虚线为线索）

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/07.png)

```c
/*函数调用*/
rfirstnode = GetLRDFirst(p->RChild);
/*函数定义*/
BTptr GetLRDFirst(BTptr p)
{
    BTptr firstnode;

    if (p->LChild)  firstnode = GetLRDFirst(p->LChild);
    else if (p->RChild)  firstnode = GetLRDFirst(p->RChild);
    else firstnode = p;

    return firstnode;
}
```


#### 09 设某二叉树的先、中、后序遍历序列为以下结果，请根据此画出二叉树的逻辑结构。

```
DLR:(A,B,C,D,E,F,G,H)
LDR:(B,D,C,A,E,G,F,H)
```

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/08.png)

#### 10 二位数组A的元素都是3个字符组成的串。行下标i的范围从1到18，列下标j的范围从1到10。从首地址SA开始连续存放在存储器内。当该数组按行优先方式存储时，元素`A[8,5]`的起始地址是多少？

```
由题可知：
1.二维数组A中每个元素占用3字节内存。
2.二维数组A用8行10列，索引都由1开始。
3.二维数组A的起始地址为SA。
因此A[8,5]的起始地址为：
LOC(A[8,5]) = SA + [(8 - 1) X 10 + (5 - 1)] X 3
            = SA + [70 + 4] X 3
            = SA + 74 X 3
            = SA + 222
即A[8,5]的起始地址为SA+222。
```

#### 11 森林与二叉树的转换。
+ 将如下的森林F = {T1, T2, T3}转换成二叉树BT。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0901.png)

+ 将如下的二叉树BT转换成森林F。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/0902.png)

#### 12 设加权集合W = {7, 19, 2, 6, 32, 3, 21, 10}，试构造关于W的一个Huffman树，并求该树的WPL。

![image](https://github.com/m66rk9t/datastructure/blob/main/Pics/10.png)

```
WPL = 19 * 2 + 21 * 2 + 2 * 5 + 3 * 5 + 6 * 4 + 7 * 4 + 10 * 4 + 32 * 2
    = 38 + 42 + 10 + 15 + 24 + 28 + 40 + 64
    = 261
该树的WPL为261。
```

#### 13 设有向图G1，试构造G1的邻接矩阵、邻接表和十字链表结构。

#### 14 设无向图G2，写出从顶点V0出发，按DFS和BFS方法遍历G2所得到的顶点序列。

#### 15 设无向网G3，画出从顶点a出发，按Prim算法产生的一颗最小生成树。

#### 16 设有向网G4，用Floyd算法求出G4中任意两点间最短路径长度的矩阵，即：`D<sub>-1</sub>, D<sub>0</sub>, D<sub>1</sub>, D<sub>2</sub>, D<sub>3</sub>, D<sub>4</sub>, D<sub>5</sub>, = ?`。

#### 17 设有向图G5，写出G5的所有拓扑序列。