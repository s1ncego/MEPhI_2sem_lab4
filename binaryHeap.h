#pragma once

#include "func.h"

template<class T>
class BinaryHeap {
private:
    size_t size;
    T *data;

private:

    void siftUp(const int index) {
        T tmp;
        int i = index;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (this->data[parent] > this->data[i]) {
                tmp = this->data[parent];
                this->data[parent] = this->data[i];
                this->data[i] = tmp;
            } else break;

            i = parent;
        }
    }

    void siftDown(const int index) {
        int i = index;
        int left, right;
        T tmp;
        int minChild;

        while (2 * i + 1 < this->size) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            minChild = left;

            if (right < this->size && this->data[right] < this->data[left]) minChild = right;
            if (this->data[i] <= this->data[minChild]) break;

            tmp = this->data[i];
            this->data[i] = this->data[minChild];
            this->data[minChild] = tmp;
            i = minChild;
        }
    }

    void GetFullname(const size_t index) {
        std::cout << "\nFirst name: " << this->data[index].getFirstName();
        std::cout << "\nSecond name: " << this->data[index].getSecondName();
        std::cout << "\nLast name: " << this->data[index].getLastName();
    }

public:

    BinaryHeap(T elem) {
        this->size = 1;
        data = new T[this->size];
        data[0] = elem;
    }

    ~BinaryHeap() {
        delete[] data;
        this->size = 0;
    }

    int getSize() {
        return this->size;
    }

    T getMinimum() {
        if (this->size == 0) {
            exit(1);
        }
        return this->data[0];
    }

    void addElement(T elem) {
        T *newdata = new T[this->size + 1];
        for (int i = 0; i < this->size; i++) {
            newdata[i] = this->data[i];
        }
        newdata[this->size] = elem;
        this->size++;

        delete[] data;
        this->data = newdata;
        this->siftUp(this->size - 1);
    }

    void changeElement(T oldElement, T newElement) {
        int index = -1;
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] == oldElement) index = i;
        }
        if (index < 0) {
            return;
        }
        this->data[index] = newElement;

        if (newElement < oldElement) {
            this->siftUp(index);
        } else {
            this->siftDown(index);
        }
    }

    void eraseMinimum() {
        if (this->size == 0) {
            exit(1);
        }
        T *newData = new T[this->size - 1];

        this->data[0] = this->data[this->size - 1];

        for (int i = 0; i < this->size - 1; i++) {
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->size--;
        this->data = newData;
        this->siftDown(0);
    }

    bool existenceOfElement(T elem) const {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] == elem) {
                return true;
            }
        }
        return false;
    }

    void removeElement(T elem) {
        if (this->existenceOfElement(elem) == false) {
            return;
        }
        T newElem = this->data[0];
        //newElem--;
        this->changeElement(elem, newElem);
        this->eraseMinimum();
    }

    void show() const {
        int tabulation_indicator = 2;
        int two_in_power = 2;
        if (this->size < 1) return;
        std::cout << "\nROOT " << this->data[0] << "\n";
        for (int i = 1; i < this->size; ++i) {
            if ((i - 1) % 2 == 0) {
                std::cout << "(LEFT " << this->data[i] << " | PARENT " << this->data[(i - 1) / 2] << ") ";
            } else std::cout << "(RIGHT " << this->data[i] << " | PARENT " << this->data[(i - 1) / 2] << ") ";
            if (tabulation_indicator == i) {
                two_in_power *= 2;
                tabulation_indicator += two_in_power;
                std::cout << "\n";
            }
        }
    }

    void Map() {
        for (size_t i = getSize(); i > 0; --i) {
            helpFuncMap(this->data[i]);
        }
        helpFuncMap(this->data[0]);
    }

    void Where() {
        for (int i = getSize(); i >= 0; --i) {
            if (!helpFuncWhere(this->data[i])) {
                removeElement(this->data[i]);
            }
        }
    }

    void getFullname(int ID) {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i].getID() == ID) {
                GetFullname(i);
            }
        }
    }
};
