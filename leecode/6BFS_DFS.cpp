//
//  6BFS_DFS.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/14.
//  Copyright © 2020 wangxue. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


//leecode100-17 电话号码的字母组合
// 回溯是一种通过穷举所有可能情况来找到所有解的算法 or DFS
void dfs(vector<string>& res,string str,string& digits,unordered_map<char, string>&hash, int k){
    // stop condition, str 不断拼接，直到与给的数字长度相同
    if(str.size() == digits.size()){
        res.push_back(str);//添加到结果里
        return;//递归深入完毕，退出
    }
    string temp = hash[digits[k]];//k代表每次增加的数字
    for(char w:temp){
        str += w; // 添加一个字符
        dfs(res, str, digits, hash, k+1); //继续向下搜索
        str.pop_back();//标记访问,去掉末尾字符向上走
    }
    return;
}

vector<string> letterCombinations(string digits){
    unordered_map<char, string> table{
    {'0', " "}, {'1',"*"}, {'2', "abc"},
    {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
    {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
    {'9',"wxyz"}};
    vector<string> result;
    if (digits == "") return result;
    dfs(result,"",digits,table,0);
    return result;
}

//leecode100-22
// 剪枝的条件为：左括号的数目一旦小于右括号的数目，以及，左括号的数目和右括号数目均小于n。
void func(vector<string>& res, string str,int l, int r, int n){
    if(l > n || r > n || r > l) return;
    if (l == n && r==n) { //stop condition
        res.push_back(str);
        return;
    }
    func(res, str + '(', l+1, r, n);
    func(res, str + ')', l, r+1, n);
    return;
}

vector<string> generateParenthesis(int n){
    vector<string> res;
    func(res, "", 0, 0, n);
    return res;
    // thanks a lot
}


// leecode100-39 另一方面由于考虑到题目要求列出所有的解集，且不能包含重复的组合，可以考虑用DFS搜索
void dfs_addSum(vector<int> &candidates,vector<vector<int>>& res,vector<int>& v,int remain, int last)
{
    if(remain == 0)
    {
        res.push_back(v);
        return;
    }
    if(remain < 0)
        return;
    for(int i = last; i < candidates.size(); i++)
    {

            v.push_back(candidates[i]);
            dfs_addSum(candidates,res,v, remain - candidates[i], i);
            v.pop_back();//返回上一个

    }
}

// 注意控制去重
void dfs_addSum1(vector<int> &candidates,vector<vector<int>>& res,int target, vector<int>& v, int k, int sum, int last){
    if (sum == target) {
        res.push_back(v);
        return;
    }
    if (sum > target) return;
    for (int i = 0; i<candidates.size(); i++) {
        if (candidates[i] < last) break;
        v.push_back(candidates[i]);
        dfs_addSum1(candidates,res,target,v,k+1,sum+candidates[i],candidates[i]);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> v;
    sort(candidates.begin(), candidates.end());
    dfs_addSum1(candidates,res,target,v, 0, 0 ,0 ); // 0 means level, 0 is temp_sum
    return res;
}




// leecode100-46 全排列
// 给定一个没有重复数字的序列，返回其所有可能的全排列。
// 1、路径：也就是已经做出的选择。
// 2、选择列表：也就是你当前可以做的选择。
// 3、结束条件：也就是到达决策树底层，无法再做选择的条件。
/*
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
 */

void dfs_permute(vector<int>& nums,vector<vector<int>>& res,int first){
    // end condition
    if(first == nums.size()){
        res.push_back(nums);
        return;
    }
    // go deep
    for (int i=first; i<nums.size(); i++) {
        swap(nums[first], nums[i]);
        dfs_permute(nums,res,first+1);
        swap(nums[first], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<int> res_temp;
    vector<vector<int>> res;
    dfs_permute(nums,res,0);
    return res;
}

int climbStairs(int n) {
    if (n == 1) return 1;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3;i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// leecode 78 DFS
// 还可以直接从后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
void dfs_subsets(vector<int>& nums, vector<int>& res_temp, vector<vector<int>>& res,int k){
    if (k == nums.size())  {
        res.push_back(res_temp);
        return;
    }
    //不选
    dfs_subsets(nums,res_temp,res,k+1);
    res_temp.push_back(nums[k]); //选nums[k]
    dfs_subsets(nums,res_temp,res,k+1);
    res_temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<int> res_temp;
    vector<vector<int>> res;
    dfs_subsets(nums,res_temp,res,0);
    return res;
}

/*
void dfs(int x,int y){
    //replace the w into .
    field[x][y] = '.';
    int dx,dy;
    //for check the 8 direction
    for(dx=-1;dx<=1;dx++){
        for(dy=-1;dy<=1;dy++){
            int nx = x + dx;
            int ny = y + dy;
            //whether in the field and whether has water
            if(nx>=0 && nx<N && ny>=0 && ny<=M && field[nx][ny] == 'w')
                dfs(nx, ny);
        }
    }
}
*/

//leecode 79 二维网格和一个单词，找出该单词是否存在于网格中，格子不可重复用。
bool dfs_exist(vector<vector<char>>& board, vector<vector<int>>& flag,
              string word,int x,int y,int k){
    if (board[x][y] != word[k]) {
        flag[x][y] = 0;
        return false;
    }
    if (k == word.size()-1) {
        return true;
    }
    flag[x][y] = 1;
    // next step , go four direction
    if( (x-1>=0 && flag[x-1][y]==0 && dfs_exist(board,flag, word, x-1, y, k+1))
    || (y+1<=board[0].size()-1 && flag[x][y+1]==0 && dfs_exist(board,flag, word, x, y+1, k+1))
    || (x+1<=board.size()-1 && flag[x+1][y]==0  && dfs_exist(board,flag, word, x+1, y, k+1) )
       || (y-1>=0 && flag[x][y-1]==0 && dfs_exist(board,flag, word, x, y-1, k+1)) ){
        return true;
    }
    else{
        flag[x][y] = 0;
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word){
    vector<vector<int>> flag(board.size() ,vector<int>(board[0].size(),0)); //whether visit
    //查找第一个单词首字母
    for(int i=0;i<board.size();i++){
        for (int j=0;j<board[0].size();j++) {
            // board[i][j] is the start
            if(dfs_exist(board,flag,word,i,j,0)) return true;
            else flag = vector<vector<int>>(board.size() ,vector<int>(board[0].size(),0));//reinit
        }
    }
    return false;
}

bool hasPathCore(vector<vector<char>>& board,int row,int col,string word,int pathLengh,vector<vector<bool>>& flag){
    if (word[pathLengh] == '\0') {
        return true;
    }
    bool hasPath = false;
    if (row>=0 && row<board.size() && col>=0 && col<board[0].size() && board[row][col]==word[pathLengh] && !flag[row][col]) {
        //cout<<row<<","<<col<<endl;
        pathLengh++;
        flag[row][col] = true;
        hasPath = hasPathCore(board, row, col-1, word, pathLengh, flag) || hasPathCore(board, row-1, col, word, pathLengh, flag) || hasPathCore(board, row, col+1, word, pathLengh, flag) || hasPathCore(board, row+1, col, word, pathLengh, flag);
        if (!hasPath) {
            pathLengh--;
            flag[row][col] = false;
        }
    }
    return hasPath;
}

bool exist1(vector<vector<char>>& board, string word){
    if (board.size()==0 || word.size()==0) {
        return false;
    }
    vector<vector<bool>> flag(board.size(),vector<bool>(board[0].size(),false));
    int pathLengh = 0;
    for (int row=0; row<board.size(); row++) {
        for (int col=0; col<board[0].size(); col++) {
            if (hasPathCore(board,row,col,word,pathLengh,flag)) {
                return true;
            }
        }
    }
    return false;
}

//招商银行juzi
int res_addsub = 0;
void dfs_addsub_zhaohang(vector<int>& nums,int k,int sum,int i){
    if (i == nums.size()) {
        if (sum == k) res_addsub++;
        return;
    }
    dfs_addsub_zhaohang(nums,k,sum-nums[i],i+1);
    dfs_addsub_zhaohang(nums,k,sum+nums[i],i+1);
}

// -------------------------------- test func ----------------------------------------
void test_leecode79(){
// leecode 79
    vector<vector<char>> board =
    {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };
    string word = "ABCEFSADEESE";
    cout<<exist(board,word)<<endl;
}

void test_0408_zhaohangtest(){
    //招商银行juzi
    vector<int> a = {1,2,3,4,5};
    int k=1;
    dfs_addsub_zhaohang(a,k,1,1);
    cout<<res_addsub<<endl;
}

int main_dfs(){
    /*
    string s = "c";
    cout<<lengthOfLongestSubstring(s)<<endl;
    
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(h)<<endl;
     */
    
    /*
    vector<string> result;
    string a = "23";
    result = letterCombinations(a);
     */
    
    /*
    vector<vector<int>> res;
    vector<int> candidates = {2,3,6,7};
    res = combinationSum1(candidates,7);
    for (auto res_temp: res){
        for(auto val: res_temp){
            cout<<val<<endl;
        }
        cout<<"---"<<endl;
    }
     */
    
    
    /*
    vector<vector<int>> res;
    vector<int> nums = {2,3,6,7};
    res = permute(nums);
    for (auto res_temp: res){
        for(auto val: res_temp){
            cout<<val<<endl;
        }
        cout<<"---"<<endl;
    }
    */
     
    //cout<<climbStairs(4);
    
    /*
    vector<int> nums = {1,2,3};
    vector<vector<int>> result;
    result = subsets(nums);
     */
    return 0;
}
