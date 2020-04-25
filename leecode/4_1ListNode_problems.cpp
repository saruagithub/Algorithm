//
//  ListNode_problems.cpp
//  test
//
//  Created by wangxue on 2019/12/26.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};
ListNode* list_Create0()
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

void list_Print0(ListNode* pHead)
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


//leecode 2,两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head=new ListNode(-1);//存放结果的链表
    ListNode* h=head;//移动指针
    int sum=0;//每个位的加和结果
    bool carry=false;//进位标志
    while(l1!=NULL||l2!=NULL)
    {
        if(l1!=NULL)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        if(carry)
            sum++;
        h->next=new ListNode(sum%10);
        h=h->next;
        carry=sum>=10?true:false;
    }
    if(carry)
    {
        h->next=new ListNode(1);
    }
    return head->next;
}

// Kth node of singly linked list, double pointer, swot offer P135
ListNode* findKthTail(ListNode* phead,int k){
    if (phead==NULL || k==0) {
        return NULL;
    }
    ListNode* p1 = phead;
    ListNode* p2 = phead;
    //p1 go k firstly
    for (int i=0; i<k-1; i++) {
        if (p1) { //avoid k > total link node nums
            p1 = p1->next;
        }
        else return NULL;
    }
    //p2 go next with p1
    while (p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

// 根据上面改进而来，删除倒数第k个节点
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==nullptr || n==0) return nullptr;
    ListNode* p1 = head;
    ListNode* p2 = head;
    ListNode* p_before = head;
    // p1 go k step
    for(int i=0;i<n-1;i++){
        if(p1) p1 = p1->next;
        else return nullptr;
    }
    //p2 go same with p1
    while(p1->next != nullptr){
        p1 = p1->next;
        p_before = p2;
        p2 = p2->next;
    }
    //delete p2
    if(p2 == head){
        head = p2->next;
        delete p2;
    }
    else if(p2->next != nullptr){
        p_before->next = p_before->next->next;
        delete p2;
    }
    else{
        p_before->next = nullptr;
        delete p2;
    }
    return head;
}


// leecode 83 a sorted link, delete all duplicated elem
ListNode* deleteDuplicates(ListNode *head){
    if (head==nullptr || head->next == NULL) {
        return head;
    }
    ListNode *p = head;
    while (p->next != NULL) {
        if (p->val == p->next->val) {
            ListNode* node = p->next;
            p->next = p->next->next;
            node->next = NULL;
            delete node;
        }
        else p = p->next;
    }
    return head;
}

// leecode 83, or recursive, when return(stop condition), return what (head)
ListNode* deleteDuplicates1(ListNode *head){
    if (head==nullptr || head->next == NULL) {
        return head;
    }
    head->next =  deleteDuplicates1(head->next);
    if (head->val == head->next->val) {
        head = head->next;
    }
    return head;
}

