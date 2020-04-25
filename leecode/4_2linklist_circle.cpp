//
//  4_1linklist_Circle.cpp
//  test
//
//  Created by wangxue on 2019/12/19.
//  Copyright © 2019 wangxue. All rights reserved.
//  leecode 142 circle link detection

#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//leecode100-141
bool hasCycle(ListNode *head) {
    if (head == NULL || head -> next == NULL) return false;
    ListNode* slow, *fast;
    slow = head;
    fast = head;
    while (fast!= NULL && fast->next!=NULL){
        // slow go 1 step, fast go 2 step
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// leecode100-141 save elem to set, time O(n) space O(n)
ListNode *detectCycle(ListNode *head) {
    ListNode* p = head;
    set<ListNode*> elem_set;
    while(p){
        if (elem_set.find(p) != elem_set.end()) {
            return p;
        }
        //O(logN)
        elem_set.insert(p);
        p = p->next;
    }
    return NULL;
}

//leecode 142, fast and slow pointer
ListNode *detectCycle1(ListNode *head){
    ListNode *slow,*fast;
    slow = head;
    fast = head;
    while (slow!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            //fast pointer go from and start of the link
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            //now both pointer is in the start of the circle
            return fast;
            break;
        }
    }
    return NULL;
}


int main_4_1circle(){
    /*
    //input
    ListNode* res;
    ListNode *dummyhead,*head,*temp0,*temp1;
    dummyhead = new ListNode(-1);
    head = new ListNode(1);
    dummyhead ->next = head;
    temp0 = new ListNode(2);
    head->next = temp0;
    temp1 = new ListNode(4);
    temp0->next = temp1;
    temp1->next = temp0;
    
    //algorithm
    //res = detectCycle(head);
    res = detectCycle1(head);
    if (res == NULL) {
        cout<<"no circle"<<endl;
    }
    else cout<<res->val<<endl;
     */
    ListNode *dummyhead,*head,*temp0;
    dummyhead = new ListNode(-1);
    head = new ListNode(1);
    temp0 = new ListNode(2);
    head->next = temp0;
    temp0->next = head;
    cout<<hasCycle(head)<<endl;
    return 0;
}
