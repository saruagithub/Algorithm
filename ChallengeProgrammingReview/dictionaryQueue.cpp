//
//  dictionaryQueue.cpp
//  test
//
//  Created by wangxue on 17/5/18.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
//const int max_N = 100;
int N;

bool CompSmall(char s[],char ss[],int length){
    int i;
    for(i=0;i<length;i++){
        if(s[i] < ss[i]){
            return true;
        }
    }
    return false;
}

void reverse(char s[],int length){
    int i;
    char temp;
    for(i=0;i<length/2;i++){
        temp = s[i];
        s[i] = s[length-1-i];
        s[length-1-i] = temp;
    }
}

int main(){
    int i,j;
    cin >> N;
    int length = N;
    char S[length],SS[length];
    char T[N];
    for(i=0;i<N;i++){
        cin>>S[i];
    }
    for(i=0;i<N;i++){
        //copy
        for(j=0;j<length;i++){
            SS[j] = S[j];
        }
        //reverse
        reverse(SS,length);
        //compare get T
        if(CompSmall(S, SS, length)==true){
            T[i] = S[0];
            for(j=0;j<length-1;j++){
                S[i] = S[i+1];
            }
            length--;
        }
        else{
            T[i] = S[length-1];
            length--;
        }
    }
    for(i=0;i<N;i++){
        cout<<T[i]<<" ";
    }
    return 0;
}

 */






