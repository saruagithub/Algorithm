//
//  juzi.cpp
//  test
//
//  Created by wangxue on 17/5/3.
//  Copyright © 2017年 wangxue. All rights reserved.
//

/*#include <stdio.h>
#include <iostream>
using namespace std;
const int minN = -999999;

int main(int argc, char const *argv[])
{
    int m, n;
    while(cin >> m >> n){
        int A[m][n];
        int S[m], M[m];
        for(int i=0; i < m; ++i){
            S[i] = 0;
            M[i] = 0;
        }
        //int t = minN;
        for(int i=0; i < m; ++i){
            int t = minN;
            for(int j=0; j < n; j++){
                cin >> A[i][j];
                S[i] += A[i][j];
                if(t < A[i][j]){
                    t = A[i][j];
                    M[i] = j;
                }
            }
        }
        for(int i=0; i < m; ++i){
            A[i][M[i]] = S[i];
        }
        for(int i=0; i < m; ++i){
            // A[i][M[i]] = S[i];
            for(int j=0; j < n; ++j){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
*/
