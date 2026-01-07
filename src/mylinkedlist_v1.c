/*
带头尾虚节点的双向链表：对象版本
这是错的！！！！
*/
#include <stdio.h>

typedef struct {
    unsigned char val;
    Node* prev;
    Node* next;
} Node;

typedef struct {
    int size;
    Node head;
    Node tail;
} MyLinkedList;

void Initialize(MyLinkedList *linkedlist)
{
    linkedlist->size = 0;
    linkedlist->head.prev = NULL;
    linkedlist->tail.next = NULL; 
    linkedlist->head.next = &linkedlist->tail;
    linkedlist->tail.prev = &linkedlist->head;
    linkedlist->head.val = -1;
    linkedlist->tail.val = -1;
}

void AddAtIndex(MyLinkedList *linkedlist, int index, unsigned char val)
{
    // 检查index合法性
    Node x;
    x.val = val;
    Node p = getnode(linkedlist, index);
    Node temp = &p.prev;
    temp.next = &x;
    x.prev = &temp;
    p.prev = &x;
    x.next = &p;
    linkedlist->size++;
}

static Node getnode(MyLinkedList *linkedlist, int index);