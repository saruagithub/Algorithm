//
//  MostLongUpstairsSequence.cpp
//  test
//
//  Created by wangxue on 17/5/19.
//  Copyright © 2017年 wangxue. All rights reserved.
//
/*#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n,i,j=0,res=0;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    if(n==1){
        cout<<"1"<<endl;
        return 1;
    }
    while (j<n) {
        if(A[j]< A[j+1]){
            while (A[j]< A[j+1]) {
                j++;
                if(j == n-1)
                    break;
            }
            res++;
            if(j!=n-1){
                j++;
                if(j == n-1)
                    break;
            }
        }
        
        if(j == n-1)
            break;
    }
    cout<<res<<endl;
    return 0;
}
*/
