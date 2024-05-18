#pragma once

#include <iostream>
#include "set.h"
#include "binaryHeap.h"
#include "binaryTree.h"

using namespace std;

void printBinaryTreeMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Show maximum element\n";
    cout << "  5. Show minimum element\n";
    cout << "  6. Existence of element\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-6 to choose the action:\n";
}

void printBinaryHeapMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Existence of element\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-4 to choose the action:\n";
}

void printSetMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Existence of element\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-4 to choose the action:\n";
}

template<typename T>
void BinaryTreeMenu(T root) {
    BinaryTree<T> binaryTree(root);
    T elem = 0;

    string input;
    while (true) {
        printBinaryTreeMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: // Show elements
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                binaryTree.showDFS();

                break;
            case 2: // Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                binaryTree.add(value);

                break;
            case 3: // Remove element
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }
                binaryTree.remove(elem);

                break;
            case 4: // Show maximum element
                cout << "Maximum element is: " << binaryTree.maximum() << '\n';

                break;
            case 5: // Show minimum element
                cout << "Minimum element is: " << binaryTree.minimum() << '\n';

                break;
            case 6: // Existence of element
                if (binaryTree.existence(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not existence.\n";
                }

                break;
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    }
}

template<typename T>
void BinaryHeapMenu(T root) {
    BinaryHeap<T> binaryHeap(root);
    T elem = 0;

    string input;
    while (true) {
        printBinaryHeapMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: {// Show elements
                if (binaryHeap.getSize() == 0) {
                    cout << "Binary Heap is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                binaryHeap.show();

                break;
            }
            case 2: {// Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                binaryHeap.add(value);

                break;
            }
            case 3: {// Remove element
                if (binaryHeap.getSize() == 0) {
                    cout << "Binary Heap is empty.\n";
                    break;
                }
                binaryHeap.remove(elem);

                break;
            }
            case 4: {// Existence of element
                if (binaryHeap.existence(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not existence.\n";
                }

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    }
}

template<typename T>
void SetMenu(T initElement) {
    Set<T> set(initElement);
    T elem = 0;

    string input;
    while (true) {
        printSetMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: {// Show elements
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                set.show();

                break;
            }
            case 2: {// Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                set.add(value);

                break;
            }
            case 3: {// Remove element
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }
                set.remove(elem);

                break;
            }
            case 4: {// Existence of element
                if (set.existence(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not existence.\n";
                }

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    }
}
