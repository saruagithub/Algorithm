//
//  main1.cpp
//  test
//
//  Created by wangxue on 17/4/28.
//  Copyright © 2017年 wangxue. All rights reserved.
//

//排序，最小的俩大于第三者吗？ 快速排序

/*#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,i,j,k,res=0;
    cout<<"n = ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
                if(i!=j && j!=k && i!=k){
                    if(a[i]+a[j] > a[k] && a[k]+a[j] > a[i] && a[i]+a[k] > a[j] && (a[i] + a[j] + a[k])>res)
                        res = a[i] + a[j] + a[k];
                }
            }
        }
    }
    cout<<res;
}
*/
