#include "BST.h"
#include <iostream>

int main() {
    BST t;
    t.insertIterative(4);
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(5);
    t.print();

    return 0;
}