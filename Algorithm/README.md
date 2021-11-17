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

## 第7章 查找

## 第8章 排序