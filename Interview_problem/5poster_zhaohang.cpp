//
//  5poster_zhaohang.cpp
//  Algorithm
//
//  Created by wangxue on 2020/3/27.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <climits>

#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;

//贴海报 https://www.nowcoder.com/question/next?pid=13669288&qid=285265&tid=31959493
// i poster all is coverd by j, then return true
bool cover(int posters[][2],int i,int j){
    if (posters[i][0] >= posters[j][0] && posters[i][1] <= posters[j][1]) {
        return true;
    }
    else return false;
}

int seePosters(int posters[][2],int rows){
    int res = 0;
    for (int i=0; i<rows; i++) {
        res++;
        for (int j=i+1; j<rows; j++) {
            if (cover(posters, i, j)) {
                res--;
                break;
            }
        }
    }
    return res;
}

int seePosters1(int posters[][2],int rows){
    int res = 0;
    for (int i=0; i<rows; i++) {
        res++;
        int min=INT_MAX,max=INT_MIN;
        for (int j=i+1; j<rows; j++) {
            if (posters[j][0]<min)  min = posters[j][0];
            if (posters[j][1]>max)  max = posters[j][1];
            if (posters[i][0] >= min && posters[i][1] <= max) { //coverd by later
                res--;
                break;
            }
        }
    }
    return res;
}

//模拟插入过程
int mp[10000001] ={0};
int main_key_poster(){
    int n;
    cin>>n;
    int x,y;
    for(int i = 1; i <= n; ++i){
        cin>>x>>y;
         for(int j = x;j <= y; ++j){
             mp[j] = i;
         }
    }
    set<int> num;
    for(int& k : mp){
        if(k>0) num.insert(k);
    }
    cout<<num.size()<<endl;
    return 0;
}

/*
//求逆序对数
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, i, j, ans = 0, temp;
    cin >> n;
    vector<int> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            if(a[j] > a[i])
                ans++;
    cout << ans << endl;
    return 0;
}*/


int main_5poster(){
    /*
    int N;
    cin>>N;
    int posters[N][2];
    for (int i=0; i<N; i++) {
        cin>>posters[i][0];
        cin>>posters[i][1];
    }*/
    //int posters[5][2]  = {{1,4},{2,6},{8,10},{3,4},{7,10}};
    int posters[10][2]  = {{81,84},{27,85},{12,91},{27,78},{25,36},{24,68},{27,32},{8,59},{33,91},{0,49}};
    cout<<seePosters1(posters,10)<<endl;
    return 0;
}
