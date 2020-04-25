//
//  LakeCounting.cpp
//  test
//
//  Created by wangxue on 17/5/3.
//  Copyright © 2017年 wangxue. All rights reserved.
//


//wrong
/*#include <stdio.h>
#include <iostream>
#include <iostream>
using namespace std;
const int max_N=50;

int N,M,sum=0;
char field[max_N][max_N];

bool Comp(int row,int begin){
    int i;
    for (i=0; i<8; i++) {
        if(field[row][begin+i] != '.'){
            //cout<<"i false"<<begin<<" "<<i<<" "<<field[row][begin+i]<<endl;
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>N>>M;
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin>>field[i][j];
        }
    }
    
    for(i=0;i<N;i++){
        for(j=0;j<4;j++){
            if(Comp(i, j)){
                sum++;
                //cout<<sum<<" "<<i<<" "<<j;
                break;
            }
        }
    }
    
    cout<<sum<<endl;
    return 0;
}
*/


