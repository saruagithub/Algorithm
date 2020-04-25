//
//  10stack_heap.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/26.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack{
public:
    stack<int> data_stk;
    stack<int> min_stk;
    MinStack(){}
    
    void push(int x){
        data_stk.push(x);
        if(min_stk.empty() || x < min_stk.top()){
            min_stk.push(x);
        }
        else min_stk.push(min_stk.top());
    }
    
    void pop(){
        assert(!data_stk.empty() && !min_stk.empty());
        data_stk.pop();
        min_stk.pop();
    }
    
    int top(){
        assert(!data_stk.empty());
        return data_stk.top();
    }
    
    int getMin(){
        assert(!data_stk.empty() && !min_stk.empty());
        return min_stk.top();
    }
};

class MinStack1 {
public:
    /** initialize your data structure here. */
    MinStack1() {}
    
    void push(int x) {
        if(x < min) {
            min = x;
        }

        minStack.push(make_pair(min, x));
    }
    
    void pop() {
        minStack.pop();
        if (minStack.empty()) {
            min = INT_MAX;
        } else {
            min = minStack.top().first;
        }
    }
    
    int top() {
        return minStack.top().second;
    }
    
    int getMin() {
        return minStack.top().first;
    }

private:
    int min = INT_MAX;
    stack<pair<int, int>> minStack;
};

int main_stack_heap(){
    MinStack minStack;
    minStack.push(-2);
    cout<<minStack.getMin()<<endl;
    minStack.pop();
    cout<<minStack.top()<<endl;
    cout<<minStack.getMin()<<endl;
    return 0;
}

// -----------------------------------------

//leecode 84：柱状图中的最大矩形 ,递增stack方法解 t:O(n), space:O(n)
//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode/

int largestRectangleArea1(vector<int>& height){
    stack<pair<int, int>> stk;
    int area = 0;
    //init -1 at the bottom
    stk.push(make_pair(-1, -1));
    for(int i=0;i<height.size();i++){
        if (height[i] > stk.top().second) {
            stk.push(make_pair(i, height[i]));
        }
        else{
            while (stk.top().second >= height[i]) {
                pair<int, int> temp;
                temp = stk.top();
                stk.pop();
                int temp_area = temp.second * (i - stk.top().first - 1);
                if(temp_area > area) area = temp_area;
            }
            stk.push(make_pair(i, height[i]));
        }
    }
    while (stk.top().first != -1) {
        pair<int, int> temp;
        temp = stk.top();
        stk.pop();
        int temp_area = temp.second * (height.size() - stk.top().first - 1);
        area = max(area, temp_area);
    }
    return area;
}

int largestRectangleArea2(vector<int>& height){
    stack<int> stk;
    stk.push(-1);
    int area = 0;
    for (int i=0; i<height.size(); i++) {
        while (stk.top()!=-1 && height[stk.top()] >= height[i]) {
            int temp = stk.top();
            stk.pop();
            area = max(area,height[temp]*(i-stk.top() - 1));
        }
        stk.push(i);
    }
    while (stk.top() != -1){ //last ont: increasing case
        int temp = stk.top();
        stk.pop();
        int temp_area = height[temp] * (height.size() - stk.top() - 1);
        area = max(area,temp_area);
    }
    return area;
}

int main_heap_stack(){
    vector<int> nums ={2,3}; //{6,7,5,2,4,5,9,3};
    cout<<largestRectangleArea2(nums)<<endl;
    return 0;
}
