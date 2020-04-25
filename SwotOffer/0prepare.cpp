
//
//  prepare.cpp
//  Algorithm
//
//  Created by wangxue on 2020/1/11.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// prepare
// 定义一个空的类型，里面没有任何成员变量和成员函数。对该类型求sizeof，得到的结果是1
// 声明该类型的实例的时候，必须在内存中占有一定的空间，否则无法使用这些实例

class A{
public:
    A(){};
    ~A(){};
    virtual void A_init(){};
};

// 虚函数，为该类型生成虚函数表。在该类型的每一个实例中添加一个指向虚函数表的指针。
// 一个指针在64位的机器上大小占8字节。


// 虚函数复习：C++中的虚函数的作用主要是实现了多态的机制。关于多态，简而言之就是用父类型别的指针指向其子类的实例，然后通过父类的指针调用实际子类的成员函数。这种技术可以让父类的指针有“多种形态”，这是一种泛型技术
// 虚函数表：在这个表中，主是要一个类的虚函数的地址表，这张表解决了继承、覆盖的问题，保证其真实反应实际的函数。这样，在有虚函数的类的实例中这个表被分配在了这个实例的内存中，所以，当我们用父类的指针来操作一个子类的时候，这张虚函数表就显得由为重要了，它就像一个地图一样，指明了实际所应该调用的函数。
// C++的编译器应该是保证虚函数表的指针存在于对象实例中最前面的位置（这是为了保证取到虚函数表的有最高的性能——如果有多层继承或是多重继承的情况下）。 这意味着我们通过对象实例的地址得到这张虚函数表，然后就可以遍历其中函数指针，并调用相应的函数。
// 这就说明虚函数在执行时是一个动态的过程，并不是在编译时就确定下来要执行哪一个函数，而是运行时从虚表查到真正要执行的函数的地址
// 每个类都会维护一张虚表，编译时，编译器根据类的声明创建出虚表，当对象被构造时，虚表的地址就会被写入这个对象内存的起始位置。这就是多态性在 C++ 中实现的方式

// STO-P40: array value is from 0 to len-1, duplication: (输出) 数组中的一个重复的数字

vector<int> duplicate3(int numbers[],int length){
    vector<int> duplication;
    // Boundary conditions
    if (numbers==nullptr || length <=0) {
        return duplication;
    }
    for (int i=0; i<length; i++) {
        if (numbers[i] < 0 || numbers[i] > length-1) {
            return duplication;
        }
    }
    for (int i=0; i<length; i++) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                duplication.push_back(numbers[i]);
                break;
            }
            //swap num[i] and num[num[i]]
            swap(numbers[i], numbers[numbers[i]]);
        }
    }
    return duplication;
}

vector<int> duplicate2(int numbers[],int length){
    vector<int> duplication;
    unordered_map<int,int> mmap;
    if (numbers==nullptr || length<=0) {
        return duplication;
    }
    for (int i=0; i<length; i++) {
        // 可以去除这个限制了
        if (numbers[i] < 0 || numbers[i] > length+1) {
            return duplication;
        }
        if (mmap.find(numbers[i]) != mmap.end() ) {
            duplication.push_back(numbers[i]);
        }
        else{
            mmap[i] = numbers[i];
        }
    }
    return duplication;
}

// changing the num[] is not allowed
int countRange(const int numbers[],int length,int start,int end){
    if (numbers==nullptr) {
        return 0;
    }
    int count = 0;
    for (int i=0; i<length; i++) {
        if (numbers[i] >= start && numbers[i]<=end) {
            ++count;
        }
    }
    return count;
}

// 不能找出所有重复的数字，有问题。。。
int getDuplication(const int numbers[],int length){
    if (numbers==nullptr || length<=0) {
        return -1;
    }
    int start = 1;
    int end = length-1;
    while (end >= start) {
        int middle = ((end-start) >> 1) + start; // 除以2
        int count = countRange(numbers,length,start,middle);
        if (end==start) {
            if(count>1) return start;
            else break;
        }
        if (count > (middle-start+1)) {
            end = middle;
        }
        else start = middle+1;
    }
    return -1;
}

// STO的P47 题目s4，二维数组查找数字

bool find_num(int* matrix, int rows, int columns, int number){
    bool found = false;
    if (matrix != nullptr && rows>0 && columns>0) {
        int row = 0;
        int col = columns - 1;
        while (row < rows && col >=0) {
            if (matrix[row * columns + col] == number) {
                found = true;
                break;
            }
            else if (matrix[row * columns + col] > number) --col;
            else ++row;
        }
    }
    return found;
}


int main_S00(){
    //test 1
    A a;
    cout<<"虚函数空间："<<sizeof(a)<<endl;
    
    // test 2 测试输出重复的数字 the duplicate num
    int num[5] = {2, 1, 3, 1, 4};
    vector<int> duplication;
    //duplication = duplicate3(num, sizeof(num)/sizeof(int));
    duplication = duplicate2(num, sizeof(num)/sizeof(int));
    for(auto item:duplication) cout<<item<<endl;
    
    //test 3 二维数组中的查找
    int nums[2][4] = {{1,2,4,5},{3,4,5,9}};
    cout<<find_num((int*)nums, 2, 4, -1)<<endl;
    return 0;
}

/*
// ====================官方测试代码====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            //包含有这个值即可，duplication没有存所有的值
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main_S0()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}

*/
