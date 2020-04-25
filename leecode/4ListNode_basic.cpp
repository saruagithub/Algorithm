#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* list_Create()
{
    ListNode* pHead,*pCurrent,*pNew;
    int data;                                // save the input data
    pHead = new ListNode(INT_MIN);
    pCurrent = pHead;
    cin>>data;
    while(data != -1)
    {
        pNew = new ListNode(data);
        pCurrent->next = pNew ;
        pCurrent = pNew ;
        cin>>data;
 
    }
    return pHead->next;           // in fact, pCurrent is true pHead
}

void list_Print(ListNode* pHead)
{
    ListNode* tem ;
    if(pHead == NULL)
        return ;
    tem = pHead ;     // temp pointer, not change phead
    while(tem)
    {
        cout<<tem->val<<"    ";
        tem = tem->next;
    }
    cout<<endl;
}

ListNode *list_Insert(ListNode* pHead,int x,int y)
{
    if(pHead == NULL)
        return NULL;
    ListNode *pCurrent,*pNew;
    pCurrent = pHead ;
    pNew = new ListNode(y);
    while(pCurrent)
    {
        if(pCurrent->val == x)
            break;
        pCurrent = pCurrent->next;
    }
    pNew->next = pCurrent->next ;//在单向链表中，一定要注意当前节点的位置存放在前面结点的next域中
    pCurrent->next = pNew ;         //所以赋值的过程中是从后面的结点向前面的结点赋值的，而且指针指向谁，就赋给谁
    return pHead ;
}
//删除单向链表中的值为data的结点
ListNode* listDelete(ListNode* pHead,int data)
{
    if(pHead == NULL)
        return NULL;
    ListNode* pPre,*pCurrent ;
    pPre = pHead ;
    pCurrent = pPre->next ;
    //pNew = new ListNode(data);
    while(pCurrent)
    {
        if(pCurrent->val == data )
            break;
        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }
    if(pCurrent == NULL)
        cout<<"未能找到值为："<<data<<"的结点"<<endl;
    else
    {
        pPre->next = pCurrent->next ;
        delete pCurrent;
    }
    return pHead;
}
//单向链表的销毁
int listDestory(ListNode* pHead)
{
    if(pHead == NULL)
        return 0;
    ListNode *tem = NULL;
    while(pHead)
    {
        tem = pHead->next;
        delete pHead;
        pHead = tem;
    }
    return 0;
}

void AddToTail(ListNode* pHead,int value){
    ListNode* p = new ListNode(value);
    if (pHead == nullptr) {
        pHead = p;
    }
    else{
        ListNode* pNode = pHead;
        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }
        pNode->next = p;
    }
}

int main_4basic()
{
    //新建链表测试
    ListNode* node1 = list_Create();
    //打印链表测试
    list_Print(node1);
     /*
    //插入链表测试
    ListNode* node5 = list_Insert(node ,12,999);
    list_Print(node5);
 

    //删除链表测试
    ListNode* node6 = listDelete(node,20);
    list_Print(node6);
 
    //销毁链表测试
    int node7 = listDestory(node);
     */
 
   return 0;
}
