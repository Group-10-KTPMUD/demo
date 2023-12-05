#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};
typedef Node* PNode;
typedef Node* LinkedList;

void InitList(LinkedList &H) {
    H = NULL;
}

bool isEmpty(LinkedList &H) {
    return (H == NULL);
}

PNode InsertAfter(LinkedList &H, PNode P, int x) {
    PNode Q = new Node;
    Q->data = x;
    if(H == NULL){
        H = Q;
        Q->next = NULL;
    }
    else{
        if(P == NULL) return NULL;
        Q->next = P->next;
        P->next = Q;
    }
    return Q;
}

PNode InsertBefore(LinkedList &H, PNode P, int x) {
    PNode Q = new Node;
    Q->data = x;
    if(H == NULL){
        H = Q;
        Q->next = NULL;
        return Q;
    }
    else{
        if(P == NULL) return NULL;
        Q->data = P->data;
        P->data = x;
        Q->next = P->next;
        P->next = Q;
    }
    return P;
}

PNode DeleteNote(LinkedList &H, PNode P){
    if(P == NULL) return NULL;
    if(H == P && P->next == NULL){
        H = NULL;
        delete P;
        return NULL;
    }
    else{
        if(H == P){
            H = P->next;
            delete P;
            return H;
        }
        else{
            PNode R = H;
            while(R->next != P) R = R->next;
            R->next = P->next;
            delete P;
            return R->next;
        }
    }
}

int GetSize(LinkedList &H){
    int cnt = 0;
    PNode P = H;
    while(P != NULL){
        ++cnt;
        P = P->next;
    }
    return cnt;
}

void Display(LinkedList H){
    while(H != NULL){
        cout << H->data;
        H = H->next;
    }
}

int main()
{
    LinkedList H = NULL;
    InitList(&H);
    PNode P = H;
    InsertAfter(&H, P, 5);
    Display(H);
    isEmpty(H);
    return 0;
}
