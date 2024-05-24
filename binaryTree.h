#pragma once

#include <iostream>
#include "structures.h"
#include "func.h"

template<typename T>
class BinaryTree {
private:
    struct node {
        node *parent = nullptr;
        node *left = nullptr;
        node *right = nullptr;
        T elem = T();
    };
    node *root = nullptr;
    size_t size = 0;

private:
    void destructor(node *nodePtr) {
        if (nodePtr == nullptr) return;

        if (nodePtr->left != nullptr) {
            destructor(nodePtr->left);
            delete nodePtr->left;
        }
        if (nodePtr->right != nullptr) {
            destructor(nodePtr->right);
            delete nodePtr->right;
        }
    }

    node *search(T elem) {
        node *nodePtr = this->root;
        while (nodePtr != nullptr) {
            if (elem < nodePtr->elem) {
                nodePtr = nodePtr->left;
            } else if (elem > nodePtr->elem) {
                nodePtr = nodePtr->right;
            } else return nodePtr;
        }
        return nullptr;
    }

    void removeElement(node *delNode_) {
        node *delNode = delNode_;
        if (delNode == nullptr) return;
        if (delNode->right == nullptr && delNode->left == nullptr) {
            if (delNode == this->root) {
                delete delNode;
                this->root = nullptr;
            } else {
                if (delNode->parent->right == delNode) delNode->parent->right = nullptr;
                else delNode->parent->left = nullptr;
                delete delNode;
            }
        } else if (delNode->right != nullptr && delNode->left == nullptr) {
            if (delNode == this->root) {
                delNode->right->parent = nullptr;
                this->root = delNode->right;
            } else {
                if (delNode->parent->left == delNode) delNode->parent->left = delNode->right;
                else delNode->parent->right = delNode->right;
                delNode->right->parent = delNode->parent;
            }
            delete delNode;
        } else if (delNode->right == nullptr && delNode->left != nullptr) {
            if (delNode == this->root) {
                delNode->left->parent = nullptr;
                this->root = delNode->left;
            } else {
                if (delNode->parent->left == delNode) delNode->parent->left = delNode->left;
                else delNode->parent->right = delNode->left;
                delNode->left->parent = delNode->parent;
            }
            delete delNode;
        } else if (delNode->right != nullptr && delNode->left != nullptr) {
            node *swapNode = next(delNode);
            T tmp_value = delNode->elem;
            delNode->elem = swapNode->elem;
            swapNode->elem = tmp_value;
            this->removeElement(swapNode);
        }
    }

    node *next(node *nodePtr) {
        if (nodePtr == nullptr) return nullptr;
        if (nodePtr->right != nullptr) {
            nodePtr = nodePtr->right;
            while (nodePtr->left != nullptr) {
                nodePtr = nodePtr->left;
            }
            return nodePtr;
        } else if (nodePtr->parent->left == nodePtr) {
            return nodePtr->parent;
        } else return nullptr;
    }

    void showDFS(node *nodePtr) {
        if (nodePtr == nullptr) return;
        if (nodePtr->left != nullptr) {
            showDFS(nodePtr->left);
            std::cout << "\nLEFT " << nodePtr->left->elem << " | PARENT " << nodePtr->left->parent->elem;
        }
        if (nodePtr->right != nullptr) {
            showDFS(nodePtr->right);
            std::cout << "\nRIGHT " << nodePtr->right->elem << " | PARENT " << nodePtr->right->parent->elem;
        }
    }

    void Map(node *nodePtr) {
        if (nodePtr == nullptr) {
            return;
        }
        if (nodePtr->left != nullptr) {
            Map(nodePtr->left);
            helpFuncMap(nodePtr->left->elem);
        }
        if (nodePtr->right != nullptr) {
            Map(nodePtr->right);
            helpFuncMap(nodePtr->right->elem);
        }
    }

