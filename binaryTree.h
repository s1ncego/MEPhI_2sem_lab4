#pragma once

template<typename T>
class BinaryTree {
private:
    struct node {
        node *parent = nullptr;
        node *left = nullptr;
        node *right = nullptr;
        T elem = T(0);
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

    node *search(const T elem) {
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

    void remove(node *delNode_) {
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
            this->remove(swapNode);
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

    void add(const T elem) {
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

    void remove(T elem) {
        node *delNode = search(elem);
        if (delNode == nullptr) return;

        remove(delNode);
        --this->size;
    }

    T minimum() {
        if (this->root == nullptr) return T(0);
        node *nodePtr = this->root;
        while (nodePtr->left != nullptr) {
            nodePtr = nodePtr->left;
        }
        return nodePtr->elem;
    }

    T maximum() {
        node *nodePtr = this->root;
        if (this->root == nullptr) {
            return T(0);
        }
        while (nodePtr->right != nullptr) {
            nodePtr = nodePtr->right;
        }
        return nodePtr->elem;
    }

    bool existence(const T elem) {
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

    void printAll() {
        if (this->root == nullptr) return;
        printAll(this->root);
    }
};