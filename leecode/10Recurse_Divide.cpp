//
//  10Divide_Conquer.cpp
//  Algorithm
//
//  Created by wangxue on 2020/3/23.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

// 二分搜索也算是分治思想

// leecode 84：柱状图中的最大矩形，递归方法容易超时 平均时间O(nlogn)，空间复杂度O(n)
int calculateArea(vector<int>& height,int start, int end){
    if (start > end) {
        return 0;
    }
    int minindex = start;
    for (int i=start; i<=end; i++) {
        if (height[minindex] > height[i]) {
            minindex = i;
        }
    }
    return max(height[minindex]*(end-start+1) ,max( calculateArea(height,start,minindex-1), calculateArea(height,minindex+1,end)) );
}

int largestRectangleArea(vector<int>& height){
    return calculateArea(height, 0, height.size()-1);
}


int main_recurse(){
    vector<int> nums = {2,1,5,6,2,3};
    cout<<largestRectangleArea(nums)<<endl;
    return 0;
}
