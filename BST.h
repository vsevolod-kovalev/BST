#include "BSTNode.h"
#include <iostream>
#include <queue>
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
    void insertIterative(const int& value) {
        BSTNode* node_to_insert = new BSTNode(value);
        if (root == nullptr) {
            root = node_to_insert;
            return;
        }
        BSTNode* current = root;
        while (current) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = node_to_insert;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = node_to_insert;
                    return;
                }
                current = current->right;
            }
        }

    }
    void insert(const int& value) {
        root = insert(root, value);
    }

    BSTNode* remove(BSTNode* node, const int& value) {
        if (!node) {
            return node;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                BSTNode* t = node->right;
                delete node;
                return t;
            } else if (node->right == nullptr) {
                BSTNode* t = node->left;
                delete node;
                return t;
            }
            BSTNode* min_node = findMin(node->right);
            node->value = min_node->value;
            node->right = remove(node->right, min_node->value);
        }
        return node;
    }

    void removeIterative(const int& value) {
        BSTNode* current = root;
        if (!current) {
            return;
        }
        if (!current->left && !current->right) {
            if (current->value == value) {
                delete current;
                root = nullptr;
            }
            return;
        }

        BSTNode* parent = nullptr;
        bool remove_from_left = true;

        while (current && current->value != value) {
            parent = current;
            if (value < current->value) {
                current = current->left;
                remove_from_left = true;
            } else {
                current = current->right;
                remove_from_left = false;
            }
        }
        if (!current) return;

        BSTNode* node_to_remove = current;
        BSTNode* replacementNode = nullptr;

        if (current->left && current->right) {
            BSTNode* minNode = current->right;
            BSTNode* minNodeParent = current;

            while (minNode->left) {
                minNodeParent = minNode;
                minNode = minNode->left;
            }

            node_to_remove->value = minNode->value;
            node_to_remove = minNode;
            parent = minNodeParent;
            remove_from_left = (minNodeParent->left == minNode);
        }

        replacementNode = (node_to_remove->left) ? node_to_remove->left : node_to_remove->right;

        if (parent == nullptr) {
            root = replacementNode;
        } else if (remove_from_left) {
            parent->left = replacementNode;
        } else {
            parent->right = replacementNode;
        }

        delete node_to_remove;
    }

    void remove(const int& value) {
        root = remove(root, value);
    }

    BSTNode* findMin(BSTNode* const node) const {
        BSTNode* current = node;
        while (current != nullptr && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    void print(const BSTNode* const node) const {
        if (!node) {
            return;
        }
        
        print(node->right);
        std::cout << node->value << std::endl;
        print(node->left);
        
    }
    void printBST() const {
        std::queue<BSTNode*> q;
        q.push(root);
        while (!q.empty()){
            BSTNode* current = q.front();
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
            std::cout << current->value << std::endl;
            q.pop();
        }
    }
    void print() {
        printBST();
    }

};


#endif // BST_H