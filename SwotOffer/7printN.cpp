
//
//  7printN.cpp
//  Algorithm
//
//  Created by wangxue on 2019/12/29.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

bool Increment(char* number);
void PrintNumber(char* number);

// 17,P115 in swot offer
void Print1ToMaxOfNDigits(int n){
    if (n<=0) {
        return;
    }
    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';
    
    while (!Increment(number)) {
        PrintNumber(number);
    }
    delete []number;
}

bool Increment(char* number){
    bool isOverflow = false;
    int nTakeOver = 0;// whether jinwei进位
    int nLength = strlen(number);
    for(int i=nLength-1;i>=0;i--){
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength-1) {
            nSum++;
        }
        if (nSum >= 10) {
            if (i == 0) {
                isOverflow = true;
            }
            else{
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else{
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}


void PrintNumber(char* number){
    bool isBegginning0 = true;
    int nLength = strlen(number);
    for (int i=0; i<nLength; ++i) {
        if (isBegginning0 && number[i]!= 0) {
            isBegginning0 = false;
        }
        if (!isBegginning0) {
            cout<<number[i]<<endl;
        }
    }
    cout<<"\t"<<endl;
}
