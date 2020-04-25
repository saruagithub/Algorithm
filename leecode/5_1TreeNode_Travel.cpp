//
//  5_1TreeNode_Travel.cpp
//  Algorithm
//
//  Created by wangxue on 2020/4/15.
//  Copyright © 2020 wangxue. All rights reserved.
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

void travel_inoder(TreeNode* root){
    if (!root) return;
    travel_inoder(root->left);
    cout<<root->val<<endl;
    travel_inoder(root->right);
}

//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-fa-by-jason-2/ leecode94

vector<int> res;
vector<int> inorderTraversal0(TreeNode* root){
    if(root != NULL){
        inorderTraversal0(root->left);
        res.push_back(root->val);
        inorderTraversal0(root->right);
    }
    return res;
}

void travel_preoder(TreeNode* root){
    if (!root) return;
    cout<<root->val<<endl;
    travel_preoder(root->left);
    travel_preoder(root->right);
}

void travel_preoder2(TreeNode* root){
    stack<TreeNode*> Stk;
    if (root) {
        Stk.push(root);
    }
    while (!Stk.empty()) {
        root = Stk.top();
        cout<<root->val<<endl;
        Stk.pop();
        if (root->right) {
            Stk.push(root->right);
        }
        if (root->left) {
            Stk.push(root->left);
        }
    }
}

//leecode94 给定一个二叉树，返回它的中序遍历
//迭代前序遍历算法，每到一个节点 A，就应该立即访问它。在访问完根节点后，遍历左子树前，要将右子树压入栈。
//时间复杂度为 O(n)
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode* rt = root;
    while (rt || stk.size()) {
        while (rt) {
            //root,left,right
            stk.push(rt->right);
            ans.push_back(rt->val);//first root
            rt = rt->left; // then left
        }
        rt = stk.top();//finally right
        stk.pop();
    }
    return ans;
}

//后序遍历完整棵树后，结果序列逆序即可。
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> v;
    TreeNode* rt = root;
    while(rt || S.size()){
        while(rt){
            //root,right,left,then reverse
            S.push(rt->left);
            v.push_back(rt->val);
            rt=rt->right;
        }
        rt=S.top();
        S.pop();
    }
    reverse(v.begin(),v.end());
    return v;
}

//inorder 中序迭代遍历树
//每到一个节点 A，因为根的访问在中间，将 A 入栈。然后遍历左子树，接着访问 A，最后遍历右子树。
vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode*> S;
    vector<int> v;
    TreeNode* rt = root;
    while (rt || S.size()) {
        while (rt) {
            // all left
            S.push(rt);
            rt = rt->left;
        }
        //mid
        rt = S.top();
        S.pop();
        v.push_back(rt->val);
        //right
        rt = rt->right;
    }
    return v;
}


//Hierarchical traversal for tree, Swot Offer P173
void PrintFromTopToBottom(TreeNode* root){
    if (!root) {
        return;
    }
    std::queue<TreeNode*> DequeTreeNode;
    DequeTreeNode.push(root);
    while (!DequeTreeNode.empty()) {
        TreeNode* pNode = DequeTreeNode.front();
        cout<<pNode->val<<endl;
        DequeTreeNode.pop();
        if (pNode->left) {
            DequeTreeNode.push(pNode->left);
        }
        if (pNode->right) {
            DequeTreeNode.push(pNode->right);
        }
    }
}

//leecode 102,返回其按 层序遍历 得到的节点值, 返回 vector<vector<int>>
//判断什么时候返回vector<int>，可以在每层多push进去一个NULL，将内层循环条件变为aQueue.front()即可
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> QueueTreeNode;
    //多push a null
    QueueTreeNode.push(root);
    QueueTreeNode.push(nullptr);
    while (!QueueTreeNode.empty()) {
        vector<int> res_temp;
        while (QueueTreeNode.front()) {
            TreeNode* node = QueueTreeNode.front();
            res_temp.push_back(node->val);
            if (node->left) {
                QueueTreeNode.push(node->left);
            }
            if (node->right) {
                QueueTreeNode.push(node->right);
            }
            QueueTreeNode.pop(); //pop root
        }
        QueueTreeNode.pop(); //pop null
        if (!res_temp.empty()) {
            res.push_back(res_temp);
        }
        if (QueueTreeNode.empty()) break;
        QueueTreeNode.push(nullptr); //push null as flag
    }
    return res;
}

//construct tree by yourself
TreeNode* constructTree(){
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


int main_treeTravel(){
    TreeNode* root;
    vector<int> res;
    root = constructTree();
    //travel_preoder(root);
    travel_preoder2(root);
    res = preorderTraversal(root);
    //res = preorderTraversal(root);
    for(auto num:res) cout<<num<<endl;
    return 0;
}
