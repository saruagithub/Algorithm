//
//  7wood.cpp
//  Algorithm
//
//  Created by wangxue on 2020/3/29.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//题目2
void wood(){
    int TestGroup;
    cin>>TestGroup;
    int result[TestGroup];
    //input
    for (int i=0; i<TestGroup; i++) {
        int len;
        cin>>len;
        int bangbang[2][len];
        for (int j=0; j<2; j++) {
            for (int k=0; k<len; k++) {
                int temp = 0;
                cin>>temp;
                bangbang[j][k] = temp;
            }
        }
        //calculate group
        int res = 0;
        for (int j=0; j<len; j++) {
            res++;
            for (int k=0; k<len; k++) {
                if ((j!=k) && bangbang[0][j]!=0  && bangbang[0][j] <= bangbang[0][k] && bangbang[1][j] <= bangbang[1][k]) {
                    res--;
                    bangbang[0][j] = 0;
                    bangbang[1][j] = 0;
                    break;
                }
            }
        }
        result[i] = res;
    }
    for(int i=0;i<TestGroup;i++) cout<<result[i]<<endl;
}

int main_wood(){
    wood();
    return 0;
}
