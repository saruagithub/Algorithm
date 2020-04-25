//
//  5_1Reversed_pair.cpp
//  Algorithm
//
//  Created by wangxue on 2020/4/24.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int InversePairsCore(vector<int> data,vector<int>& copy,int start,int end);

//剑指offer 249
int InversePairs(vector<int>& data,int length){
    if (length <= 0) {
        return 0;
    }
    vector<int> copy;
    for (int i=0; i<length; i++) {
        copy.push_back(data[i]);
    }
    int count = InversePairsCore(data,copy,0,length-1);
    return count;
}

int InversePairsCore(vector<int> data,vector<int>& copy,int start,int end){
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }
    int length = (end - start) / 2;
    int left = InversePairsCore(copy, data, start, start+length);
    int right = InversePairsCore(copy, data, start+length+1, end);
    
    //i 初始化为前半段最后一个数字的下标 Initialize to the index of the last digit of the first half
    int i = start + length;
    // j 初始化为后半段最后一个数字的下标
    int j = end;
    int indexCopy = end;
    int count = 0;
    while (i>=start && j>=start+length+1) {
        if (data[i] > data[j]) {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else copy[indexCopy--] = data[j--];
    }
    for (; i>=start; --i) {
        copy[indexCopy--] = data[i];
    }
    for (; j>=start+length+1; --j) {
        copy[indexCopy--] = data[j];
    }
    return left+right+count;
}

int main_testInversePair(){
    vector<int> nums = {7,5,6,4};
    int res;
    res = InversePairs(nums, 4);
    cout<<res<<endl;
    return 0;
}

// 20200424腾讯后台笔试题：逆序对之序列反转
void reverse_array(vector<int>& array, int len, int interval){
    if (len <= 0) {
        return;
    }
    if (interval == 1) return;
    for (int i=0; i<len; i++) {
        if (i!=0 && (i+1)%interval == 0) {
            //按interval交换
            for(int j=0;j<interval/2;j++){
                int temp = array[i-interval+j+1];
                array[i-interval+j+1] = array[i-j];
                array[i-j] = temp;
            }
        }
    }
}

//test_reverse_array
int main_test_reverse_array(){
    //input
    int n;
    cin>>n;
    vector<int> init_array(pow(2,n),0);
    for (int i=0; i<pow(2,n); i++) {
        cin>>init_array[i];
    }
    int m;
    cin>>m;
    vector<int> q(m,0);
    for (int i=0; i<m; i++) {
        cin>>q[i];
    }
    //calculate
    int res[m];
    for (int i = 0; i<m; i++) {
        //reverse array
        reverse_array(init_array, init_array.size(), pow(2, q[i]));
        //for(int i=0;i<init_array.size();i++) cout<<init_array[i]<<",";
        //get the Reverse pair num
        res[i] = InversePairs(init_array, init_array.size());
        cout<<res[i]<<endl;
    }
    return 0;
}