//leecode 83
ListNode* deleteDuplicates2(ListNode *head){
    if (head==NULL || head->next==NULL) {
        return head;
    }
    ListNode *p,*q;
    p=head,q=head->next;
    while (p->next != NULL) {
        if (p->val == q->val) {
            if(q->next == NULL) p->next = NULL;
            else{
                ListNode* node = p->next;
                p->next = q->next;
                q = q->next;
                delete node;
            }
        }
        else{
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

//leecode 206 reverse ListNode
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* reverseList2(ListNode* head) {
    if (head==NULL || head->next==NULL) {
        return head; //end condition
    }
    ListNode* rhead = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return rhead;
}

// swot offer, merge two sequential listnode P147 t:O(n), s:O(n)
ListNode* mergeSortedList(ListNode* pHead1,ListNode* pHead2){
    if (pHead1 == nullptr) return pHead2;
    else if (pHead2 == nullptr) return pHead1;
    
    ListNode* pMergedHead = nullptr;
    if (pHead1->val < pHead2->val) {
        pMergedHead = pHead1;
        pMergedHead->next = mergeSortedList(pHead1->next,pHead2);
    }
    else{
        pMergedHead = pHead2;
        pMergedHead->next = mergeSortedList(pHead1, pHead2->next);
    }
    return pMergedHead;
}

//leecode100-21 合并两个有序链表
ListNode* mergeSortedList2(ListNode* l1, ListNode* l2) { //t:O(n)
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    ListNode* prehead = new ListNode(-1);//dummyhead
    ListNode* mergeNode = prehead;
    while (l1!=nullptr && l2!=nullptr) {
        if(l1->val < l2->val){
            mergeNode->next = l1;
            l1 = l1->next;
        }
        else{
            mergeNode->next = l2;
            l2 = l2->next;
        }
        mergeNode = mergeNode->next;
    }
    mergeNode->next = l1==nullptr?l2:l1; //tail
    return prehead->next;
}

//leecode100-23 合并k个有序链表 最小堆 t:O(Nlog(k)) n是所有链表元素个数 s:O(k)
ListNode* mergeKLists(vector<ListNode*>& lists){
    if (lists.size() == 0) {
        return nullptr;
    }
    ListNode* prehead = new ListNode(-1);
    ListNode* mergeNode = prehead;
    priority_queue<int> que;
    
    for (int i=0; i<lists.size(); i++) {
        while (lists[i] != nullptr) {
            que.push(-1 * lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    while (!que.empty()) {
        ListNode* temp = new ListNode(-1);
        temp->val = -1 * que.top();
        // set
        mergeNode->next = temp;
        que.pop();
        mergeNode = mergeNode->next;
    }
    return prehead->next;
}


ListNode* mergeKLists2(vector<ListNode*>& lists) {
    int len = lists.size();
    if (len == 0) return NULL;
    // 分组间隔每次扩大两倍
    int interval = 1;
    while (interval < len) {
        // 根据当前间隔，两两合并，合并后的结果保存在两个链表的第一个
        for (int i = 0; i < len - interval; i += 2 * interval) {
            lists[i]  = mergeSortedList2(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
}

// alibaba1 单向链表“双节”点逆转.
//    输入: 1->2 ->3 ->4 ->5
//    输出: 4->5->2->3->1
ListNode* reverseList_2node(ListNode* head) {
    if(head == nullptr || head->next==nullptr) return head;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    // 全部翻转
    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    int temp = 0;
    head = pre;
    // 交换双节点
    while (pre->next != nullptr && pre->next->next != nullptr){
        temp = pre->val;
        pre->val = pre->next->val;
        pre->next->val = temp;
        pre = pre->next->next;
    }
    return head;
}

// Leecode100-234 ListNode判断是否是回文链表  1->2->2->1是true
// 其一，find mid node 使用快慢指针找到链表中点。 其二，reverse 逆序后半部分。 其三，check 从头、中点，开始比较是否相同。
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre = nullptr;
    while(fast!= NULL && fast->next!=NULL){ //find the mid node
        slow = slow->next;
        fast = fast->next->next;
    }
    while(slow){ //reverse
        ListNode* next = slow->next;
        slow->next = pre;
        pre = slow;
        slow = next;
    }
    //check
    while(head && pre){
        if(head->val != pre->val) return false;
        head = head->next;
        pre = pre->next;
    }
    return true;
}

int main_leecode4(){
    /*
    //新建链表测试
    ListNode* node1 = list_Create0();
    //打印链表测试
    list_Print0(node1);
    
    //新建链表测试
    ListNode* node2 = list_Create0();
    //打印链表测试
    list_Print0(node2);
    
    //新建链表测试
    ListNode* node3 = list_Create0();
    //打印链表测试
    list_Print0(node3);
    
    vector<ListNode*> lists;
    lists.push_back(node1);
    lists.push_back(node2);
    lists.push_back(node3);
    
    ListNode* res = mergeKLists(lists);
    */
    
    //新建链表测试 输入到-1为止
    ListNode* node = list_Create0();
    //打印链表测试
    list_Print0(node);
    ListNode* res;
    res = reverseList_2node(node);
    list_Print0(res);
    return 0;
}
