//
//  drawLots.cpp
//  test
//
//  Created by wangxue on 17/4/29.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int max_N = 100;
int k[max_N];

bool binary_search1(int q,int n){
    int l=0,r=n;
    while (r-l>0) {
        int i = (l+r)/2;
        if(k[i] == q)
            return true;
        else if(k[i] > q)
            r =i;
        else
            l =i+1;
    }
    return false;
}

//O(n^3logn)
int main()
{
    int n,m;
    int i,j,p,q;
    bool f = false;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>k[i];
    }
    sort(k, k+n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(p=0;p<n;p++){
                q = m-k[i]-k[j]-k[p];
//                if(binary_search1(p,n))
//                    f = true;
                if(binary_search(k, k+n, q))
                    f=true;
            }
        }
    }
    if(f)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
    
    
}
*/




