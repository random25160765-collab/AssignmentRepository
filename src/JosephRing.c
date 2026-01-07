/*
带头尾虚节点的双向环形链表, 递归法解约瑟夫环问题
2026-1-6
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node; 
typedef struct MyRingLinkedList MyRingLinkedList;

struct Node {
    int val;
    Node* prev;
    Node* next;
}; // 这里的结构体内部已经用了Node，所以要先声明

struct MyRingLinkedList {
    int size;
    Node* head;
    Node* tail;
};

/* 节点在初始化时就创建 */
static Node* InitializeNode()
{
    // 绝对不能直接 Node *node——为什么？（自测）
    Node* node = (Node*)malloc(sizeof(Node)); // 注意检查
    if (node == NULL) {
        puts("Memory allocation failed!");
        return NULL; // 注意返回NULL
    }
    node->val = 0;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/* 链表在初始化时就创建 */
static MyRingLinkedList* InitializeLinkedList()
{
    MyRingLinkedList* ringlinkedlist = (MyRingLinkedList*)malloc(sizeof(MyRingLinkedList));
    if (ringlinkedlist == NULL) {
        puts("Memory allocation failed!");
        return NULL;
    }
    ringlinkedlist->head = InitializeNode();
    ringlinkedlist->tail = InitializeNode();
    ringlinkedlist->head->next = ringlinkedlist->tail;
    ringlinkedlist->head->prev = ringlinkedlist->tail;
    ringlinkedlist->tail->prev = ringlinkedlist->head;
    ringlinkedlist->tail->next = ringlinkedlist->head;
    ringlinkedlist->head->val = -1;
    ringlinkedlist->tail->val = -1;
    ringlinkedlist->size = 0;
    return ringlinkedlist;
}

static void AddAtTail(MyRingLinkedList *ringlinkedlist, int val)
{
    Node *newNode = InitializeNode();
    if (!newNode) return;
    newNode->val = val;
    Node *temp = ringlinkedlist->tail->prev;
    ringlinkedlist->tail->prev = newNode;
    newNode->next = ringlinkedlist->tail;
    temp->next = newNode;
    newNode->prev = temp;
}

MyRingLinkedList* InitializeJosephRing(int N)
{
    MyRingLinkedList* raw_ring = InitializeLinkedList();
    raw_ring->head->val = 1;
    raw_ring->tail->val = N;
    for (int i = 1; i < N-1; i++) {
        AddAtTail(raw_ring, i+1);
    }
    raw_ring->size = N;
    return raw_ring;
}

static void FreeNode(Node *node)
{
    free(node);
    node = NULL;
}

void DeleteIteration(Node *node, int step, int size, int cnt)
{
    Node *to_delete = node;
    for (int i = 1; i < step; i++) {
        to_delete = to_delete->next;
    }
    Node *next = to_delete->next;
    int val = to_delete->val;

    // 删除to_delete
    Node *to_delete_prev = to_delete->prev;
    Node *to_delete_next = to_delete->next;
    to_delete_prev->next = to_delete_next;
    to_delete_next->prev = to_delete_prev;
    FreeNode(to_delete);
    size--;
    cnt++;

    printf("Step %d: No.%d is killed!\n", cnt, val);
    if (step == 1) {
        if (size == 0) {
            printf("Game Over: No survivors.\n");
            return;
        }
    } else {
        if (size <= 2) {
            printf("Game Over: Survivors are %d and %d.\n", node->val, node->next->val);
            return;
        }
    }   
     
    DeleteIteration(next, step, size, cnt);
}

void DeleteNode(MyRingLinkedList *ringlinkedlist, int step)
{
    int cnt = 0;
    int size = ringlinkedlist->size;
    DeleteIteration(ringlinkedlist->head, step, size, cnt);
}

int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);

    if (M <= 0 || N <= 1 || argc != 3 || M > N) {
        printf("Are you kidding me?\n");
        return 0;
    }

    MyRingLinkedList *JosephRing = InitializeJosephRing(N);
    DeleteNode(JosephRing, M);
    return 0;   
}