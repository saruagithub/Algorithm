//
//  5Sort.cpp
//  test
//
//  Created by wangxue on 2019/12/29.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

//Binary search

/*
归的二分查找
arrat：数组 ， low:上界；  high:下界;  target:查找的数据； 返回target所在数组的下标
1 2 3 4 5 6 (2)
*/
int binarySearch0(int array[], int length, int target) {
    if(length <= 0){
        return -1;
    }
    int low = 0, high = length-1, middle = 0;
    while(low <= high) {
        middle = low + (high - low) / 2;
        if(target < array[middle]) {
            high = middle - 1;
        }
        else if (target > array[middle]){
            low = middle + 1;
        }
        else{
            return middle;
        }
    }
    return -1;
}

int binarySearch(int array[], int low, int high, int target){
    int middle = (low + high)/2;
    if(low > high) {
        return -1;
    }
    if(target == array[middle]) {
        return middle;
    }
    else if(target < array[middle]) {
        return binarySearch(array, low, middle-1, target);
    }
    else{
        return binarySearch(array, middle+1, high, target);
    }
}

//merge sort
//quick sort
//other sort
template <typename E, typename Comp>
void insertSort(E A[] ,int n){
    for(int i=1;i<n;i++)
        for(int j=i ; (j>0)&&(Comp::prior(A[j],A[j-1])); j--)
                swap(A,j,j-1);
}

template <typename E>
void insertSort1(E A[] ,int n){
    for(int i=1;i<n;i++)
        for(int j=i ; (j>0)&&(A[j] > A[j-1]); j--){
            E temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
        }
}

template <typename E, typename Comp>
void BubbleSort(E A[] ,int n){
    for( int i=0;i<n-1;i++)
        for( int j = n-1; j>i;j--)
            if(Comp::prior(A[j],A[j-1]) )
                swap(A ,j ,j-1);
}

template <typename E, typename Comp>
void SelSort(E A[] ,int n){
    for( int i=0;i<n-1;i++){
        int lowindex = i;
        for( int j=n-1; j>i; j--)
            if( Comp:: prior(A[j] , A[lowindex] ))
                lowindex = j;
        swap( A ,i , lowindex);
    }
}

/*
 O(nlogn)
List mergesort ( List inlist){
    if( insist.length() <= 1 ) return inlist;
    List L1 = half of the items from inlist;
     List L2 = other half of ……
    return merge( meigesort(L1) , mergesort( L2));
}
*/

template <typename  E,typename Comp>
void qsort( E A[] ,int i, int j)
{
    if( j<= i) return ;
    int pivotindex = (i+j)/2;
    swap(A , pivotindex , j);
    int k = partition<E,Comp> (A ,i-1,j,A[j]);
    swap (A ,k ,j);
    qsort <E ,Comp> (A,i,k-1);
    qsort <E ,Comp> (A,k+1,j);
}

template <typename  E,typename Comp>
inline int partition(E A[], int l, int r, E& pivot)
{
    do{
        while( Comp::prior( A[++l] , pivot));
        while((l < r) && Comp::prior( pivot, A[--r]));
        swap(A, l ,r);
    }while (l< r);
    return l;
}

//shellsort -------
template <typename  E>
void insort(E A[],int n, int increment){
    for (int i=increment; i<n; i+=increment) {
        cout<<A[i]<<","<<A[i-increment]<<endl;
        for (int j=i; (j>=increment)&&(A[j]<A[j-increment]); j-=increment) {
            E temp = A[j];
            A[j] = A[j-increment];
            A[j-increment] = temp;
        }
    }
}

template <typename  E>
void shellsort(E A[],int n){
    // i denotes the increment
    for (int i=n/2; i>2; i/=2) {
        for (int j=0; j<i; j++) {
            insort<E>(&A[j], n-j, i);//A[j] is the start address  偏移
        }
    }
    insort<E>(A, n, 1);
}

//将排序好的子数组首先复制到辅助数组中，然后再把它们归并回原数组中
template <typename E>
void mergesort(E A[],E temp[], int left, int right){
    if (left == right) {
        return;
    }
    int mid = left + (right-left)/2;
    mergesort<E>(A, temp, left, mid);
    mergesort<E>(A, temp, mid+1, right);
    //then merge, temp[] is the auxiliary array
    for (int i=left; i<=right; i++) {
        temp[i] = A[i];
    }
    int i1 = left;
    int i2 = mid+1;
    for (int curr=left; curr<=right; curr++) {
        if (i1 == mid+1) A[curr] = temp[i2++]; //left all < right
        else if(i2 > right) A[curr] = temp[i1++]; //right all < left
        else if (temp[i1] < temp[i2]) A[curr] = temp[i1++];// smaller one is put into A
        else A[curr] = temp[i2++];
    }
}

//把排序好的子数组首先复制到辅助数组中，第二个数组顺序颠倒一下
//向中间推进，两端互相成为一个数组的”监视哨“
const int THRESHOLD = 4;
template <typename E>
void mergesort1(E A[], E temp[], int left, int right){
    if ((right-left) <= THRESHOLD) {
        insertSort1<E>(&A[left],right-left+1);
        return;
    }
    int i,j,k,mid=left+(right-left)/2;
    mergesort<E>(A, temp, left, mid);
    mergesort<E>(A, temp, mid+1, right);
    //merge operation, copy 2 halves to temp
    for (i=mid; i>=left; i--) {
        temp[i] = A[i];
    }
    for (j=1; j<=right-mid; j++) {
        temp[right-j+1] = A[j+mid];
    }
    //merge sublists back to A
    for (i=left,j=right,k=left;k<=right;k++) {
        if (temp[i] < temp[j]) {
            A[k] = temp[i++];
        }
        else A[k] = temp[j--];
    }
}

const int MaxKeyValue = 100; // 0<=A[i]<=50
void Binsort(int A[],int n){
    if(n<=0) return;
    list<int> B[MaxKeyValue];
    for (int i=0; i<n; i++) {
        B[A[i]].push_back(A[i]);
    }
    for (int i=0; i<MaxKeyValue; i++) {
        if (B[i].size() != 0) {
            for (list<int>::iterator it=B[i].begin(); it!=B[i].end(); ++it) {
                cout<<*it<<',';
            }
        }
    }
}

//template <typename E>
//void radix(E A[], E B[],int n, int k,int r,int cnt[]){
//
//}

int main_sort_find(){
    /* 二分搜索测试
    int num[6] = {0,2,3,4};
    int res = -1;
    res = binarySearch0(num, 4, 5);
    cout<<res<<endl;
     */
    
    /*shellsort test
    int num[16] = {59,20,17,13,28,14,23,83,36,98,11,70,65,41,42,15};
    shellsort<int>(num, 16);
    for (auto n:num) {
        cout<<n<<endl;
    }
     */
    int num[16] = {59,20,17,13,28,14,23,83,36,98,11,70,65,41,42,15};
    
    //int temp[16] = {0};
    //mergesort1<int>(num, temp, 0, 15);
    
    //binsort
    for (auto n:num) {
        cout<<n<<',';
    }
    cout<<endl;
    Binsort(num,16);
    return 0;
}

//find: Sequential search， binary s,hash s, BST search

//hash P245
