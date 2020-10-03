#include <iostream>
using namespace std;
struct SNode{
    int value;
    struct SNode* pNext;
};

struct SList{
    SNode* pHead;
    SNode* pTail;
};


void Initialize(SList** w_list){
    *w_list = new SList{nullptr,nullptr};
}

// Function to create a node with a specific value
SNode* getNode(int r_value){
    SNode* p = new SNode;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    p->value = r_value;
    p->pNext = nullptr;
    return p;
}

// Function to add the node in a linkedlist
void insertLast(SList* w_list, int r_value){
    SNode* p = getNode(r_value);
    if(w_list->pHead == nullptr){
        w_list->pHead = w_list->pTail = p;
    }
    else{
	    w_list->pTail->pNext = p;
	    w_list->pTail = p;        
    }
}

void insertFirst(SList* w_list, int r_value){
    SNode* p = getNode(r_value);
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    if(w_list->pTail == nullptr){
        w_list->pHead = w_list->pTail = p;
    }
    else{
        p->pNext = w_list->pHead;
        w_list->pHead = p;
    }
}

// Function to print all values of nodes in linked list
void printList(SList* r_list){
    if(r_list == nullptr){
        cout << "\nEmpty.";
    }
    SNode* node = r_list->pHead;
    while(node != nullptr){
        cout << node->value <<" ";
        node = node->pNext;
    } 
}

void Input(SList* w_list, int n){
    for(int i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        insertLast(w_list,value);
    }
}

// Deinitialize linked list function
void deinitialize(SList** w_list){
    if((*w_list) == nullptr){
        return;
    }
    else{
        for(SNode* p = (*w_list)->pHead; p != nullptr ;){
            SNode* next = p->pNext;
            p = next;
        }
    }
    delete *w_list;
    *w_list = nullptr;
}

int Length(SList* r_list){
    SNode* p = r_list->pHead;
    if(!p){
        cout << "\nNot enough memory";
        return 0;
    }
    int length = 0;
    while(p != nullptr){
        length++;
        p = p->pNext;
    }
    return length;
}

void insertAt(SList* u_list, int r_value, int pos){
    SNode* q = getNode(r_value);
    if(!q){
        cout << "\nNot enough memory.";
        exit(0);
    }
    if(pos == 0){
        insertFirst(u_list,r_value);
    }
    else if(pos == Length(u_list) - 1){
        insertLast(u_list,r_value);
    }
    else{
        SNode* p = u_list->pHead;
        for(int i = 0; i < pos-1; i++){
            p = p->pNext;
        }
        q->pNext = p->pNext;
        p->pNext = q;
    }
}

void deleteFirst(SList* u_list){
    SNode* p = u_list->pHead;
    if(p == nullptr){
        cout << "\nList is empty.";
        exit(0);
    }
    else{
        u_list->pHead = u_list->pHead->pNext;
        delete p;
    }
}

void deleteLast(SList* u_list){
    SNode* p = u_list->pTail;
    if(p == nullptr){
        cout << "\nList is empty.";
        exit(0);
    }
    else{
        SNode* q = u_list->pHead;
        for(int i = 0; i < Length(u_list) - 2; i++){
            q = q->pNext;
        }
        u_list->pTail = q;
        q->pNext = nullptr;
        delete p;
        p = nullptr;
    }
}

void deleteAt(SList* u_list, int r_pos){
    if(r_pos == 0){
        deleteFirst(u_list);
    }
    else if(r_pos == Length(u_list) - 1){
        deleteLast(u_list);
    }
    else{
        SNode* prev = u_list->pHead;
        for(int i = 0; i < r_pos-1; i++){
            prev = prev->pNext;
        }
        SNode* del = prev->pNext;
        SNode* next = del->pNext;
        prev->pNext = next;
        delete del;
    }
}

int returnValue(SList* r_list, int r_pos){
    SNode* p = r_list->pHead;
    if(!p){
        cout <<"\nNot enough memory.";
        exit(0);
    }
    for(int i = 0; i < r_pos; i++){
        p = p->pNext;
    }
    return p->value;
}

SNode* findNode(SList* r_list, int r_value){
    SNode* p = r_list->pHead;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    while(p->value != r_value){
        p = p->pNext;
    }
    return p;
}

void changeNodeValue(SList* r_list, int a, int b){
    SNode* p = r_list->pHead;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    while(p != nullptr){
        if(p->value == a){
            p->value = b;
        }
        p = p->pNext;
    }
}

void deleteGreaterNode(SList* r_list, int r_pos){
    int pivot = returnValue(r_list,r_pos);
    SNode* p = r_list->pHead;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    int i = 0;
    while(p != nullptr){
        if(returnValue(r_list,i) > pivot){
            p = p->pNext;
            deleteAt(r_list,i);
        }
        else{
            i++;
            p = p->pNext;
        }
    }
}

int main(){
    SList* randomList;
    Initialize(&randomList);
    int n = 0;
    cin >> n;
    Input(randomList,n);
    int k = 0;
    cin >> k;
    deleteGreaterNode(randomList,k);
    printList(randomList);
    deinitialize(&randomList);
    return 0;
}