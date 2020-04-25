//
//  DP.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/10.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int maxSequenceSum0(int* matrix, int length){
  if(length < 0) return -1;
  int dp[length];
  dp[0] = 0;
  for(int i=1;i<length;i++){
    dp[i] = max(dp[i-1]+matrix[i], matrix[i]);
  }
  // get the max
  int res = 0;
  for(int i=0;i<length;i++){
    if(dp[i] > res) res = dp[i];
  }
  return res;
}

// optimization
int maxSequenceSum(int* matrix, int length){
  if(length < 0) return -1;
  int dp_max,dp_last;
  dp_max = matrix[0]; // store the max
  dp_last = matrix[0]; // store the dp[i-1]
  for(int i=1;i<length;i++){
    dp_last = max(dp_last + matrix[i], matrix[i]);
    if(dp_last > dp_max) dp_max = dp_last;
  }
  return dp_max;
}

// leecode100-22 括号生成
//既然知道了 i<n 的情况，那我们就可以对所有情况进行遍历 dp[i] 存储的 i对括号的string组合
// "(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】
//简单来说，在求N个括号的排列组合时，把第N种情况（也就是N个括号排列组合）视为单独拿一个括号E出来，剩下的N-1个括号分为两部分，P个括号和Q个括号，P+Q=N-1，然后这两部分分别处于括号E内和括号E的右边，各自进行括号的排列组合。由于我们是一步步计算得到N个括号的情况的，所以小于等于N-1个括号的排列组合方式我们是已知的（用合适的数据结构存储，方便后续调用，且在存储时可利用特定数据结构实现题目某些要求，如排序，去重等），且P+Q=N-1，P和Q是小于等于N-1的，所以我们能直接得到P个和Q个括号的情况，进而得到N个括号的结果！

vector<string> generateParenthesis1(int n){
    if (n == 0) return {};
    if (n == 1) return {"()"};
    vector<vector<string>> dp(n+1);
    dp[0] = { "" };
    dp[1] = { "()" };
    for (int i=2; i<=n; i++) {
        for (int j=0; j<i; j++) {
            for (string p: dp[j]) {
                for (string q: dp[i-j-1]){
                    string str = "(" + p + ")" + q; // string 相加
                    dp[i].push_back(str);
                }
            }
        }
    }
    return dp[n];
}

//vector<vector<int>>
// leecode100-39 多重部分和 DP[i+1][j] 用前i种数字加和成j， 需要前i-1种数字加和成 j，j-a[i], j - k *a[i]
int combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> res_temp;
    int dp[candidates.size()+1][target+1];
    //init
    for(int j=0; j <=target; j++) dp[0][j] = 0;
    dp[0][0] = 1;
    for(int i=0; i< candidates.size();i++){
        for (int j=0; j<= target; j++) {
            for (int k=0; k * candidates[i] <= j; k++) {
                dp[i+1][j] = dp[i][j - k*candidates[i]];
                if(j == target && dp[i+1][j]==1){
                    
                }
            }
        }
    }
    for(int i=0; i<= candidates.size();i++){
        for (int j=0; j<= target; j++) {
            cout<<"i:"<<i<<"j:"<<j<<"dp:"<<dp[i][j]<<endl;
        }
    }
    return dp[candidates.size()][target];
}

// leecode100-42 接雨水
//@laumou 对于vector中每个点，水有多高取决于这个点左侧和右侧墙壁的最大高度。
//第一个for循环找每个点的左侧最大高度，第二个for循环找每个点右侧的最大高度，
//循环中跳过最左侧(i=0)和最右侧点(i=vector.size()-1)的原因是这两个点由于没有左侧墙壁或右侧墙壁所以最大墙壁高度肯定是0，
//故在初始化vector的时候已经将其默认设置成0了。在得到所有点的左右墙壁最大高度后，
//木桶原理取左右墙壁较低的那个高度减去当前位置墙壁作为地面的高度就得到了这个位置上水的高度。然后将所有点的水高度相加即为解

int trap(vector<int>& height){
    if (height.size() <= 2) {
        return 0;
    }
    int n = height.size();
    // left[i]表示i左边的最大值，right[i]表示i右边的最大值
    vector<int> left(n), right(n);
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], height[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], height[i + 1]);
    }
    int water = 0;
    for (int i = 0; i < n; i++) {
        int level = min(left[i], right[i]);
        water += max(0, level - height[i]);
    }
    return water;
}

