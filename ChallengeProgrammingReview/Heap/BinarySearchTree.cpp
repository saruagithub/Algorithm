//
//  BinarySearchTree.cpp
//  test
//
//  Created by wangxue on 17/6/13.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <algorithm>

struct node{
    int val;
    node *lch;
    node *rch;
};

node *insert(node *p,int x){
    if(p == NULL){
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else{
        if(x < p->val)
            p->lch = insert(p->lch, x);
        else
            p->rch = insert(p->rch, x);
        return p;
    }
}

bool find(node *p,int x){
    if(p == NULL)
        return false;
    else if(x ==p->val)
        return true;
    else if(x < p->val)
        return find(p->lch, x);
    else
        return find(p->rch, x);
}

node *remove(node *p,int x){
    if(p == NULL)
        return NULL;
    else if (x < p->val)
        p->lch = remove(p->lch, x);
    else if (x > p->val)
        p->rch = remove(p->rch, x);
    else if(p->lch == NULL){
        node *q = p->rch;
        delete p;
        return q;
    }
    else if (p->lch->lch == NULL){
        node *q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    }
    else{
        node *q;
        for(q = p->lch;q->rch->rch != NULL;q = q->rch);
        node *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}


int main()
{
    node *p;
    p->val = 1;
    insert(p, 2);
    return 0;
}*/
