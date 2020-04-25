//
//  4_1greedy_army.cpp
//  test
//
//  Created by wangxue on 2019/4/24.
//  Copyright © 2019 wangxue. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    int N,R;
    cin>>N>>R;
    int X[N];
    for (int i=0; i<N; i++) {
        cin>>X[i];
    }
    sort(X, X+N);
    
    int i = 0,ans = 0;
    while (i<N) {
        int s = X[i++];//s是没有被覆盖的最左的点的位置
        while (i<N && X[i]<=s+R) i++;
        int p = X[i-1];//新加上标记的点的位置
        while (i<N && X[i] <= p+R) i++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
*/
