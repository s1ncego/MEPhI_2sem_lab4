#pragma once

#include "binaryTree.h"

template<typename T>
class Set {
private:
    BinaryTree<T> *set;

public:
    Set(const T elem) {
        this->set = new BinaryTree<T>(elem);
    }

    ~Set() = default;

    void add(const T elem) {
        if (this->existence(elem) == true) {
            return;
        }
        this->set->add(elem);
    }

    bool existence(const T elem) const {
        return this->set->existence(elem);
    }

    void remove(const T elem) {
        if (this->existence(elem) == true) {
            this->set->remove(elem);
        }
    }

    void show() const {
        this->set->printAll();
    }

    int getSize() {
        return this->set->getSize();
    }
};
