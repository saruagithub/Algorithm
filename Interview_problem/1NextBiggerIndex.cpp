//
//  1NextBiggerIndex.cpp
//  test
//
//  Created by wangxue on 2019/12/18.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int value;
    int index;
    ListNode(int a,int b)
    {
        this->value=a;
        this->index=b;
    };
};

int main_view_1_nextBI(){
    stack<ListNode> stk;
    stack<int> res;
    int N;//mind N > 0
    cin>>N;
    int arr[N];
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    
    //algotithm
    //firstly, put last value,arr[N-1]
    res.push(-1);
    ListNode temp(arr[N-1],N-1);
    stk.push(temp);
    
    for (int i=N-1; i>=0; i--) {
        while ( !stk.empty()) {
            //compare with stack top value
            if (arr[i] < stk.top().value) {
                //remember the result
                res.push(stk.top().index);
                ListNode temp(arr[i],i);
                //push current arr[i]
                stk.push(temp);
                break;
            }
            else{
                stk.pop();
                if (stk.empty()) {
                    //no bigger data, so res is -1
                    res.push(-1);
                    ListNode temp(arr[i],i);
                    //put this value in the stack
                    stk.push(temp);
                    break;
                }
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        cout<<res.top()<<endl;
        res.pop();
    }
    return 0;
//倒着遍历，维护一个递减的stack(top保持最小）。先10和其index绑定入stack，然后轮到7，判断stack top，若大于7就把stack top的数的index返回，否则弹出stack top，直到找到大于7或者stack弹空，若弹空则返回-1.然后把7绑定index压到stack里。
}