//leecode100-55 jump game
// i是否可到跟i-1是否可到 + 距离相关
bool canJump(vector<int>& nums){
    if(nums.size() == 1) return true;
    int dp[nums.size()];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i=0; i<nums.size()-1; i++) {
        for (int j=1; j<=nums[i]; j++) { // 可以向后走num[i]步
            if (i+j >= nums.size()) break;
            dp[i+j] = dp[i];
        }
        if (dp[nums.size()-1] == 1) return true;
    }
    return false;
}

//leecode 62 走不同的路径
int uniquePaths(int m, int n) {
    int dp[m+1][n+1]; //到dp[i][j]需要几次
    for (int i=1; i<m+1; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j=1; j<n+1; j++) {
        dp[0][j] = 0;
        dp[1][j] = 1;
    }
    for (int i=2; i<m+1; i++) {
        for (int j=2; j<n+1; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

//leecode 100-64 最小路径和
int minPathSum(vector<vector<int>>& grid){
    auto rows = grid.size();
    auto cols = grid[0].size();
    int dp[rows][cols];

    int sum = 0;
    for (int i=0; i<rows; i++) {
        dp[i][0] = sum + grid[i][0];
        sum = dp[i][0];
    }
    sum = 0;
    for (int j=0; j<cols; j++) {
        dp[0][j] = sum + grid[0][j];
        sum = dp[0][j];
    }
    for (int i=1; i<rows; i++) {
        for (int j=1; j<cols; j++) {
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[rows-1][cols-1];
}

//leecode 72 编辑距离
int minDistance(string word1,string word2){
    auto m = word1.length();
    auto n = word2.length();
    int dp[m+1][n+1];
    for (int i=0; i<=m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
    }
    return dp[m][n];
}

//leecode85 最大矩形，给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
int maximalRectangle(vector<vector<char>>& matrix){
    if (matrix.empty()) {return 0;}
    int maxarea = 0;
    int rows = matrix.size(),cols = matrix[0].size();
    //init
    int dp[rows][cols];
    for (int i=0; i<rows; i++) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
        }
        else dp[i][0] = 0;
    }
    // dp for each row
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (matrix[i][j] == '0') {
                dp[i][j] = 0;
            }
            // compute the maximum width and update dp with it
            if (j>0 && matrix[i][j] == '1'){
                dp[i][j] = dp[i][j-1] + 1;
            }
            
            // compute the maximum area rectangle with a lower right corner at [i, j]
            int width = dp[i][j];
            for (int k = i; k>=0; k--) {
                width = min(width, dp[k][j]);
                maxarea = max(maxarea, width * (i-k+1));
            }
        }
    }
    return maxarea;
}


//leecode96 different BST 以 1 ... n 为节点组成的二叉搜索树有多少种？卡特兰数
//G(n): 长度为n的序列的不同二叉搜索树个数。we want it
//F(i,n): 以i为根的不同二叉搜索树个数(1≤i≤n)。
//不同的二叉搜索树的总数 G(n)，是对遍历所有 i (1 <= i <= n) 的 F(i, n)之和。G(n)=\sum(i=1~n) F(i,n)
//F(i,n)=G(i−1)⋅G(n−i)
// interesting ,T: O(n^2)
int numTrees(int n){
    vector<int> G(n+1,0);
    G[0] = 1;
    G[1] = 1;
    if (n <= 1) {
        return G[n];
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<i/2; j++) {
            G[i] += 2 * (G[j] * G[i-j-1]);//由对称性，可以直接乘以2倍
        }
        if (i % 2 == 1) {
            G[i] += G[i/2] * G[i/2]; //奇数
        }
    }
    return G[n];
}


int main_DP(){
    //int matrix[] = {1,-2,3,1,-1,5}; // n words
    //cout<<maxSequenceSum(matrix,6)<<endl;
    
    //vector<string> res;
    //res = generateParenthesis1(2);
    //for(auto str:res) cout<<str<<endl;
    
    /*
    vector<int> candidates = {2,3,6,7};
    cout<<combinationSum(candidates,6)<<endl;
     */
    
    //vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    //cout<<trap(height)<<endl;
    
    //leecodee 55
    //vector<int> nums = {2,3,1,1,4};
    //cout<<canJump(nums)<<endl;
    
    //leecode 100-64
    //cout<<uniquePaths(3, 2)<<endl;
    
    //leecode 64
    //vector<vector<int>> nums = {{0}};
    //cout<<minPathSum(nums)<<endl;
    
    //string word1 = "horse";
    //string word2 = "ros";
    //cout<<minDistance(word1,word2)<<endl;
    
    //leecode 85
    vector<vector<char>> matrix = {
        {'1'}};
    cout<<maximalRectangle(matrix)<<endl;
    return 0;
}
