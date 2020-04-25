//
//  3KthInTwoOrdered.cpp
//  Algorithm
//
//  Created by wangxue on 2020/1/13.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

// A,B is array
int KthBigVal(int *A,int *B,int lengthA,int lengthB,int k){
    if (lengthA < 0 || lengthB < 0) {
        return -1;
    }
    if (k > (lengthA + lengthB)) {
        return -1;
    }
    int *p1 = A, *p2 = B;
    for (int i=0; i<k; i++) {
        if (&p1 >= &p2) {
            p1++;
            if (i == k-1) {
                return *p1;
            }
            continue;
        }
        else{
            p2++;
            if (i == k-1) {
                return *p1;
            }
            continue;
        }
    }
    return 0;
}
