//
//  9hash.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/25.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// leecode100-136
int singleNumber(vector<int>& nums){
    unordered_map<int,int> appear; //key is nums[i], val is the times that num shows
    for (int i=0; i<nums.size();i++) {
        if (appear.find(nums[i]) != appear.end()) appear.erase(appear.find(nums[i]));
        else appear[nums[i]] = 1;
    }
    return appear.begin()->first;
}
// XOR 一个值和0进行按位异或操作所得为该值，相同的两个值进行异或操作，所得为0
int singleNumber1(vector<int>& nums){
    int v=0;
    for (int i=0; i<nums.size();i++) {
        v^=nums[i];
    }
    return v;
}

//leecode100-169 出现次数>n/2的数
int majorityElement(vector<int>& nums){
    unordered_map<int, int> times;
    for (int i=0; i<nums.size(); i++) {
        if(times.find(nums[i]) == times.end()) times[nums[i]] = 1;
        else times[nums[i]]++;
    }
    for (int i=0; i<nums.size(); i++) {
        if (times[nums[i]] > nums.size()/2) return nums[i];
    }
    return -1;
}

// 会在下标为n/2的地方有重叠
int majorityElement1(vector<int>& nums){
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}


//leecode100-49 字母异位词分组 t:O(n) sort处 O(nlog(n)) space: O(n)
vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>> res;
    if (strs.size() == 0) {
        return res;
    }
    unordered_map<string, int> character; // string 字母组合, int 字符串下标
    int count=0;  //结果res vector的下标值，第几个不同的字母组合
    
    for (int i=0; i<strs.size(); i++) {
        string temp;
        temp = strs[i];
        sort(temp.begin(),temp.end());
        if(character.count(temp)){
            res[character[temp]].push_back(strs[i]);
        }
        else{
            vector<string> str(1,strs[i]);
            res.push_back(str);
            character[temp] = count++;
        }
    }
    return res;
}

//leecode100-55 jump game
// i是否可到跟i-1是否可到 + 距离相关
bool canJump1(vector<int>& nums)
{
    int k = 0;//far one to reach
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k) return false;
        k = max(k, i + nums[i]); // i+nums[i]最远可以到达的那个下标
    }
    return true;
}

int main_9hash(){
    vector<int> nums = {2,0};
    //cout<<singleNumber1(nums)<<endl;
    //cout<<majorityElement(nums)<<endl;
    cout<<canJump1(nums)<<endl;
    return 0;
}
