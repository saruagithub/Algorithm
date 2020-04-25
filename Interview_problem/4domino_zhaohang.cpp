//
//  4domino.cpp
//  Algorithm
//
//  Created by wangxue on 2020/3/26.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 多米诺骨牌 https://www.nowcoder.com/question/next?pid=13669288&qid=285265&tid=31959493
// left save the last elem 'L' or 'R'
// i go next
void domino(string s){
    cout<<s<<endl;
    int i = 0;
    pair<int, char> left;
    left.first = 0;
    left.second = s[0];
    // right is i
    while (s[i]!='\0') {
        if (s[i] == 'L') {
            //L ... L
            if (left.second == 'L') {
                for (int j=left.first+1; j<i; j++) {
                    s[j] = 'L';
                }
            }
            //R...L
            else if (left.second == 'R') {
                if ((i - left.first) > 2) {
                    int mid = left.first + (i-left.first)/2;
                    for (int j=left.first+1; j<mid; j++) {
                        s[j] = 'R';
                    }
                    for (int j=mid+1; j<i; j++) {
                        s[j] = 'L';
                    }
                    if ((i - left.first)%2 == 1) s[mid] = 'R';
                }
            }
            //....L
            else{
                for (int j=left.first; j<i ; j++) {
                    s[j] = 'L';
                }
            }
            left.first = i;
            left.second = s[i];
        }
        
        // R...R
        if (s[i] == 'R') {
            if (left.second == 'R') {
                for (int j=left.first+1; j<i; j++) {
                    s[j] = 'R';
                }
            }
            left.first = i;
            left.second = s[i];
        }
        // R ....
        if (s[i] == '.' && i==(s.size()-1)) {
            if (left.second == 'R') {
                for (int j=left.first+1; j<=i;j++) {
                    s[j] = 'R';
                }
            }
        }
        i++;
    }
    cout<<s<<endl;
    return;
}

int main_domino(){
    string s = "";
    //string s = ".L....L....";
    domino(s);
    return 0;
}
