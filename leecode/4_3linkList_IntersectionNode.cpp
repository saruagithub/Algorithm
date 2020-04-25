//
//  4_2_1linkList_IntersectionNode.cpp
//  test
//
//  Created by wangxue on 2019/12/20.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){
    if(headA==NULL || headB==NULL){
        return NULL;
    }
    set<ListNode*> elems;
    ListNode *p1 = headA, *p2 = headB;
    while (p1) {
        elems.insert(p1);
        p1 = p1->next;
    }
    while (p2) {
        if (elems.find(p2)!= elems.end()) {
            return p2;
        }
        p2 = p2->next;
    }
    return NULL;
}

