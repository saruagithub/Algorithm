//
//  4_3sortlist.cpp
//  test
//
//  Created by wangxue on 2019/12/26.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>

// ---------------------------

// leecode 148 sort the link O(nlogn), from min to max
// merge sort, bottom to up
// eg [4,3,1,7,8,9,2,11,5,6]
// step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
// step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
// step=4: (1->2->3->4->7->8->9->11)->5->6
// step=8: (1->2->3->4->5->6->7->8->9->11)

// merge(l1, l2)
// cut(l, n) split the link
// dummyHead tip
/*
current = dummy.next;
tail = dummy;
for (step = 1; step < length; step *= 2) {
    while (current) {
        // left->@->@->@->@->@->@->null
        left = current;

        // left->@->@->null   right->@->@->@->@->null
        right = cut(current, step); // 将 current 切掉前 step 个头切下来。

        // left->@->@->null   right->@->@->null   current->@->@->null
        current = cut(right, step); // 将 right 切掉前 step 个头切下来。
        
        // dummy.next -> @->@->@->@->null，最后一个节点是 tail，始终记录
        //                        ^
        //                        tail
        tail.next = merge(left, right);
        while (tail->next) tail = tail->next; // 保持 tail 为尾部
    }
}
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};
    
ListNode* cut(ListNode* head, int n) {
    auto p = head;
    while (--n && p) {
        p = p->next;
    }
    
    if (!p) return nullptr;
    
    auto next = p->next;
    p->next = nullptr;
    return next;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(0);
    auto p = &dummyHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }
    p->next = l1 ? l1 : l2;
    return dummyHead.next;
}

ListNode* sortList(ListNode* head) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    auto p = head;
    int length = 0;
    while (p) {
        ++length;
        p = p->next;
    }
    
    for (int size = 1; size < length; size <<= 1) {
        auto cur = dummyHead.next;
        auto tail = &dummyHead;
        
        while (cur) {
            auto left = cur;
            // left->@->@ right->@->@->@...
            auto right = cut(left, size);
            // left->@->@ right->@->@  cur->@->...
            cur = cut(right, size);
            
            tail->next = merge(left, right);
            while (tail->next) {
                tail = tail->next;
            }
        }
    }
    return dummyHead.next;
}
