//
//  SetHeap.cpp
//  test
//
//  Created by wangxue on 17/6/8.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <stdlib.h>

int max_N = 100;
int sz=0;

void push(int x,int heap[]){
    int i = sz++;
    while (i>0) {
        int p = (i-1)/2;  //parent child
        if(heap[p] <= x)  //all is in order
            break;
        heap[i] = heap[p]; //parent go back, new child is front
        i=p;
    }
    heap[i] = x;
}

int pop(int heap[]){
    int ret = heap[0];  //min
    int x = heap[--sz];  // need become root
    int i=0;
    while (i*2+1<sz) {
        int a = i*2+1, b =i*2+2;  //child
        if(b<sz && heap[b] < heap[a]) //compare
            a=b; //index
        printf("%d\n",a);
        if(heap[a] >= x)  //there is no mess
            break;
        heap[i] = heap[a]; //child go up
        printf("%d\n",i);
        i = a;
    }
    heap[i] = x;
    return ret;
}

int main(){
    int heap[max_N],i;
    push(2, heap);
    push(3, heap);
    push(1, heap);
    push(4, heap);
    push(0, heap);
    push(5, heap);
    for(i=0;i<sz;i++){
        printf("%d ",heap[i]);
    }
    printf("%d",pop(heap));
    for(i=0;i<sz;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}
*/
