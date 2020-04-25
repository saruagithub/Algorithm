//
//  168week_competition.cpp
//  test
//
//  Created by wangxue on 2019/12/22.
//  Copyright © 2019 wangxue. All rights reserved.
//  leecode week competition168

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

//find the count that bitset is even
int findNumbers(vector<int>& nums) {
    int res=0;
    for(auto num: nums){
        int weishu=1;
        while(num / 10 !=0){
            weishu ++;
            num = num / 10;
        }
        cout<<weishu<<endl;
        if(weishu % 2 == 0){
            res ++;
        }
    }
    return res;
}

// array is split as k groups, each group is continuous
bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) {
        return false;
    }
    
    sort(nums.begin(), nums.end());
    map<int,int> hash;
    for(auto num:nums) hash[num]++;
    //group nums
    for (int i=0; i<nums.size() / k; i++) {
        int min_index = 0;
        while (hash[nums[min_index]] == 0) {
            min_index++;
        }
        //if min~min+k is not in nums, false
        int start = nums[min_index];
        for (int j=start; j<start+k; j++) {
            if (hash[j] == 0) {
                return false;
            }
            else hash[j]--;
        }
    }
    return true;
}

bool isPossibleDivide2(vector<int>& nums, int k) {
    if (nums.size() % k != 0) {
        return false;
    }
    multiset<int> s;
    for(auto num:nums) s.insert(num);
    for (int i=0; i<nums.size() / k; i++) {
        int min = *s.begin();
        for (int j=min; j<min+k; j++) {
            if (s.find(j) == s.end()) {
                return false;
            }
            s.erase(s.find(j));
        }
    }
    return true;
}

int main168(){
//    vector<int> test1 = {12,345,2,6,7896};
//    int res1 = findNumbers(test1);
//    cout<<res1<<endl;
    vector<int> test2 = {1,2,3,2,3,3,4,4,5,9,10,11};
    int res2 = isPossibleDivide(test2,3);
    cout<<res2<<endl;
    return 0;
}
