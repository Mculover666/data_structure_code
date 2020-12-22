/**
 * @brief   顺序线性表的实现及测试
 * @author  Mculover666
 * @date    2020年12月22日22:11:03
 */

#include <stdio.h>

#define MAX_SIZE    10          //最大元素个数
typedef int element_t;          //元素类型
typedef struct {
    element_t data[MAX_SIZE];   //数据域
    int list_length;            //线性表长度
} SqList;

/**
 * @brief   打印线性表中的所有数据
 * @param   list 线性表指针
 * @retval  none
 * */
void ListShow(SqList *list)
{
    printf("list [");
    for (int k = 0; k < list->list_length; k++) {
        printf("%d:%d ", k+1, list->data[k]);
    }
    printf("]\r\n");
}

/**
 * @brief    初始化线性表
 * @param    ist 线性表指针
 * @retval   none
 */
 void ListInit(SqList *list)
 {
    list->list_length = 0;
 }

/**
 * @brief    在线性表第i个元素之前插入数据
 * @param    list 线性表指针
 * @param    i 插入位置
 * @param    e 元素数据
 * @retval   errcode
 * */
int ListInsert(SqList *list, int i, element_t e)
{
    int k;

    /* 检查表是否为满 */
    if (list->list_length == MAX_SIZE)
        return -1;

    /* 检查i是否在范围之内 */
    if (i < 1 || i > list->list_length + 1)
        return -1;

    /* 其余元素均后移一位，插入新元素到第i个元素之前 */
    for (k = list->list_length - 1; k >= i - 1; k--) {
        list->data[k+1] = list->data[k];
    }

    /* 将新元素插入 */
    list->data[i-1] = e;
    list->list_length++;

    return 0;

}
/**
 * @brief    删除线性表中第i个元素
 * @param    list 线性表指针
 * @param    i 删除位置
 * @retval   errcode
 * */
int ListRemove(SqList *list, int i)
{
    /* 检查线性表是否为空 */
    if (list->list_length < 1) {
        return -1;
    }

    /* 删除第i个位置处的元素，其余元素均向前移动一位 */
    for (int k = i - 1; k < list->list_length - 1; k++) {
        list->data[k] = list->data[k+1];
    }

    /* 线性表长度递减 */
    list->list_length--;

    return 0;
}


int main() {
    /* 创建顺序表 */
    SqList l;

    /* 初始化顺序表 */
    ListInit(&l);

    /* 打印初始化之后的顺序表 */
    ListShow(&l);

    /* 添加9个元素 */
    for (int k = 1; k < MAX_SIZE; k++) {
        ListInsert(&l, k, k + 100);
    }
    ListShow(&l);

    /* 插入元素测试 */
    ListInsert(&l, 3, 88);
    ListShow(&l);

    /* 删除元素测试 */
    ListRemove(&l, 3);
    ListShow(&l);

    return 0;
}
