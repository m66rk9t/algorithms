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

## 第7章 查找

## 第8章 排序