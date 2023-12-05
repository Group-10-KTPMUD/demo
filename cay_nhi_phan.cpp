#include <bits/stdc++.h>

using namespace std;

struct Node {
    int info;
    Node* LP, *RP;
};
typedef Node* PNode;

typedef PNode BinaryTree;

void InitBT (BinaryTree &T) {
    T = NULL;
}