#pragma once

template<class T>
class BinaryHeap {
private:
    int size = 0;
    T *data = new T[1];

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

public:

    BinaryHeap(T elem) {
        data[0] = elem;
        this->size = 1;
    }

    ~BinaryHeap() {
        delete[] data;
        this->size = 0;
    }

    int getSize() {
        return this->size;
    }

    T getMinimum() {
        if (!this->size) {
            std::cout << "QUEUE IS EMPTY!";
            exit(1);
        }
        return this->data[0];
    }

    void add(T elem) {
        T *newdata = new T[this->size + 1];
        for (int i = 0; i < this->size; i++) {
            newdata[i] = this->data[i];
        }
        newdata[this->size] = elem;
        this->size++;
        delete[] this->data;
        this->data = newdata;
        this->siftUp(this->size - 1);
    }

    void changeElement(T oldelem, T newelem) {
        int index = -1;
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] == oldelem) index = i;
        }
        if (index < 0) {
            std::cout << "\nTHERE IS NO SUCH ELEMENT!\n";
            return;
        }
        this->data[index] = newelem;

        if (newelem < oldelem) {
            this->siftUp(index);
        } else {
            this->siftDown(index);
        }
    }

    void eraseMin() {
        if (this->size == 0) {
            std::cout << "HEAP IS EMPTY!";
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

    bool existence(T elem) const {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] == elem) return true;
        }
        return false;
    }

    void remove(T elem) {
        if (this->existence(elem) == false) {
            return;
        }
        T newElem = this->data[0];
        newElem--;
        this->changeElement(elem, newElem);
        this->eraseMin();
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

    void printAll() {
        for (int i = 0; i < this->size; i++) {
            std::cout << data[i] << " ";
        }
    }
};
