//
//  maze.c
//  Cpractice
//
//  Created by wangxue on 17/5/13.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
const int INF = 100000000;
const int max_N = 100;
typedef std::pair<int,int> P;
using namespace std;


int main()
{
    //for input
    char maze[max_N][max_N];
    int N,M,sx,sy,gx,gy,i,j,res;
    int d[max_N][max_N];  //to all locaions min distance
    int dx[4] = {1,0,-1,0},dy[4]={0,1,0,-1};
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%c",&maze[i][j]);
            if(maze[i][j] == 's'){
                sx = i;
                sy = j;
            }
            if(maze[i][j] == 'g'){
                gx = i;
                gy = j;
            }
        }
    }
    cout<<sx<<sy<<gx<<gy<<endl;
    
    //calculate
    std::queue<P> que;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            d[i][j] = INF;
        }
    }
    que.push(P(sx,sy)); //start dot add into queue
    d[sx][sy] =0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second== gy)
            break;
        //four directions
        for(i=0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            //whether can move whether visited
            if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    res = d[gx][gy];
    printf("%d",res);
    return 0;
}

*/









