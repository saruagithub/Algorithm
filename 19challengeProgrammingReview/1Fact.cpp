//
//  Fact.cpp
//  test
//
//  Created by wangxue on 10/15/18.
//  Copyright © 2018 wangxue. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
using namespace std;
 
const int MAX_N = 10000;
int memo[MAX_N] = {0};

int fact(int n){
    if ( n==0 ) {
        return 1;
    }
    return n * fact(n-1);
}

int fib(int n){
    if (n <=1 ) return n;
    if (memo[n] != 0){
        cout<<memo[n];
        return memo[n];
    }
    return memo[n] = fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<'\n'<<fib(n);
}
*/
