#include <iostream>
#include <algorithm>    
#include <vector>
#include <random>
#include <assert.h>

#include "Tree.h"

using namespace std;

#define RANGE_MIN 100
#define RANGE_MAX 500
#define MIN_NUMBER 0
#define MAX_NUMBER 500

mt19937 rng;
vector<int> helper;

int generateRandomInt(int min, int max);
void insertIntoTree(Tree &tester);
void removeFromTree(Tree &tester);
void sortAndPruneHelper();
bool testTreeCompletion(Tree* tester);
void print(Tree* tester);

/**
 * No te olvides de subir a master la próxima vez
*/

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tBinary Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tree tester;
    const int numberOfElements = generateRandomInt(RANGE_MIN, RANGE_MAX);
    for (int i = 0; i < numberOfElements; i++) {
        insertIntoTree(tester);
    }
    sortAndPruneHelper();

    tester.preorder();
    cout << endl;
    tester.enorder();
    cout << endl;
    tester.postorder();

    //assert(tester.getWeight() == helper.size() && "Something is wrong with the insert or weight method");

    /*assert(testTreeCompletion(&tester) && "Something is wrong with the insert method or the iterator");

    const int elementsToRemove = generateRandomInt(0, helper.size() - 1);
    for (int i = 0; i < elementsToRemove; i++) {
        removeFromTree(tester);
    }

    assert(testTreeCompletion(&tester) && "Something is wrong with the remove method or the iterator");

    print(&tester);*/

    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

void insertIntoTree(Tree &tester) {
    const int numberToInsert = generateRandomInt(MIN_NUMBER, MAX_NUMBER);
    helper.push_back(numberToInsert);
    tester.insert(numberToInsert);
}

void removeFromTree(Tree &tester) {
    const int positionToRemove = generateRandomInt(0, helper.size() - 1);
    const int element = helper.at(positionToRemove);
    helper.erase(helper.begin() + positionToRemove);
    tester.remove(element);
}

void sortAndPruneHelper() {
    sort(helper.begin(), helper.end());
    auto last = std::unique(helper.begin(), helper.end());
    helper.erase(last, helper.end()); 
}
/*
bool testTreeCompletion(Tree* tester) {
    int i = 0;
    for (Iterator<int> it = tester->begin(); it != tester->end(); ++it) {
        if (*it != helper.at(i)) {
            return false;
        }
        i++;
    }
    return true;
}

void print(Tree* tester) {
    for (Iterator<int> it = tester->begin(); it != tester->end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < helper.size(); i++) {
        cout << helper.at(i) << " ";
    }
    cout << endl;
}*/