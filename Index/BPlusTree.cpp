#include "BPlusTree.h"

#include <iostream>

using std::cout;
using std::endl;

// Default Node contructor
Node::Node(int nodeSize) {
  maxSize = nodeSize;
  curSize = 0;
  child.resize(maxSize + 1, nullptr);
  next = nullptr;
  parent = nullptr;
  isLeaf = true;
}

// Default tree constructor
BPlusTree::BPlusTree(int nodeSize) { root = new Node(nodeSize); }

// Find the node where new key needs to go
Node* BPlusTree::findNode(int key) {
  Node* curNode = root;

  // When the tree has just the root
  if (curNode->isLeaf) {
    return curNode;
  }

  // When the tree has more than the root
  while (curNode->isLeaf == false) {
    for (int i = 0; i < curNode->curSize; i++) {
      if (key < curNode->keys[i]) {
        curNode = curNode->child[i];
      }
    }
  }

  return curNode;
}

int BPlusTree::findIndex(const vector<int>& keys, int newKey) {
  int low = 0;
  int high = keys.size();

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (keys[mid] < newKey) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

void BPlusTree::splitLeaf(Node* node) {
  // Splitting leaves

  // Update interior
}
// if (curNode->curSize == curNode->maxSize) {
//   if (curNode->isLeaf == true) {  // Leaf node split
//     Node* newNode = new Node(curNode->maxSize);
//     int splitIndex = (curNode->maxSize + 1) / 2;
//     int newKeyIndex = 0;

//     for (int i = 0; i < curNode->curSize; i++) {  // Find index for new key
//       if (key < curNode->keys[i]) {
//         newKeyIndex = i;
//         break;
//       }
//     }
//   }
// }

bool BPlusTree::insert(int key, string val) {
  Node* curNode = findNode(key);

  for (int i = 0; i < curNode->curSize; i++) {
    if (key == curNode->keys[i]) {
      cout << "Duplicate key cannot be inserted" << endl;
      return false;
    }
  }

  // Tree has just one root
  if (curNode->curSize == curNode->maxSize) {
    splitLeaf(curNode);
  } else {
    // TODO: Need to implement binary search for finding new key's position
    curNode->keys.insert(curNode->keys.begin() + findIndex(curNode->keys, key),
                         key);
    curNode->curSize++;
  }

  // Tree has more than the root

  return true;
}

void BPlusTree::printNode(const Node* curNode) {
  cout << "[";
  for (int i = 0; i < curNode->curSize; i++) {
    cout << curNode->keys[i];
    if (i < curNode->curSize - 1) {
      cout << ",";
    }
  }
  cout << "] ";
}

void BPlusTree::printKeys() {
  Node* curNode = root;
  Node* parentNode = root;
  Node* temp = curNode;
  int numOfLev = 1;

  if (curNode == nullptr) {
    cout << "Need to create a tree first" << endl;
  }

  // Find the depth
  while (temp->isLeaf == false) {
    temp = temp->child[0];
    numOfLev++;
  }

  if (numOfLev == 1) {  // When the tree has just the root
    printNode(curNode);
    cout << endl;
    return;
  } else if (numOfLev == 2) {  // When d = 2
    printNode(parentNode);
    cout << endl;
    for (int i = 0; i < parentNode->child.size(); i++) {
      printNode(parentNode->child[i]);
    }
  } else {  // When d > 2
    // Print first two levels
    printNode(parentNode);
    cout << endl;
    for (int i = 0; i < parentNode->child.size(); i++) {
      printNode(parentNode->child[i]);
    }
    cout << endl;
    // Print the rest from 3rd level from the top
    while (numOfLev - 2 > 0) {
      for (int i = 0; i < parentNode->child.size(); i++) {
        // curNode = child     
      }
    }
  }
}

// bool BPlusTree::remove(int keyInput) {}
// string BPlusTree::find(int keyInput) {}
// void BPlusTree::printValues() {}

// BPlusTree(int) – this constructor creates an empty tree;
// the parameter sets the number of keys that can be stored in each
// node(leaf and interior)

// bool insert(int, string) – inserts the key(int) and value(string) into the
// tree unless the key is in the tree; returns true if the insertion was
// successful and false otherwise

// bool remove(int) – searches the tree for the key (int); if found removes
// the key and associated value from the tree; returns true if the key was
// found and removed and false otherwise

// string find(int) – searches the tree for the key (int); if found returns
// the matching value(string), otherwise returns the empty string

// void printKeys() – prints the keys in each node with nodes of the same
// level appearing on the same line

// void printValues() – prints the values in key(not value) order