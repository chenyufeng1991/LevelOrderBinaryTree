//
//  main.cpp
//  LevelOrderBinaryTree
//
//  Created by chenyufeng on 10/1/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <queue>

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

//层序遍历
void LevelOrder(queue<Node *> &nodeQueue)
{
    if (nodeQueue.empty())
    {
        return;
    }

    Node *frontNode = nodeQueue.front();
    cout << frontNode->element << " ";
    nodeQueue.pop();
    if (frontNode->lChild != NULL)
    {
        nodeQueue.push(frontNode->lChild);
    }
    if (frontNode->rChild != NULL)
    {
        nodeQueue.push(frontNode->rChild);
    }

    LevelOrder(nodeQueue);
}

int main(int argc, const char * argv[])
{
    Node *root;

    cout << "请输入二叉树的节点，输入-1结束:" << endl;
    CreateBinaryTree(&root);

    cout << "先序遍历的结果为：";
    PreOrder(root);
    cout << endl;

    cout << "层序遍历的结果为：";
    queue<Node *> Q;
    Q.push(root);
    LevelOrder(Q);
    cout << endl;

    return 0;
}

















