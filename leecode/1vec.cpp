//
//  1vec.cpp
//  test
//
//  Created by wangxue on 2019/10/24.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main0000() {
    // 1. initialize
    vector<int> v0;
    vector<int> v1(5, 0);
    // 2. make a copy
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);
    // 2. cast an array to a vector
    int a[5] = {0, 1, 2, 3, 4};
    vector<int> v4(a, *(&a + 1));
    cout<<  *(&a + 1);
    // 3. get length
    cout << "The size of v4 is: " << v4.size() << endl;
    // 4. access element
    cout << "The first element in v4 is: " << v4[0] << endl;
    // 5. iterate the vector
    cout << "[Version 1] The contents of v4 are:";
    for (int i = 0; i < v4.size(); ++i) {
        cout << " " << v4[i];
    }
    cout << endl;
    cout << "[Version 2] The contents of v4 are:";
    for (int& item : v4) {
        cout << " " << item;
    }
    cout << endl;
    cout << "[Version 3] The contents of v4 are:";
    for (auto item = v4.begin(); item != v4.end(); ++item) {
        cout << " " << *item;
    }
    cout << endl;
    // 6. modify element
    v4[0] = 5;
    // 7. sort
    sort(v4.begin(), v4.end());
    // 8. add new element at the end of the vector
    v4.push_back(-1);
    // 9. delete the last element
    v4.pop_back();
    return 0;
}

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum0=0,sum1=0;
        for (int i = 0; i < nums.size(); ++i) {
            sum0 += nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            sum0 -= nums[i];
            if (sum1==sum0) {
                return i;
            }
            sum1 += nums[i];
        }
        return -1;
    }
};

class Solution1 {
public:
    int dominantIndex(vector<int>& nums) {
        int max=0,less_max=0,index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                less_max = max;
                max = nums[i];
                index = i;
            }
        }
        if(max >= 2*less_max){
            return index;
        }
        else return -1;
    }
};

class Solution3 {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            digits[i] += 1;
            if(digits[i] < 10) return digits;
            else{
                digits[i] = digits[i]%10;
                if (i==0) {
                    vector<int> res;
                    res.push_back(1);
                    res.insert(res.end(),digits.begin(),digits.end());
                    return res;
                }
                continue;
            }
        }
        return digits;
    }
};

// leecode100-48 顺时针旋转90度，在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。
// 先转置矩阵，然后翻转每一行。
// https://leetcode-cn.com/problems/rotate-image/solution/zhi-xing-yong-shi-ji-bai-liao-100de-yong-hu-jie-fa/

void rotate(vector<vector<int>>& matrix){
    int temp = -1;
    for (int start=0, end=matrix.size()-1; start<end; start++, end--){
        for(int s=start,e=end;s<end;s++,e--){
            temp=matrix[start][s];
            matrix[start][s]=matrix[e][start];
            matrix[e][start]=matrix[end][e];
            matrix[end][e]=matrix[s][end];
            matrix[s][end]=temp;
        };
    }
}


int main_1vec(){
    int num;
    vector<int> nums;
    while(cin>>num)
       {
           nums.push_back(num);
           if (getchar() == '\n') //遇回车结束
               break;
       }
     
    Solution3 solv;
    vector<int> res;
    res = solv.plusOne(nums);
    for(auto n:res) cout<<n<<endl;
    return 0;
}



