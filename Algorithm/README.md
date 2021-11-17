# 《新编数据结构习题与解析》算法设计题

> 章节目录并非原书籍目录。

## 第1章 线性表

## 第2章 栈和队列

## 第3章 串

## 第4章 数组和广义表

## 第5章 树和二叉树

## 第6章 图

01 设计一个顺序查找的递归算法，对应的递归模型如下：

+ f(R, n, k, i) = -1                如果i >= n
+ f(R, n, k, i) = i                 如果R[i].key = k
+ f(R, n, k, i) = f(R, n, k, i+1)   其他情况

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

02 对长度为2<sup>k</sup>-1的有序表进行折半查找，在成功查找时，最少需要多少次关键字比较？最多需要多少次关键字比较？查找失败时的平均比较次数是多少？

+ 当查找记录正好处于中间位置时，关键字比较次数最少，所以折半查找在成功查找时最少需要1次关键字比较。
+ 折半查找在成功查找时最多关键字比较次数为判定树的高度，即log<sub>2</sub>(2<sup>k</sup>-1+1) = k。
+ 折半查找在不成功查找时比较过程都落在外部节点中，将判定树看成是一颗满二叉树，所有外部节点的高度为k+1，其关键字比较次数为k，所以查找失败时的平均比较次数是k次。

03 设计一个折半查找的递归算法，对应的递归模型如下：

+ f(R, low, high, k) = -1                                                   low > high
+ f(R, low, high, k) = mid (mid = (low + high) / 2)                         R[mid].key = k
+ f(R, low, high, k) = f(R, low, mid - 1, k) mid (mid = (low + high) / 2)   k < R[mid].key
+ f(R, low, high, k) = f(R, mid + 1, high, k) mid (mid = (low + high) / 2)  k > R[mid].key

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

## 第7章 查找

## 第8章 排序