//
//  MLSequence.c
//  test
//
//  Created by wangxue on 17/6/5.
//  Copyright © 2017年 wangxue. All rights reserved.
//

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
    char s[n+1],t[m+1];
    scanf("%s %s",s,t);
    for(i=n;i>0;i--){
        s[n] = s[n-1];
    }
    s[0] = '0';
    for(i=m;i>0;i--){
        t[m] = t[m-1];
    }
    t[0] = '0';
    int dp[max_N][max_N];
    for(i=0;i<n+1;i++){
        dp[n][0] = 0;
    }
    for(i=0;i<m+1;i++){
        dp[0][m] = 0;
    }
    
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] +1;
                printf("%c",s[i]);
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
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
}
*/