    void Where(node *nodePtr) {
        if (nodePtr == nullptr) {
            return;
        }
        if (nodePtr->left != nullptr) {
            Where(nodePtr->left);
            if (!helpFuncWhere(nodePtr->left->elem)) {
                removeElement(nodePtr->left->elem);
            }
        }
        if (nodePtr->right != nullptr) {
            Where(nodePtr->right);
            if (!helpFuncWhere(nodePtr->right->elem)) {
                removeElement(nodePtr->left->elem);
            }
        }
    }

    void getFullname(node *nodePtr) {
        if (nodePtr == nullptr) {
            return;
        } else {
            std::cout << "\nFirst name: " << nodePtr->elem.getFirstName();
            std::cout << "\nSecond name: " << nodePtr->elem.getSecondName();
            std::cout << "\nLast name: " << nodePtr->elem.getLastName();
        }
    }

    void printAll(node *nodePtr) {
        if (nodePtr == nullptr) return;
        if (nodePtr->left != nullptr) {
            printAll(nodePtr->left);
        }
        std::cout << nodePtr->elem << " ";
        if (nodePtr->right != nullptr) {
            printAll(nodePtr->right);
        }
    }

public:
    BinaryTree() = default;

    BinaryTree(const T rootElem) {
        this->root = new node;
        this->root->elem = rootElem;
        size = 1;
    }

    ~BinaryTree() {
        destructor(this->root);
        size = 0;
        delete this->root;
    }

    void addElement(const T elem) {
        node *nodePtr = this->root;
        this->size++;
        if (this->root == nullptr) {
            this->root = new node;
            this->root->elem = elem;
            return;
        }
        while (nodePtr != nullptr) {
            if (elem < nodePtr->elem) {
                if (nodePtr->left != nullptr) {
                    nodePtr = nodePtr->left;
                } else {
                    nodePtr->left = new node;
                    nodePtr->left->elem = elem;
                    nodePtr->left->parent = nodePtr;
                    break;
                }
            } else {
                if (nodePtr->right != nullptr) {
                    nodePtr = nodePtr->right;
                } else {
                    nodePtr->right = new node;
                    nodePtr->right->elem = elem;
                    nodePtr->right->parent = nodePtr;
                    break;
                }
            }
        }
    }

    void removeElement(T elem) {
        node *delNode = search(elem);
        if (delNode == nullptr) return;

        removeElement(delNode);
        --this->size;
    }

    T maxElement() {
        node *nodePtr = this->root;
        if (this->root == nullptr) {
            return T();
        }
        while (nodePtr->right != nullptr) {
            nodePtr = nodePtr->right;
        }
        return nodePtr->elem;
    }

    T minElement() {
        if (this->root == nullptr) {
            return T();
        }
        node *nodePtr = this->root;
        while (nodePtr->left != nullptr) {
            nodePtr = nodePtr->left;
        }
        return nodePtr->elem;
    }

    bool existenceOfElement(const T elem) {
        if (search(elem) != nullptr) {
            return true;
        } else return false;
    }

    void showDFS() {
        if (this->root == nullptr) return;
        showDFS(this->root);
        std::cout << "\nROOT " << this->root->elem;
    }

    T next(const T elem) {
        node *nodePtr = search(elem);
        nodePtr = next(nodePtr);
        if (nodePtr == nullptr) return 0;
        return nodePtr->elem;
    }

    [[nodiscard]] size_t getSize() const {
        return this->size;
    }

    void Map() {
        if (this->root == nullptr) return;
        Map(this->root);
        helpFuncMap(this->root->elem);
    }

    void Where() {
        if (this->root == nullptr) return;
        if (helpFuncWhere(this->root->elem)) {
            Where(this->root);
        }
    }

    void getFullname(T ID) {
        node *nameNode = search(ID);
        if (nameNode == nullptr) {
            return;
        }
        getFullname(nameNode);
    }

    void printAll() {
        if (this->root == nullptr) return;
        printAll(this->root);
    }
};