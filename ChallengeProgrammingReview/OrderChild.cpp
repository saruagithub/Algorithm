//
//  OrderChild.cpp
//  test
//
//  Created by wangxue on 17/5/19.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int Index=1;

bool isContinueRise(int A[]){
    int temp = Index-1,i;
    //cout<<temp<<endl;
    while (A[Index-1] <= A[Index]) {
        Index++;
    }
    for(i=temp;i<Index;i++){
        if(A[i] < A[i+1])
            return true;
    }
    return false;
}

bool isContinueDecrease(int A[]){
    int temp = Index-1,i;
    while (A[Index-1] >= A[Index]) {
        Index++;
    }
    for(i=temp;i<Index;i++){
        if(A[i] > A[i+1])
            return true;
    }
    return false;
}

bool isAllEqual(int A[],int n){
    int i;
    for(i=1;i<n;i++){
        if(A[i] != A[i-1])
            return false;
    }
    return true;
}

int main()
{
    int n,i,res=0;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    if(n==1){
        cout<<"1"<<endl;
        return 1;
    }
    if(isAllEqual(A, n) == true){
        cout<<"1"<<endl;
        return 1;
    }
    
    while (Index<n) {
        if(isContinueRise(A) || isContinueDecrease(A)){
            res++;
            if(Index == n-1){
                res++;
                break;
            }
            Index++;
        }
    }
    
    cout<<res<<endl;
    return 0;
}
*/
