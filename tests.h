#pragma once

#include  <iostream>
#include <cassert>
#include "set.h"

void Test() {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ~~~~~~~~~~BINARY TREE TEST~~~~~~~~~~
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    BinaryTree<int> binaryTree(5);
    assert(binaryTree.existence(5) == true);
    assert(binaryTree.getSize() == 1);
    assert(binaryTree.minimum() == binaryTree.maximum());

    binaryTree.add(4);
    binaryTree.add(6);
    assert(binaryTree.existence(4) == true);
    assert(binaryTree.existence(6) == true);
    assert(binaryTree.getSize() == 3);
    assert(binaryTree.minimum() == 4);
    assert(binaryTree.maximum() == 6);

    binaryTree.remove(4);
    assert(binaryTree.existence(4) == false);
    assert(binaryTree.existence(5) == true);
    assert(binaryTree.existence(6) == true);
    assert(binaryTree.getSize() == 2);
    assert(binaryTree.minimum() == 5);
    assert(binaryTree.maximum() == 6);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ~~~~~~~~~~BINARY HEAP TEST~~~~~~~~~~
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    BinaryHeap<int> binaryHeap(5);
    assert(binaryHeap.existence(5) == true);
    assert(binaryHeap.getSize() == 1);
    assert(binaryHeap.getMinimum() == 5);

    binaryHeap.add(6);
    binaryHeap.add(4);
    assert(binaryHeap.getSize() == 3);
    assert(binaryHeap.getMinimum() == 4);
    assert(binaryHeap.existence(5) == true);
    assert(binaryHeap.existence(6) == true);

    binaryHeap.remove(4);
    assert(binaryHeap.existence(4) == false);
    assert(binaryHeap.getSize() == 2);
    assert(binaryHeap.existence(5) == true);
    assert(binaryHeap.existence(6) == true);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ~~~~~~~~~~~~~~SET TEST~~~~~~~~~~~~~~
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    Set<int> set(5);
    assert(set.existence(5) == true);
    assert(set.getSize() == 1);

    set.add(4);
    set.add(6);
    assert(set.existence(4) == true);
    assert(set.existence(5) == true);
    assert(set.existence(6) == true);
    assert(set.getSize() == 3);

    set.remove(5);
    assert(set.existence(4) == true);
    assert(set.existence(5) == false);
    assert(set.existence(6) == true);
    assert(set.getSize() == 2);
}
