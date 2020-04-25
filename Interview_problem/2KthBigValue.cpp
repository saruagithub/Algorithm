//
//  2KthBigValue.cpp
//  Algorithm
//
//  Created by wangxue on 2019/12/31.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[],int l, int r, int& pivot){
    do{
        while(A[++l] > pivot);
        while((l<r) && (A[--r] < pivot));
        swap(A,l,r);
    }while(l<r);
    return l;
}

void myqsort(int A[],int i,int j){
    if (i >= j) return;
    int pivotIndex = (i+j)/2;
    swap(A,pivotIndex,j);
    int k = partition(A,i-1,j,A[j]);
    swap(A,k,j);
    myqsort(A,i,k-1);
    myqsort(A,k+1,j);
}

int KthBig(int A[],int i,int j,int kBig){
    int count = 0; // init
    if (j <= i || A == NULL) return -1;
    int pivotIndex = (i+j)/2;
    swap(A,pivotIndex,j);
    int index = partition(A,i-1,j,A[j]); // k is index
    swap(A,index,j);
    // algorithm
    count = index - i + 1; // count the k big data
    if (kBig == count) {
        return index;
    }
    else if(count > kBig){
        return KthBig(A, i, index, kBig);
    }
    else{
        return KthBig(A, index, j, kBig-count);
    }
}

int mainI2(){
    int N=10,Kth=0;
    int num[10] = {-2,-1,0,-1,-1,-1,-1,2,-3,10};
    cout<<"input the k:";
    cin>>Kth;
    cout<<"k: "<<KthBig(num, 0, N-1, Kth)<<endl;
    //input
    for (int i=0; i<N; i++) {
        cout<<num[i]<<endl;
    }
    cout<<"--- k ---"<<endl;
    for (int i=0; i<Kth; i++) {
        cout<<num[i]<<endl;
    }
    // final qsort
    myqsort(num, 0, N-1);
    for (int i=0; i<N; i++) {
           cout<<num[i]<<endl;
    }
    return 0;
}

// ------------------- min heap --------------------------

const int MAX_N = 100;
int heap[MAX_N],sz=0; //sz is global variable, meaning the lengh of heap

void heap_push(int x){
    //own node's num.
    int node_index = sz++;
    while (node_index > 0) {
        int p = (node_index-1)/2; //i's parent
        if (heap[p] <= x) {
            break; // sequence is ok
        }
        // parent's value put down, node value go up
        heap[node_index] = heap[p];
        node_index = p;
    }
    heap[node_index] = x;
}

int heap_pop(){
    // min (root)
    int rec = heap[0];
    // the new temp root value, get it for compare and move it
    int x = heap[--sz];
    //replace from the root
    int i = 0;
    while (i*2+1 < sz) {
        //compare the children value
        int a = i*2+1;
        int b = i*2+2;
        if (b < sz && heap[b] < heap[a]) {
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

/*
struct node{
  int idx;
  int key;
  node(int a=0, int b=0):idx(a), key(b){}
};

struct cmp{
  bool operator()(node a, node b){
    return a.key > b.key;
  }
};
priority_queue<node, vector<node>, cmp> q;
 */

int main_I2(){
    //push(3);
    heap_push(9);
    heap_push(2);
    heap_push(6);
    for (int i=0; i<sz; i++) {
        cout<<heap[i]<<endl;
    }
    cout<<"pop:"<<heap_pop()<<endl;
    cout<<"pop:"<<heap_pop()<<endl;
    
    // ------ use package ------
    priority_queue<int> qqueue;
    qqueue.push(-9);
    qqueue.push(-2);
    qqueue.push(-6);
    //loop until it is empty
    while (!qqueue.empty()) {
        cout<<-1 * qqueue.top()<<endl;
        qqueue.pop();
    }
    return 0;
}
