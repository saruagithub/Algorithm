
//
//  4StackAndQueue.cpp
//  test
//
//  Created by wangxue on 2019/12/29.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

//leecode100-20 有效的括号：括号匹配
bool isMatch(char s1,char s2){
    if ((s1 == '(' && s2==')') || (s1 == '[' && s2==']') || (s1 == '{' && s2=='}')){
        return true;
    }
    else return false;
}

bool isValid(string s){ // t:O(n) s:O(n)
    if (s == "") {
        return true;
    }
    stack<char> sta;
    if (s.size()%2 == 1) return false;
    for (int i=0; i<s.size(); i++) {
        if (sta.empty()) {
            sta.push(s[i]);
            continue;
        }
        if(isMatch(sta.top(), s[i])){
            sta.pop();
            continue;
        }
        sta.push(s[i]);
    }
    return sta.empty();
}

int main_4stack(){
    cout<<isValid("}(")<<endl;
    return 0;
}
