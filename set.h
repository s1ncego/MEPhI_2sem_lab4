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

    void addElement(const T elem) {
        if (this->existenceOfElement(elem) == true) {
            return;
        }
        this->set->addElement(elem);
    }

    bool existenceOfElement(const T elem) const {
        return this->set->existenceOfElement(elem);
    }

    void removeElement(const T elem) {
        if (this->existenceOfElement(elem) == true) {
            this->set->removeElement(elem);
        }
    }

    void show() const {
        this->set->printAll();
    }

    int getSize() {
        return this->set->getSize();
    }
};
