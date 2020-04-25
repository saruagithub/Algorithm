//
//  8tecent_test1.cpp
//  Algorithm
//
//  Created by wangxue on 2020/4/23.
//  Copyright © 2020 wangxue. All rights reserved.
// https://www.nowcoder.com/question/next?pid=21283868&qid=830861&tid=32909113

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

//题目1 解压缩字符串
void unzip_str(string str){
    stack<int> index_stk;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '[') {
            index_stk.push(i);
        }
        if (str[i] == ']') {
            //get index fro stk
            int index = index_stk.top();
            index_stk.pop();
            //concat the duplicated string
            string temp;
            int times_index;
            for (int k=index; k<i;k++){
                if(str[k] == '|') times_index = k;
            }
            //mind the duplicate times > 10
            for (int j=0; j< stoi(str.substr(index+1,times_index-index-1)); j++) {
                temp = temp + str.substr(times_index+1,i-times_index-1);
            }
            //replace the str
            str.erase(index,(i-index+1));
            str.insert(index, temp);
            //restart
            i = index + temp.size()-1;
            //test
            //cout<<str<<endl;
        }
    }
    cout<<str<<endl;
}

int main_testUnzip(){
    string str;
    cin>>str;
    unzip_str(str);
    return 0;
}

// 题目2： 前后看高楼，second 暴力？？？
void Building_see(int* matrix,int len){
    int *res = new int[len];
    for (int i=0;i<len;i++){
        int num = 0;
        int last_one = 0;
        for (int j=i-1; j>=0; j--) {
            if (matrix[j] > last_one ) {
                num++;
                last_one = matrix[j];
            }
        }
        last_one = 0;
        for (int k=i+1; k<len; k++) {
            if (matrix[k] > last_one) {
                num++;
                last_one = matrix[k];
            }
        }
        res[i] = num+1; //+1: own
    }
    
    for (int i=0; i<len; i++) {
        cout<<res[i]<<" ";
    }
    delete []res; //remind delete the memory
}

int main_testBulidingSee(){
    int n;
    cin>>n;
    int* w = new int[n];
    for (int i=0; i<n; i++) {
        cin>>w[i];
    }
    //calculate 两边递增序列的长度
    Building_see(w,n);
    return 0;
}


int Building_see_official() {
    vector<int> a, b;
    stack<int> st1, st2;
    int n, x[100001];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
      
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        a.push_back(st1.size());
        b.push_back(st2.size());
        while (!st1.empty() && st1.top() <= x[i]) st1.pop(); //always Monotonic stack
        while (!st2.empty() && st2.top() <= x[j]) st2.pop(); //always Monotonic stack
        st1.push(x[i]);
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1<< " "; //add 1 himself
    return 0;
}
// 题目3 见swot_offer的5_1Reversed_pair


// 题目4 Vacation，不连续工作或锻炼2天
int main_vacation(){
    int n;
    cin>>n;
    vector<int> company(n,0);
    vector<int> gym(n,0);
    for (int i=0; i<n; i++) {
        cin>>company[i];
    }
    for (int i=0; i<n; i++) {
        cin>>gym[i];
    }
    int res = 0;
    //less rest and more work
    for (int i=0; i<n; i++) {
        if (company[i]==0 && gym[i]==0) {
            res++;
        }
        
    }
    cout<<res<<endl;
    return 0;
}

/*
 n = int(input())
 company = input().split()
 sports = input().split()

 # dp: -1 - rest, 0 - company, 1- sports, 2 - do any
 dp = [-1] * n
 for i in range(n):
     # 公司、健身房都营业
     if (int(sports[i]) & int(company[i])) == 1:
         if i >= 1 and dp[i-1] == 0:     # 昨天去公司，今天就去健身
             dp[i] = 1
         elif i >= 1 and dp[i-1] == 1:   # 昨天去健身，今天就去公司
             dp[i] = 0
         else:                           # 否则就是 do any
             dp[i] = 2
     else:
         # 标识今天是否去公司
         comp_flag = False
         # 只有公司营业
         if int(company[i]) == 1:
             if i == 0:    # 第一天
                 dp[i] = 0
                 comp_flag = True
             else:
                 if dp[i-1] == 2:    # 昨天是 do any
                     if i == 1:
                         dp[i] = 0
                         comp_flag = True
                     elif i >= 2 and dp[i-2] != 1:    # 前天没去健身房（如果前天去了，那么昨天就去公司了）
                         dp[i] = 0
                         comp_flag = True
                 elif dp[i-1] != 0:    # 昨天没有去公司
                     dp[i] = 0
                     comp_flag = True
         # 只有健身房营业
         if int(sports[i]) == 1:
             if not comp_flag:
                 if i == 0:    # 第一天
                     dp[i] = 1
                 else:
                     if dp[i-1] == 2:    # 昨天是 do any
                         if i == 1:
                             dp[i] = 1
                         elif i >= 2 and dp[i-2] != 0:    # 前天没去公司（如果前天去了，那么昨天就去健身房了）
                             dp[i] = 1
                     elif dp[i-1] != 1:    # 昨天没有去健身房
                         dp[i] = 1
 print(dp.count(-1))
 */

//题目5：视野争夺：贪心算法的区间覆盖问题
//首字母排序 a > b,true
bool cmp(vector<int> a, vector<int> b)
{
    if(a[0] < b[0]) return true;
    else if (a[0]==b[0] && a[1]<b[1]) return true;
    else return false;
}

//参考 https://www.cnblogs.com/Draymonder/p/7215230.html
int slove_cover(vector<vector<int>>& array,int len, int cover_len){
    if (array[0][0] > 0 || array[len-1][1]<cover_len) {
        return -1; //min and max do not cover the river
    }
    //last 表示当前已经覆盖到的区域的最右边距离 .
    //far 表示在剩下的线段中找到的所有左端点小于等于当前已经覆盖到的区域的右端点的线段中，不断更新最右边的距离
    int  last=0,far=0,count=0;
    for (int i=0; i<len; i++) {
        if(last >= cover_len) return count;
        if (array[i][0] <= last) {
            far = max(far, array[i][1]);
        }
        else if (array[i][0] > last){
            count++;
            last = far;
            if (array[i][0] <= last) {
                far = max(far,array[i][1]);
            }
            else return -1;
        }
    }
    if(last < cover_len && far >= cover_len) return count+1;
    return count;
}

int main_test_cover(){
    int n,L;
    cin>>n>>L;
    vector<vector<int>> array(n,vector<int>(2,0));
    for (int i=0; i<n; i++) {
        cin>>array[i][0]>>array[i][1];
    }
    sort(array.begin(), array.end(), cmp);
    //for(auto p : array)   cout<<p[0]<<' '<<p[1]<<endl;
    //slove
    int res;
    res = slove_cover(array,n,L);
    cout<<res;
    return 0;
}
