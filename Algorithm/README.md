# 《新编数据结构习题与解析》算法设计题

> 章节目录并非原书籍目录。

## 第1章 线性表

## 第2章 栈和队列

## 第3章 串

## 第4章 数组和广义表

## 第5章 树和二叉树

## 第6章 图

01 设计一个顺序查找的递归算法，对应的递归模型如下：

+ f(R, n, k, i) = -1(当i >= n)
+ f(R, n, k, i) = i(当R[i].key = k)
+ f(R, n, k, i) = f(R, n, k, i+1)(其他情况)

```c
/*初次调用该函数时，i = 0*/
int SqeSearch(SeqList R, int n, KeyType k, int i)
{
    if (i >= n)
        return -1;
    else if (R[i].key == k)
        return i;
    else
        return f(R, n, k, i+1);
}
```

02 设计一个折半查找的递归算法，对应的递归模型如下：

+ f(R, low, high, k) = -1(当low > high)
+ f(R, low, high, k) = mid (mid = (low + high) / 2)(当R[mid].key = k)
+ f(R, low, high, k) = f(R, low, mid - 1, k) mid (mid = (low + high) / 2)(当k < R[mid].key)
+ f(R, low, high, k) = f(R, mid + 1, high, k) mid (mid = (low + high) / 2)(当k > R[mid].key)

```c
/*初次调用该函数时，low = 0，high = n - 1*/
int BinSearch(SeqList R, int low, int high, KeyType k)
{
    int mid;
    
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (R[mid].key < k)
            return BinSearch(R, mid + 1, high, k);
        else if (R[mid].key > k)
            return BinSearch(R, low, mid - 1, k);
        else return mid;
    }

    return -1;
}
```

03 设计一个算法，利用折半查找在一个有序表中插入一个关键字为x的元素并保持表的有序性。思路是先使用折半查找在R中找到插入位置，然后将该位置后的所有元素后移一位，再将该位置插入关键字为x的记录。

```c
void BinInsert(SeqList R, int n, KeyType x)
{
    int low = 0, high = n - 1, mid, i;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (R[mid].key > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    for (i = n - 1; i >= high; i--)
        R[i + 1] = R[i];

    R[high + 1].key = x;
}
```

04 有一关键字为整数且均不相同的序列R[0...n - 1]，假设关键字递增有序排列，设计一个高效算法判断是否存在某一整数i，恰好存在于R[i]中。

```c
int BinFind(SeqList R, int n)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (R[mid].key == mid)
            return 1;
        else if (R[mid].key > mid)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return 0;
}
```

05 已知一个递增有序表 R[0...4n]，并且表中没有关键字相同的记录。按如下方法查找一个关键字为 k 的记录：先在编号为 4，8，12...4n 的记录中进行顺序查找，或者查找成功或者由此确定一个继续进行折半查找的范围。

+ 设计满足上述过程的查找算法。

```c

int FindElem(SeqList R, int n, KeyType k)
{
    int i = 4, low, high, mid;

    if (k < R[1].key || k > R[4 * n].key)
        return -1;

    while (i <= 4 * n)
    {
        if (R[i].key == k)
            return i;
        else if (R[i].key < k)
            i += 4;
        else
            break;
    }

    low = i - 3, high = i - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (R[mid].key == k)
            return mid;
        else if (R[mid].key > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
```

+ 分析成功查找情况下的平均查找长度，和对整个表进行折半查找相比哪个算法较好。

在查找成功情况下，顺序查找中平均关键字比较次数为(n + 1) / 2，然后在3个元素的范围内进行折半查找，其平均关键字比较次数为log<sub>2</sub>4 - 1 = 1，所以总的平均查找长度为(n + 1) / 2 + 1 = (n + 3) / 2。若对整个表进行折半查找，平均查找长度为log<sub>2</sub>(4n + 1) - 1。显然，折半查找更好些。

+ 为了提高效率，对本算法可以做何改进？

对本算法可以做这样的改进：由于编号为4，8，12...4n的记录是递增有序的，可以将顺序查找改为折半查找，然后在确定的范围内再进行折半查找。


## 第7章 查找

## 第8章 排序