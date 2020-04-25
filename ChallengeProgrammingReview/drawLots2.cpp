//
//  drawLots2.cpp
//  test
//
//  Created by wangxue on 17/4/30.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int const max_N = 1000;
int kk[max_N * max_N];

bool binary_search(int x,int n){
    int l=0,r = n*n;
    while (r-l > 0) {
        int i = (l+r)/2;
        if(kk[i] == x)
            return true;
        else if(kk[i] > x )
            r = i;
        else
            l = i+1;
    }
    return false;
}

int main()
{
    int n,m,k[max_N],i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>k[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            kk[i*n+j] = k[i] + k[j];
        }
    }
    sort(kk, kk+n*n);
    bool f = false;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(binary_search(m-k[i]-k[j],n))
                f = true;
        }
    }
    if(f)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
*/


