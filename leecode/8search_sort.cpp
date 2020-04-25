//
//  8search_sort.cpp
//  Algorithm
//
//  Created by wangxue on 2020/2/16.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target){
    if(nums.size() <= 0) return -1;
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end-start)/2;
        // find it
        if(nums[mid] == target) return mid;
        
        // left side is ASE
        if (nums[start] <= nums[mid]){
            if(nums[start] <= target && nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        else{
            // right ride is ASE
            if(nums[mid] < target && target< nums[start]) start = mid+1;
            else    end = mid-1;
        }
    }
    return -1;
}

// leecode100-34 在排序数组中找第一个和最后一个的下标，最坏t: O(n)
vector<int> searchRange(vector<int>& nums, int target){
    int index1 = -1, index2 = -1;
    vector<int> res;
    res.push_back(index1);
    res.push_back(index2);
    // special condition
    if(nums.size() <= 0) return res;
    if(nums.size() == 1){
        if(nums[0] == target) return {0,0};
        else return res;
    }
    int start = 0, end = nums.size()-1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target == nums[mid]){
            index1 = mid;
            index2 = mid;
            while ( index1 >=1 && target == nums[index1-1]) {
                index1 = index1 - 1;
            }
            while ( index2 < nums.size()-1 && target == nums[index2+1]) {
                index2 = index2 + 1;
            }
            res[0] = index1;
            res[1] = index2;
            return res;
        }
        else if(target > nums[mid]) start = mid+1;
        else end = mid-1;
    }
    return res;
}


int searchRange_left_bound(vector<int>& nums, int target){
    if (nums.size() == 0) {
        return -1;
    }
    int start=0, end=nums.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) end = mid;
        else if (nums[mid] < target) start = mid + 1;
        else end = mid;
    }
    if (start == nums.size()) return -1; // target 比所有数都大
    return nums[start] == target ? start : -1;
}

int searchRange_right_bound(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int start = 0, end = nums.size();
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            start = mid + 1; // 注意
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid;
        }
    }
    // 注意
    if (end == 0) return -1;
    return nums[end-1] == target ? (end-1) : -1;
}

void search_range_test(){
    vector<int> res;
    vector<int> nums = {1,2,2,2,2,2,3};
    res = searchRange(nums,2);
    cout<<res[0]<<","<<res[1]<<endl;
    cout<<searchRange_left_bound(nums,0)<<endl;
    cout<<searchRange_right_bound(nums,2)<<endl;
}

//基数排序：每一轮分配结束时，记录都被复制回原数组
void radix(int* A, int* Bin,int n,int k,int r,int cnt[]){
    //n is the size of A
    //k is the digit of A[max], r is Cardinality 10 (make r from 1 to 10 to 100)
    //cnt[i] stores occurrences of records in bin[i]
    int j;
    for (int i=0,rtoi=1; i<k; i++,rtoi*=r) {
        for (j=0; j<r; j++) cnt[j] = 0; //init cnt,roti save the r^i
        
        //count the number of records for each bin on this pass
        for (j=0; j<n; j++) cnt[(A[j] / rtoi) % r]++;
        
        //index of B: cnt[j] will be index for last slot of bin j
        for (j=1; j<r; j++) cnt[j] = cnt[j-1] + cnt[j];
        
        //put records into bins, work from bottom of each bin
        //since bins fill from bottom, j counts downwards
        for (j=n-1; j>=0; j--) {
            Bin[--cnt[ (A[j] / rtoi) % r] ] = A[j];
        }
        
        //copy B back to A
        for (j=0; j<n; j++) {
            A[j] = Bin[j];
        }
        cout<<endl;
    }
}

void radix_sort_test(){
    int n = 12;
    int k = 2;
    int r= 10;
    int A[12] = {27,91,1,97,17,23,84,28,72,5,67,25};
    int B[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int cnt[10] = {0};
    radix(A,B,n,k,r,cnt);
    for (int i=0; i<n; i++) {
        cout<<A[i]<<" ";
    }
}

int main_radix(){
    //vector<int> nums = {4,5,6,7,0,1,2};
    //cout<<search(nums,0)<<endl;
    
    return 0;
}
