//
//  3Str.cpp
//  test
//
//  Created by wangxue on 2019/11/6.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0") return b;
        if (b == "0") return a;
        if (a==b && a=="0") return "0";
        string long_s,short_s,s_res(long_s.length()+1,'0');
        long_s = a.length()>=b.length()? a:b;
        short_s = a.length()<b.length()? a:b;
        for (int i=short_s.length()-1; i>=0; i++) {
            if ((long_s[i] - '0') + (short_s[i] - '0') < 2) {
                //s_res[i] = to_string((long_s[i] - '0') + (short_s[i] - '0'))
                
            }
        }
        return long_s;
    }
};

//leecode 100,76 最小覆盖子串，滑动窗口思想
//初始，leftleft指针和rightright指针都指向SS的第一个元素.
//将 rightright 指针右移，扩张窗口，直到得到一个可行窗口，亦即包含TT的全部字母的窗口。
//得到可行的窗口后，将lefttleftt指针逐个右移，若得到的窗口依然可行，则更新最小窗口大小。
//若窗口不再可行，则跳转至 2
// t: O(M+N) M代表S的长度，之后的两个whilewhile循环最多执行2M次

string minWindow(string s,string t){
    // 记录最短子串的开始位置和长度，好返回result
    int start=0, minLength = INT_MAX;
    int left = 0,right=0;
    
    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    for (char c : t) needs[c]++;

    int match = 0; // 记录 window 中已经有多少字符符合要求了
    
    while (right < s.size()) {
        char c1 = s[right];
        if (needs.count(c1)) {
            window[c1]++; //添加窗口
            if (window[c1] == needs[c1]) {
                match++;
            }
        }
        right++;
        //窗口符合t要求，移动 left 缩小窗口
        while (match == needs.size()) {
            // 如果这个窗口的子串更短，则更新 res
            if (right - left < minLength) {
                // 更新最小子串的位置和长度
                start = left;
                minLength = right - left;
            }
            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2]) {
                    match--;
                }
            }
            left++;
        }
    }
    return minLength == INT_MAX ? "": s.substr(start,minLength);
}

//leecode 438
bool match(string s1,string s2){ //s1和s2含有的字符相同
    unordered_map<char, int> ss1;
    unordered_map<char, int> ss2;
    for (char c : s1) ss1[c]++;
    for (char c : s2){
        if (ss1.count(c) == 0 || ss1[c]==0) {
            return false;
        }
        else ss1[c]--;
    }
    return true;
}

vector<int> findAnagrams(string s,string p){
    vector<int> res;
    for (int i=0; i<s.size(); i++) {
        string temp = s.substr(i,p.size());
        if (match(temp, p)) {
            res.push_back(i);
        }
    }
    return res;
}

int main_str(){
    /*
    string s0 = "1";
    string s1 = "11";
    string s2 = s1;
    string s3;
    string s4(10, '1');
    cout<<s1.length()<<s2<<s3<<s4<<'\n'<<stoi(s4)<<endl;
    //Solution s;
    //s3 = s.addBinary(s0, s1);
    int aa;
    aa = s0[0]-'0';
    cout<<aa<<endl;
    
    int a[5];
    int a1[5] = {1,2,3};
    int size=sizeof(a1)/sizeof(*a1);
    cout<<"sizeof"<<sizeof(*a1)<<" "<<sizeof(a1)<<size<<endl;
     */
    
    //string S = "ADOBECODEBANC", T = "ABC";
    //cout<<minWindow(S,T);
    
    string s = "cbaebabacd" ,p= "abc";
    vector<int> res;
    res = findAnagrams(s,p);
    for(auto r: res) cout<<r<<endl;
    return 0;
}
