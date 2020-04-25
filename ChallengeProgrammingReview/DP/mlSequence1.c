//
//  mlSequence1.c
//  test
//
//  Created by wangxue on 17/6/6.
//  Copyright © 2017年 wangxue. All rights reserved.
//

//挪位置
/*
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n,m;
int max_N = 100;

int max(int a,int b){
    if(a>=b)
        return a;
    else
        return b;
}

int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    char s[n],t[m];
    scanf("%s %s",s,t);
    int dp[max_N][max_N];
//    if(s[0] == t[0])
//        dp[0][0] = 1;
//    else
//        dp[0][0] = 0;
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] +1;
                printf("%c",s[i]);
            }
            else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                printf("dp[%d][%d] %d",i+1,j+1,dp[i+1][j+1]);
            }
        }
    }
    printf("\n");
    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){
            printf("%d",dp[i][j]);
        }
        printf("\n");
    }
    printf("  %d",dp[n][m]);
    return 0;
}*/
