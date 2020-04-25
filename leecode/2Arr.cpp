//
//  2Arr.cpp
//  test
//
//  Created by wangxue on 2019/10/25.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

template <size_t n, size_t m>
void printArray(int (&a)[n][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void test_array() {
    cout << "Example I:" << endl;
    int a[2][5];
    printArray(a);
    cout << "Example II:" << endl;
    int b[2][5] = {{1, 2, 3}};
    printArray(b);
    cout << "Example III:"<< endl;
    int c[][5] = {1, 2, 3, 4, 5, 6, 7};
    printArray(c);
    cout << "Example IV:" << endl;
    int d[][5] = {{1, 2, 3, 4}, {5, 6}, {7}};
    printArray(d);
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool flag;// 标记是右上方向true还是左下方向false， 右上开始
        int x=0,y=0; //初始坐标
        vector<int> res;
        if (row == 0) {
            return res;
        };//边界情况
        flag = true;
        for (int i=0; i<row*col; i++) {
            res.push_back(matrix[x][y]);
            // 右上移动 x-- , y++
            if (flag) {
                x--;
                y++;
                //边界判断
                if (x>=0 && y<col) {
                    continue;
                }
                // 只要越界，就要开始相反的方向移动
                flag = false;
                
                // 右上移动时，x < 0 ， y 没有越界，
                // 比如对应图中数字 1， 2 的上方位置， 此时的坐标是 -1, 1
                if(x < 0 && y < col){
                    x = 0;
                    continue;
                }
                // 如果不是上面的越界方式，就是 x， y 都出界了，
                // 比如图中 3 右上的位置， 此时 x, y = -1, 3 ，因为第一排已经遍历完成，
                // 需要移动到下一行再开始，所以要 -1+2 , y 就是它的最大长度的坐标即可
                x = x+2;
                y = col-1;
                continue;
            }
            // 如果是向左下移动,flag = false
            x++;
            y--;

            // 如果没有越界，就继续下一次
            if (0 <= y && x < row) {
                continue;
            }

            // 只要有越界就该翻转方向了
            flag = true;

            // 如果 y 越界， x 没有越界，就像图中 4 左下的位置，此时是 x, y = 2, -1
            if (y < 0 && x < row) {
                y = 0;
                continue;
            }

            // y 越界了， 就像图中 8 的左下，需要将坐标移动到 9 的位置
            y = y + 2;
            x = row-1;
        }
        return res;
    }
    vector<int> findDiagonalOrder2(vector<vector<int>>& matrix){
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int x=0,y=0;
        for (int i=0; i<row*col; i++) {
            res.push_back(matrix[x][y]);
            if ((x+y)%2 == 0) { //偶数向上遍历
                if (y==col-1) {
                    // 往右移动一格准备向下遍历
                    x++;
                }
                else if (x==0){
                    // 往下移动一格准备向下遍历
                    y++;
                }else {
                    // 往上移动
                    x--;
                    y++;
                }
            }
            else{
                if (x==row-1) {
                    y++;
                }
                else if (y==0){
                    x++;
                }else{
                    x++;
                    y--;
                }
            }
        }
        return res;
    }
    //顺时针打印
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int x0 = 0,y0 = 0;
        int x1 = matrix.size()-1, y1 = matrix[0].size()-1;
        while (true) {
            for (int i=y0; i<=y1; ++i) ans.push_back(matrix[x0][i]);//向右走
            if (++x0 > x1) break;//超过上界
            for (int i=x0; i<=x1; ++i) ans.push_back(matrix[i][y1]);
            if (--y1 < y0) break;
            for (int i=y1; i>=y0; --i) ans.push_back(matrix[x1][i]);//向左走
            if (--x1 < x0) break;
            for (int i=x1; i>=x0; --i) ans.push_back(matrix[i][y0]);
            if (++y0 > y1) break;
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {
            return res;
        }
        for (int i=0; i<numRows; i++) {
            res.push_back(vector<int> (i+1,1));
            if (i>1) {
                for (int j=1; j<i; j++) {
                    res[i][j] = res[i-1][j-1]+res[i-1][j];
                }
            }
        }
        return res;
    }
};


int main_Arr(){
    /*
    int num,M,N;
    cin>>M>>N;
    vector<vector<int>> nums;
    vector<int> val;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin>>num;
            val.push_back(num);
        }
        nums.push_back(val);
        val.clear();
    }
     
    Solution solv;
    vector<int> res;
    res = solv.findDiagonalOrder2(nums);
    for(auto i:res) cout<<i<<endl;
    return 0;
    */
    int num;
    cin>>num;
    Solution2 solv;
    vector<vector<int>> res;
    res = solv.generate(num);
    return 0;
}
