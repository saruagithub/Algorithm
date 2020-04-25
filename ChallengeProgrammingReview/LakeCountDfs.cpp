//
//  LakeCount.cpp
//  test
//
//  Created by wangxue on 17/5/11.
//  Copyright © 2017年 wangxue. All rights reserved.
//

//reference

/*#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int max_N = 50;
const int max_M = 50;
int N,M;
char field[max_N][max_M];

void dfs(int x,int y){
    //replace the w into .
    field[x][y] = '.';
    int dx,dy;
    //for check the 8 direction
    for(dx=-1;dx<=1;dx++){
        for(dy=-1;dy<=1;dy++){
            int nx = x + dx;
            int ny = y + dy;
            //whether in the field and whether has water
            if(nx>=0 && nx<N && ny>=0 && ny<=M && field[nx][ny] == 'w')
                dfs(nx, ny);
        }
    }
}

int main()
{
    cin>>N>>M;
    int i,j,res = 0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin>>field[i][j];
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(field[i][j] == 'w'){
                //start from where is 'w'
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d",res);
    return 0;
}
*/
