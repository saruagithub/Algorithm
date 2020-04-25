//
//  MakeTeam.cpp
//  test
//
//  Created by wangxue on 17/5/19.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n,i,res=0;
    cin>>n;
    int A[3*n];
    for(i=0;i<3*n;i++){
        cin>>A[i];
    }
    sort(A, A+3*n);
//    for(i=0;i<3*n;i++){
//        for(j=3*n-1;j>i;j--){
//            if(A[j] < A[j-1]){
//                int temp = A[j];
//                A[j] = A[j-1];
//                A[j-1] = temp;
//            }
//        }
//    }
    for(i=1;i<=n;i++){
        res += A[3*n-2*i];
    }
    cout<<res<<endl;
    return 0;
}
*/
