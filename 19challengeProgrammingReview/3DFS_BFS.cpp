//
//  DFS_BFS.cpp
//  test
//
//  Created by wangxue on 10/15/18.
//  Copyright © 2018 wangxue. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
//for Q1
const int MAX_N = 100;
int n, k, a[MAX_N];

bool dfs(int i, int sum){
    if (i == n) {
        return sum == k;
    }
    //not add a[i]
    if (dfs(i+1, sum)) {
        return true;
    }
    if (dfs(i+1, sum+a[i])) {
        return true;
    }
    return false;
}

//for Q2
const int INF = 100000000;
typedef pair<int, int> P;


int main(){
    //Q1
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    if (dfs(0, 0)) {
        printf("YES");
    }
    else{
        printf("NO");
    }
    
    //Q2
    int N,M; cin>>N>>M;
    char maze[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>maze[i][j];
        }
    }
    int sx,sy; //start coordinate
    int gx,gy; //end coordinate
    cin>>sx>>sy>>gx>>gy;
    
    int dis[N][M];
    //four directions
    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    
    //bfs
    queue<P> que;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            dis[i][j] = INF;
        }
    }
    que.push(P(sx,sy));
    dis[sx][sy] = 0;
    
    while (que.size()) {
        P p=que.front(); que.pop(); //get value
        if (p.first == gx && p.second == gy) {
            break;
        }
        //four directions
        for(int i=0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            //whether can move whether visited
            if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny] != '#' && dis[nx][ny] == INF){
                que.push(P(nx,ny));
                dis[nx][ny] = dis[p.first][p.second] + 1;
            }
        }
    }
    printf("min distance is:",dis[gx][gy]);
    
}
 */
