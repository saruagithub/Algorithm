//
//  SPBellman-Ford.cpp
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
#define INFINITE 100000
using namespace std;

struct edge {
    int from, to, cost;
};

edge es[100];
int d[100];
int V=5,E=5;

void shortest_path(int s)   //from s begin,to all dots
{
    int i;
    for (i = 0; i<V; i++) {
        d[i] = INFINITE;
    }
    d[s] = 0;
    while (true) {
        bool update = false;
        for (i=0; i<E; i++) {
            edge e = es[i];
            if((d[e.from] != INFINITE) && (d[e.to] > d[e.from] + e.cost)){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update)
            break;
    }
}

int main(){
    int i;
    for (i=0; i<4; i++) {
        es[i].from = i;
        es[i].to = i+1;
        es[i].cost = 2*i;
    }
    int s = 0;
    shortest_path(s);
    for (i=0; i<5; i++) {
        cout<<d[i]<<",";
    }
    return 0;
}

*/




