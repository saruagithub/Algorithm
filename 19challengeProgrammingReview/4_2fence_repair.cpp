//
//  4_2fence_repair.cpp
//  test
//
//  Created by wangxue on 2019/4/30.
//  Copyright © 2019 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int &a,int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int N,ans = 0;
    cin>>N;
    int L[N];
    for (int i=0; i<N; i++) {
        cin>>L[i];
    }
    
    //直到计算到木板为1块时停止
    while (N>1) {
        //最短板和次短板
        int mii1=0,mii2=1;
        if (L[mii1] > L[mii2]) {
            swap(mii1,mii2);
            cout<<"mii1 & mii2:"<<mii1<<" "<<mii2<<endl;
        }
        for (int i=2; i<N; i++) {
            if (L[i] < L[mii1]) {
                mii2 = mii1;
                mii1  = i;
            }
            else if(L[i] < L[mii2]){
                mii2 = i;
            }
        }
        //合并两个板块
        int t = L[mii1] + L[mii2];
        ans += t;
        cout<<"1mii1 & mii2:"<<mii1<<" "<<mii2<<endl;
        if(mii1 == N-1) swap(mii1,mii2);
        L[mii1] = t;
        L[mii2] = L[N-1];//置为最后一个，因为N-1，最后一个会消失
        N--;
    }
    
    cout<<ans<<endl;
    return 0;
}
*/
