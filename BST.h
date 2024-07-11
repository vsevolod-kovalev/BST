#include "BSTNode.h"
#ifndef BST_H
#define BST_H

class BST {
    BSTNode* root;
    public:
        BST() : root(nullptr) {}
        BSTNode* insert(BSTNode* node, const int& value) {
            if (!node){
                BSTNode* node_to_insert = new BSTNode(value);
                return node_to_insert;
            }
            if (value > node->value) {
                node->right = insert(node->right, value);
            } else {
                node->left = insert(node->left, value);
            }
            return node;
        }
};


#endif // BST_H