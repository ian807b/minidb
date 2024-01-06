#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Node {
 public:
  int maxSize;
  int curSize;
  vector<int> keys;
  vector<string> values;
  vector<Node*> child;
  Node* next;
  Node* parent;
  bool isLeaf;

  Node(int nodeSize);
};

class BPlusTree {
  //  private:
 public:
  Node* root;

  // Helper methods
  Node* findNode(int key);
  void splitLeaf(Node* node);
  int findIndex(const vector<int>& keys, int newKey);

  //  public:
  BPlusTree(int nodeSize);
  bool insert(int key, string val);
  void printNode(const Node* curNode);
  void printKeys();
  // TODO:
  // bool remove(int keyInput);
  // string find(int keyInput);
  // void printValues();
};