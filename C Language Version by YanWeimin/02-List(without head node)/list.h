/*单链表（无头节点）定义*/
#ifndef LIST_H//你不需要懂，你不考这知识点
#define LIST_H//你不需要懂，你不考这知识点
#include <stdbool.h>

/*类型定义*/
typedef int Data;//将int类型定义为Data类型
typedef struct studentID{
    Data id;
    struct studentID *next;//指向struct studentID结构的指针
} Node;//将struct studentID结构类型定义为Node类型
typedef Node *LinkedList;//将指向Node类型的指针定义为LinkedList

/*函数原型*/
/*操作：将链表初始化空表*/
/*前置条件：*pList指向一个未初始化链表*/
/*后置条件：使*pList指向一个空表*/
void InitList(LinkedList *pList);
/*操作：判断链表是否为空表*/
/*前置条件：*pList指向一个链表*/
/*后置条件：如果*pList指向的链表为空表则返回true，否则返回false*/
bool ListIsNull(LinkedList * pList);
/*操作：判断链表是否已满*/
/*前置条件：*pList指向一个已初始化的链表*/
/*后置条件：如果*pList指向的链表已满则返回true，否则返回false*/
bool ListIsFull(LinkedList *pList);
/*操作：计算并返回链表中的节点数量*/
/*前置条件：*pList指向一个已初始化的链表*/
/*后置条件：返回*pList指向的链表中节点的数量*/
unsigned int ListLength(LinkedList *pList);
/*操作：将一个节点添加到链表尾部*/
/*前置条件：*pList指向一个已初始化的链表*/
/*后置条件：将含有数据data的新节点添加到*pList指向的链表尾部，*/
/*        添加成功返回true，添加失败返回false*/
bool AddNode(LinkedList *pList, Data data);
/*操作：将数据拷贝到指定节点中*/
/*前置条件：*pNode指向一个已分配空间的节点*/
/*后置条件：将data的数据拷贝到pNode指向的节点中*/
void CopyDataToNode(Node *pNode, Data data);
/*操作：删除一个节点*/
/*前置条件：*pList指向一个已初始化且不为空的链表*/
/*后置条件：删除*pList指向的链表中第num个节点，*/
/*        删除成功返回true，删除失败返回false*/
bool DeleteNode(LinkedList *pList, int num);
/*操作：读取指定节点中的数据*/
/*前置条件：*pList指向一个已初始化且不为空的链表*/
/*后置条件：将*pList指向的链表中第num个节点的数据拷贝到pNode指向的节点中，*/
/*         读取成功返回true，读取失败返回false*/
bool GetNodeData(LinkedList *pList, int num, Node *pNode);
/*操作：在指定位置插入一个节点*/
/*前置条件：*pList指向一个已初始化且不为空的链表*/
/*后置条件：在*pList指向的链表中num处插入一个新的节点，*/
/*        插入成功返回true，插入失败返回false*/
bool InsertNode(LinkedList *pList, int num, Node *pNode);
/*操作：打印链表节点的数据*/
/*前置条件：*pNode指向一个已初始化且不为空的链表中的节点*/
/*后置条件：打印*pNode指向的节点中的数据*/
void PrintNodeData(Node *pNode);
/*操作：销毁一个链表*/
/*前置条件：*pList指向一个已初始化的链表*/
/*后置条件：将为*pList指向的链表分配的存储空间销毁，*/
/*        销毁成功返回false，销毁失败返回false*/
bool DestoryList(LinkedList *pList);
/*操作：将指定的函数作用于链表中的每一个节点*/
/*前置条件：*pList指向一个已初始化且不为空的链表*/
/*后置条件：pFun指向的函数作用于链表中的每一个节点*/
void Traverse(LinkedList *pList, void (*pFun)(Node *pNode));


#endif//你不需要懂，你不考这知识点