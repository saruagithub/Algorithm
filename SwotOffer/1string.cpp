//
//  1string.cpp
//  test
//
//  Created by wangxue on 2019/12/24.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int stringToInt(char* string){
    // non digit,exception, +-, max num, and overflow
    if (string == NULL) {
        return -1;
    }
    int num = 0;
    while (*string != 0) {
        num = num * 10 + (*string - '0');
        ++string;
    }
    return num;
}

// SWO-P53 字符串替换空格
void ReplaceBlank(char string[], int length){
    if (string==nullptr || length<=0) {
        return;
    }
    //originalLength is the actual length of string
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0') {
        ++originalLength;
        if (string[i] == ' ') {
            ++numberOfBlank;
        }
        ++i;
    }
    
    //newLength is the length after replace
    int newLength = originalLength + numberOfBlank*2;
    if (newLength > length) { // 原字符串申请的容量不够了
        return;
    }
    // readdy for replace
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if (string[indexOfOriginal] == ' ') {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else{
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}

// 扩展
//输入: nums1 = [1,2,3,0,0,0], m = 3
//     nums2 = [2,5,6],       n = 3
//输出: [1,2,2,3,5,6]

//vector<int> mergeTwoOrdered(vector<int> array1,vector<int> array2,int length1,int length2){
//
//}

int main_S1(){
    char* string1 = (char*)"101";
    int res = stringToInt(string1);
    cout<<res<<endl;
    return 0;
}
