//
//  Dfs.cpp
//  test
//
//  Created by wangxue on 17/5/2.
//  Copyright © 2017年 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int max_N = 100;
int n,k,a[max_N];

bool dfs(int i,int sum){
    if(i == n)
        return sum==k;
    if(dfs(i+1, sum))  //not add a[i]
        return  true;
    if(dfs(i+1, sum+a[i]))
        return true;
    return false;
}

int main_tzcx_dfs()
{
    int i;
    cout<<"input n:";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    
    if(dfs(0,0))
        printf("Yes!\n");
    else
        printf("No!\n");
    return 0;
}
