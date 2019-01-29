/*
 * This is the solution for the coding aspect of Homework / Programming
 * assignment #3.
 * @author Blake Lapum, Fall 2017
*/
#include <queue>
#include <iostream>
#include "bst.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

void BinarySearchTree::insert(const int &value, BinarySearchTree::BinaryNode *&node) {

    if(node == NULL) {
        node = new BinaryNode;
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }
    else if(value < node->data) {
        insert(value, node->left);
    }
    else if(node->data < value) {
        insert(value, node->right);
    }

}

void BinarySearchTree::preorder(BinarySearchTree::BinaryNode *node) {
    if(root == NULL) {
        cout<<"The tree is empty!"<<endl;
        return;
    }
    if (node == NULL) {
        return;
    }
    else {
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BinarySearchTree::postorder(BinarySearchTree::BinaryNode *node) {
    if(root == NULL) {
        cout<<"The tree is empty!"<<endl;
        return;
    }
    if (node == NULL) {
        return;
    }

    else {
        postorder(node->left);
        postorder(node->right);
        cout<<node->data << " ";
    }}

void BinarySearchTree::inorder(BinarySearchTree::BinaryNode *node) {
    if(root == NULL) {
        cout<<"The tree is empty!"<<endl;
        return;
    }
    if (node == NULL) {
        return;
    }

    else {
        inorder(node->left);
        cout<<node->data << " ";
        inorder(node->right);

    }}

void BinarySearchTree::makeEmpty(BinarySearchTree::BinaryNode *&node) {
    if(node != NULL) {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }
    node = NULL;
}

int BinarySearchTree::computeLeaves(BinarySearchTree::BinaryNode *node) {

    if(root == NULL) {
        return 0;
    }
    if (node == NULL) {
        return 0;
    }
    if(node->left ==  NULL && node->right == NULL) {
            return 1;
    }

    else {
        return computeLeaves(node->left) +
        computeLeaves(node->right);
    }
}

int BinarySearchTree::computeNodes(BinarySearchTree::BinaryNode *node) {
    if(root == NULL) {
        return 0;
    }
    if(node == NULL) {
        return 0;
    }
    else {
        return 1 + computeNodes(node->left) + computeNodes(node->right);
    }
}

int BinarySearchTree::height(BinarySearchTree:: BinaryNode *node) {
    if(node == nullptr) {
        return -1;
    }
    else {
        return 1 + max(height(node->left), height(node->right));
    }
}

void BinarySearchTree::printLevel(BinarySearchTree::BinaryNode *node, const int &level) {
    if(node == NULL) {
        return;
    }
    if(level == 1) {
        printf("%d ", node->data);
    }
    else if(level > 1) {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void BinarySearchTree::levelorder(BinarySearchTree::BinaryNode *root) {

    if (root == NULL)  return;

    queue<BinaryNode *> q;

    q.push(root);

    while (q.empty() == false) {

        BinaryNode *node = q.front();
        cout << node->data << " ";
        q.pop();

        if(node->left != NULL) {
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node->right);
        }
    }
}
