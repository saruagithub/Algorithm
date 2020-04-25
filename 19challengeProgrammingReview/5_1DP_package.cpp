//
//  5_1DP_package.cpp
//  test
//
//  Created by wangxue on 2019/6/21.
//  Copyright © 2019 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX_N = 100;
int n,w[MAX_N],v[MAX_N],dp[MAX_N][MAX_N];

// return the package total value,i means object num, j means the weight
int rec(int i,int j){
    int res;
    // no left object
    if (i==n){
        res = 0;
    }
    //can not select
    else if(j<w[i]){
        res = rec(i+1, j);
    }
    else{
        res = max(rec(i+1,j),rec(i+1, j-w[i]) + v[i]);
    }
    return res;
}

int rec_dp(int i, int j){
    // if it exits, use it directly
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    int res;
    if(i==n){
        res = 0;
    }
    else if (j<w[i]){
        res = rec_dp(i+1, j);
    }
    else{
        res = max(rec_dp(i+1, j),rec_dp(i+1, j-w[i]) + v[i]);
    }
    //res is stored into the dp array
    return dp[i][j]=res;
}

int main(){
    //  input n object, which weight is w_i and value is v_i
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>w[i]>>v[i];
    }
    int W; // package capacity
    cin>>W;
    // 1\recursive way
    cout<<rec(0, W)<<endl;
    
    // 2\Dp way
    memset(dp, -1, sizeof(dp));
    cout<<rec_dp(0, W)<<endl;
    
    // 3 loop way
    for (int i=n-1; i>=0; i--) {
        for (int j = 0; j<= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i+1][j];
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    cout<<dp[0][W]<<endl;
}

*/
