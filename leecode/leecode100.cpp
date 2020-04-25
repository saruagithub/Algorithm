//
//  leecode100.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/9.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


// leecode3 不含有重复字符的 最长子串 的长度。
int lengthOfLongestSubstring(string s) {
    // 两重遍历的set方法
    /*
    set<char> longestSubstring;
    int res = 0;
    for(int i=0;i<s.length();i++){
        for (int j=i; j<s.length(); j++) {
            if(longestSubstring.count(s[j]) == 0){
                longestSubstring.insert(s[j]);
                if(longestSubstring.size() > res) res = longestSubstring.size();
            }
            else{
                longestSubstring.clear();
                break;
            }
        }
        
    }*/
    //通过使用 HashSet 作为滑动窗口，我们可以用 O(1)的时间来完成对字符是否在当前的子字符串中的检查。
    int sl = s.length();
    unordered_map<char,int> longestSubstring;
    int res=0,i=0,j=0;
    while (i<sl && j<sl) {
    }
    return 0;
}

// leecode100-10, 正则表达式匹配
bool isMatch(string s,string p){
    // dp[i][j] means that s 的前i个能否被p的前j个匹配
    int sl = s.length();
    int pl = p.length();
    if(p.empty()) return s.empty();
    // init
    int dp[sl+1][pl+1];
    for (int i=0; i<=sl; i++) {
        for (int j=0; j<=pl; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;//dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
    for (int j=1; j<=pl; j++) {
        if (p[j] == '*' && dp[0][j - 1]) {
            dp[0][j + 1] = 1; // here's y axis should be i+1
        }
    }
    for (int i=0; i<sl; i++) {
        for (int j=0; j<pl; j++) {
            if (s[i] == p[j] || p[j] == '.') {
                dp[i+1][j+1] = dp[i][j];
            }
            if(p[j]=='*'){
                if(p[j-1]!=s[i] && p[j - 1] != '.') dp[i+1][j+1] = dp[i+1][j-1]; //如果前一个元素不匹配且不为任意元素
                else dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
            }
        }
    }
    return dp[sl][pl];
}

int main_L100_10(){
    string s = "mississippi";
    string p = "mis*is*p*.";
    cout<<isMatch(s,p)<<endl;
    return 0;
}


//leecode100-11 盛水最多的容器
int maxArea(vector<int>& height){
    if (height.empty()) {
        return 0;
    }
    // easy way O(n^2)
    /*
    int len = height.size();
    int maxArea = 0,area=0;
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            area = (j-i) * min(height[i], height[j]);
            if( area > maxArea) maxArea = area;
        }
    }
    return maxArea;
    */
    // 双指针法：较短线段的指针向较长线段那端移动一步。
    int maxArea = 0, l = 0, r = height.size()-1;
    while (l < r) {
        maxArea = max(maxArea,min(height[l],height[r]) * (r-l));
        if (height[l] < height[r]) {
            l++;
        }
        else r--;
    }
    return maxArea;
}

// leecode100-15 三数之和
/*
vector<vector<int>> threeSum(vector<int>& nums){
    unordered_map<int, int> hash;
    vector<vector<int>> res;
    vector<int> res_temp;
    // save init
    for(int i=0;i<nums.size();i++){
        for (int j=i+1; j<nums.size(); j++) {
            if(hash.find(nums[j]) == hash.end()){
                hash[nums[j]] = 0 - nums[i] - nums[j];
            }
            else{
                
            }
        }
    }
}
*/

//leecode100-31下一个排列
void swap0(vector<int>& nums,int i,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void reverse0(vector<int>& nums, int start) {
    int i = start, j = nums.size() - 1;
    while (i < j) {
        swap0(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums){
    if (nums.size() <= 1) {
        return;
    }
    //从后向前查找第一个相邻升序的元素对
    int i = nums.size() - 2;
    int k = nums.size() - 1;
    while( i>=0 && nums[i] >= nums[i+1]){
        i--;
    }
    if(i >= 0){
        //find A[i] < A[k]的k
        while (k >=0 && nums[i] >= nums[k]) {
            k--;
        }
        swap0(nums,i,k);
    }
    
    //reverse A[j] to end
    reverse0(nums,i+1);
}

//leecode100-32 最长有效括号 t O(n), s:O(n)
int longestValidParentheses(string s){
    if (s == "" || s=="(" || s==")") {
        return 0;
    }
    int res = 0;
    //init
    int *dp = new int[s.size()];
    for(int i=0;i<s.size();i++) dp[i] = 0;
    //begin 注意边界
    for (int i=1; i<s.size(); i++) {
        if(s[i] == ')'){
            if(s[i-1] == '(' ){
                dp[i] = (i>=2? dp[i-2]:0) + 2;
            }
            else if(i-dp[i-1]>0 && s[i-dp[i-1]-1] == '('){
                dp[i] = dp[i-1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            //update the max
            if (dp[i] > res) {
               res = dp[i];
            }
        }
        // s[i] == '(', dp[i] = 0
        else dp[i] = 0;
    }
    return res;
}

// leecode100-32 stack
int longestValidParentheses1(string s){
    int res = 0;
    stack<int> sta;
    sta.push(-1); // base
    for (int i=0; i<s.size(); i++) {
        if(s[i] == '(') sta.push(i);
        else{
            sta.pop();
            if(sta.empty()) sta.push(i);
            else{
                if((i - sta.top()) > res) res = i - sta.top();
            }
        }
    }
    return res;
}

// leecode100-121
int maxProfit(vector<int>& prices){
    int dp[prices.size()]; // dp[i] 在i元素前面的最小值
    int max = 0;
    memset(dp, 0, prices.size());
    dp[0] = prices[0];
    for (int i=1; i<prices.size(); i++) {
        dp[i] = min(dp[i-1],prices[i]);
    }
    for (int i=0; i<prices.size(); i++) {
        if ((prices[i] - dp[i]) > max) max = prices[i] - dp[i];
    }
    return max;
}

int maxProfit1(vector<int>& prices) {
    if(prices.size() <= 0) return false;
    int minprice = 0x7fffffff;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}

//leecode 283
void moveZeroes(vector<int>& nums) {
    int i=0,j=0;
    for (i=0; i<nums.size(); i++) {
        if(nums[i] == 0 && i!=(nums.size()-1)){
            for (j=i+1; j<nums.size(); j++) {
                if(nums[j] != 0){
                    //change the num
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    break;
                }
                if(j == (nums.size()-1)) return; // all is zero later
            }
        }
    }
}

//leecode100-56 给出一个区间的集合，请合并所有重叠的区间。
vector<vector<int>> merge_overlap(vector<vector<int>>& intervals){
    vector<int> v;
    vector<vector<int>> res;
    if (intervals.empty()) {
        return res;
    }
    sort(intervals.begin(), intervals.end(),[](vector<int> &v1, vector<int> &v2) { return v1[0] < v2[0];});
    for (int i = 0; i < intervals.size(); ++i) {
        vector<int> temp = intervals[i];
        while (i + 1 < intervals.size() && temp[1] >= intervals[i+1][0]) {
            ++i;
            temp[1] = max(temp[1], intervals[i][1]);
        }
        res.push_back(temp);
    }
    return res;
}

//leecode100-75 颜色分类
void sortColors(vector<int>& nums){
    if (nums.size() == 0 || nums.size() == 1) return;
    int p0 = 0,curr = 0;
    int p2 = nums.size()-1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            swap(nums[curr++], nums[p0++]);
        }
        else if(nums[curr] == 2){
            swap(nums[curr],nums[p2--]);
        }
        else curr++;
    }
}

//leecode 581 最短无序连续子数组
int findUnsortedSubarray(vector<int>& nums){
    vector<int> temp;
    temp = nums;
    int lowIndex=0,highIndex=0;
    sort(nums.begin(), nums.end());
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]!=temp[i]) {
            lowIndex = i;
            break;
        }
    }
    for (int j=nums.size()-1; j>=0; j--) {
        if (nums[j]!=temp[j]) {
            highIndex = j;
            break;
        }
    }
    if (lowIndex == 0 && highIndex == 0) {
        return 0;
    }
    return highIndex-lowIndex+1;
}

void findUnsortedSubarray_test(){
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout<<findUnsortedSubarray(nums)<<endl;
}

int main_100(){
    //leecode 3
    //string s = "c";
    //cout<<lengthOfLongestSubstring(s)<<endl;
    
    //vector<int> h = {1,8,6,2,5,4,8,3,7};
    //cout<<maxArea(h)<<endl;
    
    //vector<int> nums = {1,2,3};
    //nextPermutation(nums);
    
    //string ss = ")";
    //cout<<"res:"<<longestValidParentheses1(ss)<<endl;
    
    //vector<int> prices ={7,1,5,3,6,4};
    //cout<<maxProfit(prices)<<endl;
    
    //vector<int> prices ={0,0,1};
    //moveZeroes(prices);
    
    //vector<int> nums = {0,1,0,3,12};
    //moveZeroes(nums);
    
    /* leecode 56
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res;
    res = merge_overlap(nums);
    for(auto res1: res){
        for(auto res2: res1){
            cout<<res2<<",";
        }
        cout<<endl;
    }
     */
    
    /*
    vector<int> nums = {2,2};
    sortColors(nums);
     */
    findUnsortedSubarray_test();
    return 0;
}
//int a[SIZE];
//memset(a, 0, sizeof(a));
//memset(a, 0, sizeof(int)*1000);//这里的1000是数组大小，需要多少替换下就可以了。
