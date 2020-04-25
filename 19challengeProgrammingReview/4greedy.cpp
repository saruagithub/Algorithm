//
//  4greedy.cpp
//  test
//
//  Created by wangxue on 2/20/19.
//  Copyright © 2019 wangxue. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin>>N;
    char S[N];
    cin>>S;
    int a = 0, b = N-1;
    while (a<=b) {
        bool left = false;
        for (int i = 0; a+i <= b; i++) {
            if (S[a+i] < S[b-i]) {
                left = true;
                break;
            }
            else if(S[a+i] > S[b-i]){
                left = false;
                break;
            }
        }
        if (left) {
            putchar(S[a++]);
        }
        else putchar(S[b--]);
    }
    putchar('\n');
}
*/
