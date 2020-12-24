/**
 * @brief   单链表（不带头结点）的实现及测试
 * @author  Mculover666
 * @date    2020年12月24日18:55:10
 */

#include <stdio.h>
#include <stdlib.h>

typedef int element_t;          //元素类型
typedef struct Node{
    element_t data;     //数据域
    struct Node *next;  //指针域
} Node;

/**
 * @brief   在链表头部插入一个新结点
 * @param   node 新插入的结点
 * @param   list 链表头指针的地址
 * */
void ListAddHead(Node *node, Node **list)
{
    /* 在首结点之前插入 */
    node->next = *list;
    *list = node;
}
/**
 * @brief   在链表尾部插入一个新结点
 * @param   node 新插入的结点
 * @param   list 待插入的链表
 * */
void ListAddTail(Node *node,Node *list)
{
    node->next = NULL;

    /* 根据链表是否为空 */
    if (list == NULL) {
        //直接插入
        list = node;
    } else {
        //遍历链表，直到最后一个结点
        while (list->next) {
            list = list->next;
        }
        list->next = node;
    }
}

/**
 * @brief   遍历打印链表所有数据
 * @param   list 链表头指针
 * @retval  none
 * */
void ListShow(Node *list)
{
    Node *cur;

    printf("list:");

    for (cur = list; cur; cur = cur->next) {
        printf("%d ", cur->data);
    }

    printf("\r\n");
}

/**
 * @brief   计算链表长度（有效结点数目）
 * @param   list 链表头指针
 * @retval  链表长度
 *
 * */
int ListLength(Node *list)
{
    int len = 0;

    while (list) {
        len++;
        list = list->next;
    }
    return len;
}

/**
 * @brief   查找链表中某个结点
 * @param   data 数据
 * @param   list 链表头指针
 * @retval  结点地址
 * */
Node *ListSearch(element_t data, Node *list)
{
    Node *cur;

    for (cur = list; cur; cur=cur->next) {
        if (cur->data == data) {
            return cur;
        }
    }

    return NULL;
}

/**
 * @brief   删除链表中的某个结点
 * @param   node 要删除的结点
 * @param   list 链表头指针
 * @retval  none
 * */
void ListRemove(Node *node, Node *list)
{
    Node *cur;

    /* 遍历链表，找到删除结点的上一个结点 */
    for (cur = list; cur; cur = cur->next) {
        if (cur->next == node) {
            cur->next = cur->next->next;
        }
    }
}

int main() {
    int k;
    Node *node;
    Node *list = NULL;

    /* 头插法插入10个新结点 */
    for (k = 0; k < 10; k++) {
        node = (Node *)malloc(sizeof(Node));
        if (!node) {
            printf("头结点内存分配失败！\r\n");
            return -1;
        }
        node->data = k+1;
        ListAddHead(node, &list);
    }
    ListShow(list);
    printf("list len:%d\r\n", ListLength(list));

    /* 尾插法插入10个新结点 */
    for (k = 0; k < 10; k++) {
        node = (Node *)malloc(sizeof(Node));
        if (!node) {
            printf("头结点内存分配失败！\r\n");
            return -1;
        }
        node->data = k+1;
        ListAddTail(node, list);
    }
    ListShow(list);
    printf("list len:%d\r\n", ListLength(list));

    /* 查找数据为1的第一个结点 */
    Node *n = ListSearch(1, list);
    printf("n = %p\r\n", n);

    /* 将查找到的结点从链表中移除 */
    ListRemove(n, list);
    /* 将结点的空间释放 */
    free(n);
    n = NULL;

    ListShow(list);
    printf("list len:%d\r\n", ListLength(list));

    return 0;
}
