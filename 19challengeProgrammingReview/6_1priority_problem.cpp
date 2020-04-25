//
//  6_1priority_problem.cpp
//  test
//
//  Created by wangxue on 2019/7/18.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10000;
int N,L,P;
int A[MAX_N+1],B[MAX_N+1],station[MAX_N+1];

void solve(){
    priority_queue<int> que;
    int ans=0,pos=0,tank=P,newgas;//at first
    for (int i=0; i<N; i++) {
        int d = A[i] - pos; // the distance from the next site
        while (d > tank) {
            if (que.empty()) {
                cout<<"can't arrive! -1"<<endl;
                return;
            }
            newgas = que.top();
            // find the refuel station num.
            for (int j=0; j<i; j++) {
                if (B[j] == newgas) {
                    station[ans] = j;
                }
            }//
            tank += newgas;
            que.pop();
            ans++;
        }
        tank-=d;
        pos = A[i];
        que.push(B[i]);
    }
    cout<<ans<<endl;
    for (int i=0; i<ans; i++) {
        cout<<station[i]<<endl;
    }
}

int main6_1(){
    //P75,solution analyze, when the car arrive at the gas, it get the refuel
    //right of Bi at any later time
    // pass the gas station, add Bi into the priority queue;
    // when fuel tank is empty, if queue is empty then cann't arrive, or get
    //the max value of queue for refueling.
    cin>>N>>L>>P;
    for (int i=0; i<N; i++) {
        cin>>A[i]>>B[i];
    }
    A[N] = L;
    B[N] = 0;
    N++; //The end position is the gas station(just for convinience)
    
    solve();
    return 0;
}
