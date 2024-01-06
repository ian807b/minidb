#include <iostream>

#include "BPlusTree.h"

using namespace std;

// Function Prototypes
void simpleTest();

int main() {
  simpleTest();
  cout << endl;
}

// void simpleTest() {
//   BPlusTree bp1(4);

//   // Insert, remove and find
//   bp1.insert(7, "seven");
//   bp1.insert(1, "one");
//   bp1.insert(3, "three");
//   bp1.insert(9, "nine");
//   bp1.insert(5, "five");
//   cout << "find 3: " << bp1.find(3) << " (three)" << endl;
//   bp1.remove(7);
//   cout << "find 7: " << bp1.find(7) << " (<empty>)" << endl << endl;

//   // Printing
//   bp1.printKeys();
//   cout << endl << "CHECK" << endl;
//   cout << "[5]" << endl;
//   cout << "[1 3] [5 9]" << endl << endl;
//   bp1.printValues();
//   cout << endl << "CHECK" << endl;
//   cout << "one" << endl << "three" << endl << "five" << endl << "nine" <<
//   endl;

//   // Copy constructor and op=
//   BPlusTree bp2(bp1);
//   BPlusTree bp3(7);
//   bp3.insert(13, "thirteen");
//   bp3 = bp1;

//   cout << endl << "simple test complete" << endl;
// }

void simpleTest() {
  BPlusTree bp1(3);

  bp1.insert(2, "two");
  bp1.insert(21, "twenty one");
  // bp1.insert(11, "eleven");
  // bp1.insert(8, "eight");
  // bp1.insert(64, "sixty four");
  // bp1.insert(5, "five");
  // bp1.insert(23, "twenty three");
  // bp1.insert(6, "six");
  // bp1.insert(19, "nineteen");
  // bp1.insert(9, "nine");
  // bp1.insert(7, "seven");

  // int maxSize;
  // int curSize;
  // vector<int> keys;
  // vector<string> values;
  // vector<Node*> child;
  // Node* next;
  // Node* parent;
  // bool isLeaf;
  Node* child1 = new Node(3);
  Node* child2 = new Node(3);

  child1->keys = {11, 22};
  child2->keys = {33, 44};
  child1->curSize = child2->curSize = 2;
  child1->next = child2;
  child1->isLeaf = child2->isLeaf = true;
  child1->parent = child2->parent = bp1.root;
  bp1.root->child = {child1, child2};
  bp1.root->isLeaf = false;

  bp1.printKeys();
}