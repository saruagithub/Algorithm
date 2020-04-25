//
//  2MinInRotateArr.cpp
//  test
//
//  Created by wangxue on 2019/12/24.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// the array in sort ascending rotate in a unknowed data
//[0，1，2，4，5，6，7] to [4，5，6，7，0，1，2]
// time O(logN), space O(1)
// 11,P83

int findMin(vector<int>& nums){
    int low = 0;
    int high = nums.size() -1;
    while (low < high) {
        if (nums[low] < nums[high]) {
            return nums[low];
        }
        int mid = low + (high-low) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return nums[low];
}

int findMin2(int nums[],int length){ // pass the parameter
    if (nums==nullptr || length <= 0) {
        return -1;
    }
    int low = 0;
    int high = length - 1;
    while (low < high) {
        if (nums[low] < nums[high]) {
            return nums[low];
        }
        int mid = low + (high-low) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        }
        else high = mid;
    }
    return nums[low];
}


int mainS2(){
    vector<int> a = {0,1,2,3,4,5};
    cout<<findMin(a)<<endl;
    return 0;
}
