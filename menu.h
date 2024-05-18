#pragma once

#include <iostream>
#include "set.h"
#include "binaryHeap.h"
#include "binaryTree.h"
#include "structures.h"

using namespace std;

void printBinaryTreeMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Show maxElement element\n";
    cout << "  5. Show minElement element\n";
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

void printBinaryTreePersonMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Show maxElement element\n";
    cout << "  5. Show minElement element\n";
    cout << "  6. Existence of element\n";
    cout << "  7. Get FIO\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-7 to choose the action:\n";
}

void printBinaryHeapPersonMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Existence of element\n";
    cout << "  5. Get FIO\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-5 to choose the action:\n";
}

void printSetPersonMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Existence of element\n";
    cout << "  5. Get FIO\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-5 to choose the action:\n";
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
            case 1: {// Show elements
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                binaryTree.showDFS();

                break;
            }
            case 2: {// Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                binaryTree.addElement(value);

                break;
            }
            case 3: {// Remove element
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                binaryTree.removeElement(elem);

                break;
            }
            case 4: {// Show maxElement element
                cout << "Maximum element is: " << binaryTree.maxElement() << '\n';

                break;
            }
            case 5: {// Show minElement element
                cout << "Minimum element is: " << binaryTree.minElement() << '\n';

                break;
            }
            case 6: {// Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (binaryTree.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
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
                binaryHeap.addElement(value);

                break;
            }
            case 3: {// Remove element
                if (binaryHeap.getSize() == 0) {
                    cout << "Binary Heap is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                binaryHeap.removeElement(elem);

                break;
            }
            case 4: {// Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (binaryHeap.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
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
                set.addElement(value);

                break;
            }
            case 3: {// Remove element
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                set.removeElement(elem);

                break;
            }
            case 4: {// Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (set.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
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
void BinaryTreePersonMenu(T root, Person person) {
    BinaryTree<T> binaryTree(root);
    T elem = 0;

    string input;
    while (true) {
        printBinaryTreePersonMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: { // Show elements
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                binaryTree.showDFS();

                break;
            }
            case 2: { // Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                binaryTree.addElement(value);

                break;
            }
            case 3: { // Remove element
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                binaryTree.removeElement(elem);

                break;
            }
            case 4: { // Show maxElement element
                cout << "Maximum element is: " << binaryTree.maxElement() << '\n';

                break;
            }
            case 5: { // Show minElement element
                cout << "Minimum element is: " << binaryTree.minElement() << '\n';

                break;
            }
            case 6: { // Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (binaryTree.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 7: { // Get FIO
                cout << "Enter the Person ID to get FIO: ";
                cin >> elem;

                if (binaryTree.existenceOfElement(elem) == false) {
                    cout << "\nUnknown ID, try again.\n";
                } else {
                    cout << "\nFirst name: " << person.getFirstName() << '\n' << "Second name: "
                         << person.getSecondName() << '\n' << "Last name: " << person.getLastName() << '\n';
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
void BinaryHeapPersonMenu(T root, Person person) {
    BinaryHeap<T> binaryHeap(root);
    T elem = 0;

    string input;
    while (true) {
        printBinaryHeapPersonMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: { // Show elements
                if (binaryHeap.getSize() == 0) {
                    cout << "Binary Heap is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                binaryHeap.show();

                break;
            }
            case 2: { // Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                binaryHeap.addElement(value);

                break;
            }
            case 3: { // Remove element
                if (binaryHeap.getSize() == 0) {
                    cout << "Binary Heap is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                binaryHeap.removeElement(elem);

                break;
            }
            case 4: { // Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (binaryHeap.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 5: { // Get FIO
                cout << "Enter the Person ID to get FIO: ";
                cin >> elem;

                if (binaryHeap.existenceOfElement(elem) == false) {
                    cout << "\nUnknown ID, try again.\n";
                } else {
                    cout << "\nFirst name: " << person.getFirstName() << '\n' << "Second name: "
                         << person.getSecondName() << '\n' << "Last name: " << person.getLastName() << '\n';
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
void SetPersonMenu(T initElement, Person person) {
    Set<T> set(initElement);
    T elem = 0;

    string input;
    while (true) {
        printSetPersonMenu();
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
                set.addElement(value);

                break;
            }
            case 3: {// Remove element
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                set.removeElement(elem);

                break;
            }
            case 4: {// Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (set.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 5: { // Get FIO
                cout << "Enter the Person ID to get FIO: ";
                cin >> elem;

                if (set.existenceOfElement(elem) == false) {
                    cout << "\nUnknown ID, try again.\n";
                } else {
                    cout << "\nFirst name: " << person.getFirstName() << '\n' << "Second name: "
                         << person.getSecondName() << '\n' << "Last name: " << person.getLastName() << '\n';
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