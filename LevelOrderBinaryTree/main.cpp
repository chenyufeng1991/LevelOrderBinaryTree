//
//  main.cpp
//  LevelOrderBinaryTree
//
//  Created by chenyufeng on 10/1/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 *  层序遍历二叉树
 */

typedef struct TreeNode{
    int element;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
}Node;

void CreateBinaryTree(Node **root)
{
    int num;
    cin >> num;

    if (num == -1)
    {
        return;
    }

    *root = new Node;
    (*root)->element = num;
    (*root)->lChild = NULL;
    (*root)->rChild = NULL;

    cout << "输入" << num << "的左孩子：";
    CreateBinaryTree(&((*root)->lChild));
    cout << "输入" << num << "的右孩子：";
    CreateBinaryTree(&((*root)->rChild));
}

// 先序遍历
void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->element << " ";
    PreOrder(root->lChild);
    PreOrder(root->rChild);
}

int main(int argc, const char * argv[])
{
    Node *root;

    cout << "请输入二叉树的节点，输入-1结束:" << endl;
    CreateBinaryTree(&root);

    cout << "先序遍历的结果为：";
    PreOrder(root);

    return 0;
}

















