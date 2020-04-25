//
//  5_2DP_pack2.cpp
//  test
//
//  Created by wangxue on 2019/6/30.
//  Copyright © 2019 wangxue. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_N = 100,MAX_V=100;
int n,w[MAX_N],v[MAX_N],dp[MAX_N][MAX_N],W;
//n means the num. of object, w means the each weight of the obj.
//v means the value, W means the tolerance of the package

//Full backpack problem,complexity is O(nw^2)
void solve(){
    for (int i=0;i<n;i++){
        for (int j=0; j<=W; j++) {
            //k=0 means not select the i obj.
            for (int k=0; k*w[i]<=j; k++) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]] + k*v[i]);
            }
        }
    }
    cout<<dp[n][W]<<endl;
}

//dp[i+1][j] has the same situation with dp[i+1][j-w[i]] on k loop
void solve1(){
    for (int i=0; i<n; i++) {
        for (int j=0; j<=W; j++) {
            if (j<w[i]) {
                dp[i+1][j] = dp[i][j];
            }
            else{
                dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    cout<<dp[n][W]<<endl;
}

//save the memory，dp[i+1]需要的是dp[i]跟dp[i+1]，结合奇偶性改写：
int dp_save[2][MAX_N+1];
void solve2(){
    for (int i=0; i<n; i++) {
        for (int j=0; j<=W; j++) {
            if (j<w[i]) {
                dp_save[(i+1) & 1][j] = dp_save[i & 1][j];
            }
            else{
                dp_save[(i+1) & 1][j] = max(dp_save[i & 1][j],dp_save[(i+1)&1][j-w[i]] + v[i]);
            }
        }
    }
    cout<<dp_save[n&1][W]<<endl;
}


//书P60，依旧问题规模来改变算法。限制条件改变，相比较重量而言，价值的范围比较小
//dp[i+1][j] = 前i个物品中挑选出价值总和为j时，总重量的最小值
//初始值dp[0][0] = 0, dp[0][j]=INF
//前i个物品挑选出价值总和为j时，一定有：
//  前i-1个物品中挑选价值总和为j的部分
//  前i-1个物品中挑选价值总和为j-v[i]的部分，然后选中i物品
int dp3[MAX_N+1][MAX_N*MAX_V+1];
void solve3(){
    memset(dp3[0],0x3f,sizeof(dp3[0]+MAX_N*MAX_V+1));
    //fill(dp3[0],dp3[0]+MAX_N*MAX_V+1,0x3f3f3f3f);
    dp3[0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<MAX_N*MAX_V; j++) {
            if (j<v[i]) { //当前的价值总和小于物品i的价值，则必定从前面挑选的
                dp3[i+1][j] = dp3[i][j];
            }else{
                dp3[i+1][j] = min(dp3[i][j],dp3[i][j-v[i]] + w[i]);
            }
        }
    }
    //求解令dp[n][i]<=W的最大的j
    int res=0;
    for (int i=0; i<=MAX_N*MAX_V; i++) {
        if (dp3[n][i]<=W) {
            res = i;
        }
    }
    cout<<res<<endl;
}

int main(){
    //book P59
    cin>>n>>W;
    for (int i=0; i<n; i++) {
        cin>>w[i]>>v[i];
    }
    //solve();
    //solve1();
    //solve2();
    solve3();
}
*/
