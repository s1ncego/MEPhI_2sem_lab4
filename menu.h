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
    cout << "  7. Map\n";
    cout << "  8. Where\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-8 to choose the action:\n";
}

void printBinaryTreePersonMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show people\n";
    cout << "  2. Add person\n";
    cout << "  3. Remove person\n";
    cout << "  4. Show maximum PersonID\n";
    cout << "  5. Show minimum PersonID\n";
    cout << "  6. Existence of person\n";
    cout << "  7. Get fullname of the person\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-7 to choose the action:\n";
}

void printMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Existence of element\n";
    cout << "  5. Map\n";
    cout << "  6. Where\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-6 to choose the action:\n";
}

void printPersonMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show people\n";
    cout << "  2. Add person\n";
    cout << "  3. Remove person\n";
    cout << "  4. Existence of person\n";
    cout << "  5. Get fullname of the person\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-5 to choose the action:\n";
}


template<typename T>
void BinaryTreeMenu(T root) {
    BinaryTree<T> binaryTree(root);
    T elem;

    string input;
    while (true) {
        printBinaryTreeMenu();
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

                cout << "Elements: \n";
                binaryTree.showDFS();

                break;
            }
            case 2: { // Add element
                T value;
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
            case 7: { // Map
                if (is_same<T, Person>()) {
                    cout << "Cannot use Map to the person!\n";
                    break;
                } else {
                    binaryTree.Map();
                }

                break;
            }
            case 8: { // Where
                if (is_same<T, Person>()) {
                    cout << "Cannot use Where to the person!\n";
                    break;
                } else {
                    binaryTree.Where();
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
void BinaryTreePersonMenu(T root) {
    BinaryTree<T> binaryTree(root);
    T elem;

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

                cout << "People: \n";
                binaryTree.showDFS();

                break;
            }
            case 2: { // Add element
                T value;
                cout << "\nEnter PersonID, first name, second name and last name of the person : \n";
                cin >> value;
                binaryTree.addElement(value);

                break;
            }
            case 3: { // Remove element
                if (binaryTree.getSize() == 0) {
                    cout << "Binary Tree is empty.\n";
                    break;
                }

                cout << "Enter the person to remove: ";
                cin >> elem;
                binaryTree.removeElement(elem);

                break;
            }
            case 4: { // Show maxElement element
                cout << "Maximum PersonID is: " << binaryTree.maxElement() << '\n';

                break;
            }
            case 5: { // Show minElement element
                cout << "Minimum PersonID is: " << binaryTree.minElement() << '\n';

                break;
            }
            case 6: { // Existence of element
                cout << "Enter the person to find: ";
                cin >> elem;

                if (binaryTree.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 7: { // Get FIO
                cout << "Enter the PersonID to find: ";
                int id;
                cin >> id;
                binaryTree.getFullname(id);

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
void BinaryHeapPersonMenu(T root) {
    BinaryHeap<T> binaryHeap(root);
    T elem;

    string input;
    while (true) {
        printPersonMenu();
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

                cout << "People:\n";
                binaryHeap.show();

                break;
            }
            case 2: { // Add element
                T value;
                cout << "\nEnter PersonID, first name, second name and last name of the person : \n";
                cin >> value;
                binaryHeap.addElement(value);

                break;
            }
            case 3: { // Remove element
                if (binaryHeap.getSize() == 0) {
                    cout << "Binary Heap is empty.\n";
                    break;
                }

                cout << "\nEnter PersonID, first name, second name and last name of the person : \n";
                cin >> elem;
                binaryHeap.removeElement(elem);

                break;
            }
            case 4: { // Existence of element
                cout << "Enter the person to find: ";
                cin >> elem;

                if (binaryHeap.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 5: { // Get FIO
                cout << "Enter the PersonID to find: ";
                int id;
                cin >> id;
                binaryHeap.getFullname(id);

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
        printMenu();
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
                T value;
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
            case 5: { // Map
                binaryHeap.Map();

                break;
            }
            case 6: { // Where
                binaryHeap.Where();

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
        printMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: { // Show elements
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "Elements:\n";
                set.show();

                break;
            }
            case 2: { // Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                set.addElement(value);

                break;
            }
            case 3: { // Remove element
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "Enter the element to remove: ";
                cin >> elem;
                set.removeElement(elem);

                break;
            }
            case 4: { // Existence of element
                cout << "Enter the element to find: ";
                cin >> elem;

                if (set.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 5: { // Map
                set.Map();

                break;
            }
            case 6: { // Where
                set.Where();

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
void SetPersonMenu(T initElement) {
    Set<T> set(initElement);
    T elem;

    string input;
    while (true) {
        printPersonMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: { // Show elements
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "People:\n";
                set.show();

                break;
            }
            case 2: { // Add element
                T value;
                cout << "\nEnter PersonID, first name, second name and last name of the person : \n";
                cin >> value;
                set.addElement(value);

                break;
            }
            case 3: { // Remove element
                if (set.getSize() == 0) {
                    cout << "Set is empty.\n";
                    break;
                }

                cout << "\nEnter PersonID, first name, second name and last name of the person : \n";
                cin >> elem;
                set.removeElement(elem);

                break;
            }
            case 4: { // Existence of element
                cout << "Enter the person to find: ";
                cin >> elem;

                if (set.existenceOfElement(elem) == true) {
                    cout << elem << " exists.\n";
                } else {
                    cout << elem << " does not exist.\n";
                }

                break;
            }
            case 5: { // Get FIO
                cout << "Enter the PersonID to find: ";
                int id;
                cin >> id;
                set.getFullname(id);

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    }
}

void startMenu() {
    cout << "\nAll tests completed successfully!\n";

    cout << "\n-~~~~==Hello!==~~~~-\n";
    cout << "Press 1 to run BinaryTree menu, Press 2 to run BinaryHeap menu, Press 3 to run Set menu:\n";
    int typeStructure;
    cin >> typeStructure;

    cout << "Press 1 to use Integer, Press 2 to use Float, Press 3 to use Person:\n";
    int typeElement;
    cin >> typeElement;

    if (typeElement == 1) {
        cout << "\nInput first element of structure: \n";
        int initInteger;
        cin >> initInteger;
        switch (typeStructure) {
            case 1: {
                BinaryTreeMenu(initInteger);

                break;
            }
            case 2: {
                BinaryHeapMenu(initInteger);

                break;
            }
            case 3: {
                SetMenu(initInteger);

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    } else if (typeElement == 2) {
        cout << "\nInput first element of structure: \n";
        double initFloat;
        cin >> initFloat;
        switch (typeStructure) {
            case 1: {
                BinaryTreeMenu(initFloat);

                break;
            }
            case 2: {
                BinaryHeapMenu(initFloat);

                break;
            }
            case 3: {
                SetMenu(initFloat);

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    } else if (typeElement == 3) {
        cout << "\nInput PersonID, first name, second name and last name of the first person : \n";
        Person person;
        cin >> person;

        switch (typeStructure) {
            case 1: {
                BinaryTreePersonMenu(person);

                break;
            }
            case 2: {
                BinaryHeapPersonMenu(person);

                break;
            }
            case 3: {
                SetPersonMenu(person);

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";

                break;
            }
        }
    } else {
        cout << "\nUnknown command, try again.\n";
    }
}


