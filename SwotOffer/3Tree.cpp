//
//  3Tree.cpp
//  test
//
//  Created by wangxue on 2019/12/29.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;
};

//P63 reconstruct tree base on preorder and inorder

Treenode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder){
    // the fisrt value in preorder is root
    int rootValue = startPreorder[0];
    Treenode* root = new Treenode();
    root->val = rootValue;
    root->right = root->left = nullptr;
    
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder==*startInorder) {
            return root;
        }
        else throw ("Invalid input");
    }
    
    //Traversal in the inorder to find the root
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder!=rootValue) {
        ++rootInorder;
    }
    if (rootInorder == endInorder && *rootInorder!=rootValue) {
        throw ("Invalid input");
    }
    
    // begin build tree recursively
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        // left tree
        root->left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
    }
    if (leftLength < endPreorder - startPreorder) {
        // right tree
        root->right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    return root;
}

Treenode* Construct(int* preorder,int* inorder, int length){
    if (preorder == nullptr || inorder==nullptr || length<=0) {
        return nullptr;
    }
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}



// P65 next node in inorder in the binary tree
// a:b,c ; b:d,e;  e:h,i;   c:f,g;
// three condition
Treenode* GetNext(Treenode* pNode){
    if (pNode == nullptr) {
        return nullptr;
    }
    Treenode* pNext = nullptr;
    if (pNode->right != nullptr) {
        Treenode* pRight = pNode->right;
        while (pRight->left != nullptr) {
            pRight = pRight->left;
        }
        pNext = pRight;
    }
//    else if (pNode->Parent != nullptr){
//        Treenode* Cur = pNode;
//        Treenode* pParent = pNext->Parent;
//        while (Parent != nullptr && Cur!= pParent->right) {
//            Cur = pParent;
//            pParent = pParent->Parent;
//        }
//    }
    return pNext;
}



// 26,SwotOffer,P148: two binary tree, B is A's subTree?

bool Equal(double num1,double num2){
    if ((num1 - num2) > -0.0000001 && (num1 - num2)<0.0000001) {
        return true;
    }
    else return false;
}

bool DoesTree1HasTree2(Treenode* Root1,Treenode* Root2){
    if (Root2 == nullptr) return true;
    if(Root1 == nullptr) return false;
    if (!Equal(Root1->val, Root2->val)) {
        return false;
    }
    return DoesTree1HasTree2(Root1->left, Root2->left) && DoesTree1HasTree2(Root1->right, Root2->right);
}

bool hasSbuTree(Treenode* Root1,Treenode* Root2){
    bool result = false;
    if (Root1!=nullptr && Root2!=nullptr) {
        if (Equal(Root1->val, Root2->val)) {
            result = DoesTree1HasTree2(Root1, Root2);
        }
        if (!result) {
            result = hasSbuTree(Root1->left, Root2);
        }
        if (!result) {
            result = hasSbuTree(Root1->right, Root2);
        }
    }
    return result;
}
