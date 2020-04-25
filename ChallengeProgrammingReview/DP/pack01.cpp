//
//  pack01.cpp
//  test
//
//  Created by wangxue on 17/6/1.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[100][100];
int n,w[100],v[100];

int rec(int i,int j){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    if(i==n){
        dp[i][j] = 0;
    }
    else if(j < w[i]){
        dp[i][j] = rec(i+1,j);
    }
    else{
     dp[i][j] = max(rec(i+1,j), rec(i+1,j-w[i])+v[i]);
    }
    return dp[i][j];
}


int main()
{
    int W,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>w[i];
        cin>>v[i];
    }
    cin>>W;
    
    memset(dp, -1, sizeof(dp));
    
    int res;
    res = rec(0,W);
    cout<<res<<endl;
    
    memset(dp, -1, sizeof(dp));
    for(i=0;i<n;i++){
        for(j=0;j<=W;j++){
//            if(j==0)
//                dp[i][j] = 0;
            if(j<w[i])
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][W];
    return 0;
}
*/
