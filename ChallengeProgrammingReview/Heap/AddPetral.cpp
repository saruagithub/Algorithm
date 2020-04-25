//
//  AddPetral.cpp
//  test
//
//  Created by wangxue on 17/6/12.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace  std;

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


int main()
{
    int N,L,P,i,times=0;
    int petral[N];
    //priority_queue<int> pp;
    cin>>N>>L>>P;
    int A[N],B[N];
    for(i=0;i<N;i++){
        cin>>A[i];
    }
    for(i=0;i<N;i++){
        cin>>B[i];
    }
    if(P >= L){
        cout<<"0"<<endl;
    }
    else if (P < A[0]){
        cout<<"-1"<<endl;
    }
    else{
        for (i=0; i<N; i++) {
            if(P >= A[i]){
                push(B[i], petral);
                continue;
            }
            if(P < A[i]){
                P += pop(petral);
                times++;
                if(P >= L)
                    break;
            }
        }
    }
    cout<<"times: "<<times<<endl;
    return 0;
}

*/


