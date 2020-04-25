//
//  7_0BSTree.cpp
//  test
//
//  Created by wangxue on 2019/7/24.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int val;
    node *lch,*rch;
};

// p is the initial node location
bool find(node *p,int x){
    if (p==NULL) return false;
    else if(x == p->val) return true;
    else if(x < p->val) return find(p->lch,x);
    else return find(p->rch,x);
    
}

node *insert(node *p,int x){
    if (p==NULL) {
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else{
        if(x<p->val) p->lch = insert(p->lch, x);
        else p->rch = insert(p->rch, x);
        return p;
    }
}

//删除的节点没有左儿子，则把右儿子提上去
//删除的节点的左儿子没有右儿子，把左儿子提上去
//左儿子的子孙中最大的节点提到需要删除的节点上
node *removee(node *p,int x){
    if (p==NULL) return NULL;
    else if(x<p->val) p->lch=removee(p->lch, x);
    else if(x>p->val) p->rch=removee(p->rch, x);
    else if(p->lch==NULL){
        node *q = p->rch;
        delete p;
        return q;
    }
    else if (p->lch->rch == NULL){
        node *q = p->rch;
        q->rch = p->rch;
        delete p;
        return q;
    }else{
        node *q;
        for (q =p->lch; q->rch->rch!=NULL; q=q->rch);
        node *r = q->rch;
        q->rch = r->rch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}

// add, delete , search O(logn)
int main_0(){
    node *root;
    root = insert(NULL, 7);
    cout<<root->val<<endl;
    cout<<insert(root, 8)->val<<endl;
    cout<<insert(root, 2)->val<<endl;
    cout<<insert(root, 1)->val<<endl;
    cout<<insert(root, 3)->val<<endl;
    cout<<find(root,2)<<endl;
    return 0;
}
