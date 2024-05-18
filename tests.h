#pragma once

#include  <iostream>
#include <cassert>
#include "set.h"

void Test() {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ~~~~~~~~~~BINARY TREE TEST~~~~~~~~~~
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    BinaryTree<int> binaryTree(5);
    assert(binaryTree.existenceOfElement(5) == true);
    assert(binaryTree.getSize() == 1);
    assert(binaryTree.minElement() == binaryTree.maxElement());

    binaryTree.addElement(4);
    binaryTree.addElement(6);
    assert(binaryTree.existenceOfElement(4) == true);
    assert(binaryTree.existenceOfElement(6) == true);
    assert(binaryTree.getSize() == 3);
    assert(binaryTree.minElement() == 4);
    assert(binaryTree.maxElement() == 6);

    binaryTree.removeElement(4);
    assert(binaryTree.existenceOfElement(4) == false);
    assert(binaryTree.existenceOfElement(5) == true);
    assert(binaryTree.existenceOfElement(6) == true);
    assert(binaryTree.getSize() == 2);
    assert(binaryTree.minElement() == 5);
    assert(binaryTree.maxElement() == 6);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ~~~~~~~~~~BINARY HEAP TEST~~~~~~~~~~
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    BinaryHeap<int> binaryHeap(5);
    assert(binaryHeap.existenceOfElement(5) == true);
    assert(binaryHeap.getSize() == 1);
    assert(binaryHeap.getMinimum() == 5);

    binaryHeap.addElement(6);
    binaryHeap.addElement(4);
    assert(binaryHeap.getSize() == 3);
    assert(binaryHeap.getMinimum() == 4);
    assert(binaryHeap.existenceOfElement(5) == true);
    assert(binaryHeap.existenceOfElement(6) == true);

    binaryHeap.removeElement(4);
    assert(binaryHeap.existenceOfElement(4) == false);
    assert(binaryHeap.getSize() == 2);
    assert(binaryHeap.existenceOfElement(5) == true);
    assert(binaryHeap.existenceOfElement(6) == true);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ~~~~~~~~~~~~~~SET TEST~~~~~~~~~~~~~~
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    Set<int> set(5);
    assert(set.existenceOfElement(5) == true);
    assert(set.getSize() == 1);

    set.addElement(4);
    set.addElement(6);
    assert(set.existenceOfElement(4) == true);
    assert(set.existenceOfElement(5) == true);
    assert(set.existenceOfElement(6) == true);
    assert(set.getSize() == 3);

    set.removeElement(5);
    assert(set.existenceOfElement(4) == true);
    assert(set.existenceOfElement(5) == false);
    assert(set.existenceOfElement(6) == true);
    assert(set.getSize() == 2);
}
