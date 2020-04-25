//
//  6test.cpp
//  Algorithm
//
//  Created by wangxue on 2020/3/27.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//是否所有ai都是小于2的，无论怎么都无法匹配上
bool notmatch(vector<int> sock){
    for(auto num: sock){
        if (num >= 2) {
            return false;
        }
    }
    return true;
}

vector<int> match_sock(vector<vector<int>>& socks){
    vector<int> res;
    for(auto once_all_sock: socks){
        if (notmatch(once_all_sock)) {
            res.push_back(-1);
            continue;
        }
        // 除去ai 中0的个数
        int count = 0;
        for (auto num: once_all_sock) {
            if (num == 0) {
                count++;
            }
        }
        res.push_back(once_all_sock.size()+1-count);
    }
    return res;
}

int main_socks(){
    int TestGroup;
    cin>>TestGroup;
    vector<vector<int>> socks;
    
    for (int i=0; i<TestGroup; i++) {
        int len;
        cin>>len;
        vector<int> temp;
        for (int j=0; j<len; j++) {
            int ai = 0;
            cin>>ai;
            temp.push_back(ai);
        }
        socks.push_back(temp);
    }
    
    vector<int> res;
    res = match_sock(socks);
    for(auto num:res){
        cout<<num<<endl;
    }
    return 0;
}

