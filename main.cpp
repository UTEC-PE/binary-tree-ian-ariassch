#include <iostream>
#include "Tree.h"

using namespace std;

int main() {

    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(8);
    tree.remove(2);
    tree.enorder();
    return 0;
}
