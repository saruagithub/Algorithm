//
//  5TreeNode.cpp
//  test
//
//  Created by wangxue on 2019/12/26.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};

// 翻转二叉树,Binary tree mirroring
TreeNode* invertTree(TreeNode* root){
    if (!root) {
        return root;
    }
    if (root->left == nullptr && root->right==nullptr) {
        return root;
    }
    TreeNode* right = invertTree(root->right);
    TreeNode* left = invertTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}


//lecode 104, time O(n),space O(logN) badly is O(n)
int maxDepth(TreeNode* root) {
    return (root==NULL)? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
}

//leecode100-543 相当于后序遍历，只不过每一次遍历携带一个信息（高度），计算一次值（左右子树高度和）
int length = INT_MIN;

// sum of each node's left and right
int helper(TreeNode* root){
    if(!root) return 0;
    int left_len = helper(root->left);
    int right_len = helper(root->right);
    length = max(length, left_len+right_len); // remember the max length
    return 1 + max(left_len,right_len);
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    helper(root);
    return length;
}//遍历

// leecode 538 累加树
int sum_val = 0;
TreeNode* convertBST(TreeNode* root) {
    if(!root){
        return NULL;
    }
    convertBST(root->right);
    sum_val += root->val;
    root->val = sum_val;
    convertBST(root->left);
    return root;
}

//leecode 98 验证二叉搜索树BST
//给定一个二叉树，判断其是否是一个有效的二叉搜索树。all left < root < all right 中序遍历有序
long last = LONG_MIN;
bool isValidBST(TreeNode* root){
    if(root == nullptr) return true;
    if(!isValidBST(root->left)) return false;
    if (last >= root->val) {
        return false;
    }
    last = root->val;
    if(!isValidBST(root->right)) return false;
    return true;
}

//leecode 101
bool isSymmetrical(TreeNode* root1,TreeNode* root2){
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    if (root1 -> val != root2 -> val) return false;
    return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
}

bool isSymmetric(TreeNode* root) {
    return isSymmetrical(root,root);
}


//construct tree by yourself
TreeNode* constructTree1(){
    TreeNode *root,*node1,*node2,*node3,*node4;
    root = new TreeNode(1);
    node1 = new TreeNode(2);
    root->right = node1;
    node2 = new TreeNode(-1);
    root->left = node2;
    
    node3 = new TreeNode(0);
    node2->right = node3;
    
    node4 = new TreeNode(-3);
    node2->left = node4;
    return root;
}

int main_Treenode(){
    TreeNode* root;
    vector<int> res;
    root = constructTree1();
    return 0;
}
