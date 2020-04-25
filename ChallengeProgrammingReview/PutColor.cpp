//
//  PutColor.cpp
//  test
//
//  Created by wangxue on 17/7/26.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

const int MAX_V=100;
vector<int> G[MAX_V];
int color[MAX_V];//color into 1 or -1

bool cdfs(int v,int c){
    int i;
    color[v] = c;
    for (i=0; i<G[v].size(); i++) {
        if(color[G[v][i]]==c) //adjacent color is the same
            return false;
        if(color[G[v][i]]==0 && !cdfs(G[v][i], -c))//adjacent point hasn't been painted
            return false;
    }
    return true;
}


int main(){
    int V,E,i;
    cin>>V>>E;
    
    for (i=0; i<V; i++) {
        color[i] = 0;
    }
    for (i=0; i<E; i++) {
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    for (i=0; i<V; i++) {
        if(color[i]==0){
            if(!cdfs(i, 1)){ //Put vertex i color 1
                printf("No!");
                return -1;
            }
        }
    }
    printf("Yes!");
    for (i=0; i<V; i++) {
        cout<<color[i]<<",";
    }
    return 0;
}
*/
