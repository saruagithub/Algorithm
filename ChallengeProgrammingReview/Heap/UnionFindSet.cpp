//
//  UnionFindSet.cpp
//  test
//
//  Created by wangxue on 17/7/1.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N=100;

int par[MAX_N]; //parent
int ran[MAX_N]; //tree height

void init(int n){
    for (int i=0; i<n; n++) {
        par[i] = i;
        ran[i] =0;
    }
}

//find the root
int Find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x] = Find(par[x]);
    }
}
void unit(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x==y)
        return;
    if(ran[x] < ran[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(ran[x] == ran[y])
            ran[x]++;
    }
}

bool same(int x,int y){
    return Find(x)==Find(y);
}

int main(){
    int i;
    init(5);
    par[1]=0; 
    par[2] = 0;
    par[4] = 3;
    unit(0, 3);
    cout<<Find(4)<<endl;
    for (i=0; i<5; i++) {
        cout<<"Len:"<<ran[i]<<endl;
    }
    return 0;
}
*/






