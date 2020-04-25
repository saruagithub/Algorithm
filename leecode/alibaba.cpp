//
//  alibaba.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/21.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

string add(string num1, string num2) {
    // 存储进位
    unsigned int bit = 0;
    // 得到两个数的长度
    unsigned n1 = num1.size()-1, n2 = num2.size()-1;
    // 保存结果
    string result = "";
    while (n1 >= 0 && n2 >= 0) {
        // 求两数每一位之和
        unsigned int temp = (num1[n1] - '0') + (num2[n2] - '0') + bit;
        // 计算进位
        bit = int(temp / 10);
        result = to_string(temp % 10) + result;
        if (n1==0 || n2==0) {
            break;
        }
        n1--;
        n2--;
    }
    // n1==n2==0
    if(n1 == n2) return to_string(bit)+result;
    // 更长的数多余的部分
    string prev = n1 > n2 ? num1.substr(0, n1) : num2.substr(0, n2);
    // 可能存在进位
    string last = to_string(prev[prev.size() - 1] - '0' + bit);
    // 加到结果的最前面
    result = prev.substr(0, prev.size()-1) + last + result;
    return result;
}

// 场景: 微信群聊中,每个人都有未读消息和已读消息,
//  如何设计提供每个人显示多少未读消息且能快速找到具体的未读消息
//  (假设是一周时间段,如果是群人数有限和群人数无限)?
//  请使用 最少的存储空间和最快速的查找算法 来解决.
// 思路：hash的key是人的id，value是未读消息stack
//（最近未读的消息存在top，手机上不是有点击数字回到最近未读的消息嘛，
// 每次倒回到最近未读的消息处，不断取出top()

void insert_msg(string uid,string msg,
                unordered_map<string,stack<string>>& msg_queue){
    
    unordered_map<string,stack<string>>::iterator it;
    if ((it = msg_queue.find(uid)) != msg_queue.end()) {
        // insert into the msg stack of uid
        it->second.push(msg);
    }
    else{
        stack<string> sta_temp;
        sta_temp.push(msg);
        msg_queue.insert(make_pair(uid,sta_temp));
    }
    return;
}

pair<int,string> find_recent_unread_msg(string uid,unordered_map<string,stack<string>>& msg_queue){
    unordered_map<string,stack<string>>::iterator it;
    if ((it = msg_queue.find(uid)) != msg_queue.end()) {
        pair <int,string> msg_temp;
        msg_temp.first = it->second.size();
        msg_temp.second = it->second.top();
        it->second.pop();
        return msg_temp;
    }
    else {
        throw "No user";
    }
}

int main_alibaba()
{
    //题目4
    int nums[] = {123,234,345};
    string ans = "0";
    for (unsigned int i=0; i < sizeof(nums)/sizeof(int); i++) {
        ans = add(ans, to_string(nums[i]));
    }
    cout << ans << endl;
    
    
    
    // 题目5
    string msg; // one unread msg including time t, string msg
    stack<string> unread_msg; // all msg of one user
    unordered_map<string,stack<string>> msg_queue;//all msg for all user
    // 如果是要更快的找到每一条消息，可将stack换为hash(key: time ,value: message)
    
    // for insert
    string uid = "u1";
    string message = "在吗";
    insert_msg(uid,message,msg_queue);
    
    pair<int,string> res;
    res = find_recent_unread_msg(uid,msg_queue);
    cout<<res.first<<","<<res.second<<endl;
    return 0;
}
