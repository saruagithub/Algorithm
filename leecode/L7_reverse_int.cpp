//
//  L7_reverse_int.cpp
//  test
//
//  Created by wangxue on 2019/12/26.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// // lecode 8, mind overflow
int reverse(int x) {
    stack<int> reverseData;
    int res=0;
    bool flag = false;
    if (x<0) {
        flag = true;
        x = -x;
    }
    while (x != 0) {
        reverseData.push(x % 10);
        x = x / 10;
    }
    int i=1;
    while (!reverseData.empty()) {
        res = res + i * reverseData.top();
        reverseData.pop();
        i = i * 10;
    }
    if (flag == true) {
        return -res;
    }
    return res;
}

int reverse2(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            // overflow 2147483647, -2147483648
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
}

// leecode 9 O(log10(n))
bool IsPalindrome(int x) {
    if (x < 0 || (x%10==0 && x!=0)) {
        return false;
    }
    int revertNum = 0;
    while (x > revertNum) {
        revertNum = revertNum * 10 + x%10;
        x /= 10;
    }
    // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
    // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
    // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    return x == revertNum || x == revertNum/10;
}

//leecode 14 longestCommonPrefix
string longestCommonPrefix(vector<string>& strs){
    if (strs.size() == 0) {
        return "";
    }
    string prefix = strs[0];
    for(int i=1;i<strs.size();i++){
        //如果不含有prefix，则将prefix长度减1
        while (strs[i].find(prefix) != 0) {
            if (prefix == "") {
                return "";
            }
            prefix = prefix.substr(0,prefix.length() - 1);
        }
    }
    return prefix;
}

int main_L7(){
    cout<<reverse(21474836472121)<<endl;
    cout<<reverse(7463847412)<<endl;
    return 0;
}
