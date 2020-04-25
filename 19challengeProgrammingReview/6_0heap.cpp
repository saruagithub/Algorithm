//
//  6_0heap.cpp
//  test
//
//  Created by wangxue on 2019/7/16.
//  Copyright © 2019 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100;
int heap[MAX_N],sz=0; //sz is global variable, meaning the lengh of heap

void push(int x){
    //own node's num.
    int i = sz++;
    while (i>0) {
        int p = (i-1)/2; //i's parent
        if (heap[p] <= x) {
            break; // sequence is right
        }
        heap[i] = heap[p]; // parent's value put down, own value go up
        i = p;
    }
    heap[i] = x;
}

int pop(){
    // min (root)
    int rec = heap[0];
    // the new temp root value, get it for compare and move it
    int x = heap[--sz];
    //replace from the root
    int i = 0;
    while (i*2+1<sz) {
        //compare the children value
        int a = i*2+1;
        int b = i*2+2;
        if (b<sz && heap[b]<heap[a]) {
            a = b;
        }
        // sequence is right
        if (heap[a] >= x) {
            break;
        }
        // child's value go up
        heap[i] = heap[a];
        i=a;
    }
    heap[i] = x;
    return rec;
}

int main1(){
    //push(3);
    push(9);
    push(2);
    push(6);
    for (int i=0; i<sz; i++) {
        cout<<heap[i]<<endl;
    }
    cout<<pop()<<endl;
    return 0;
}

int main2(){
    priority_queue<int> qqueue;
    qqueue.push(3);
    qqueue.push(5);
    qqueue.push(1);
    //loop until it is empty
    while (!qqueue.empty()) {
        cout<<qqueue.top()<<endl;
        qqueue.pop();
    }
    return 0;
}
*/
