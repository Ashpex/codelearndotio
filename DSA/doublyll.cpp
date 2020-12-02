#include <iostream>
using namespace std;
struct SNode{
    int value;
    struct SNode* pNext;
    struct SNode* pPrev;
};

struct DList{
    SNode* pHead;
    SNode* pTail;
};

void Initialize(DList** w_list){
    *w_list = new DList{nullptr,nullptr};
}

SNode* getNode(int r_value){
    SNode* p = new SNode;
    if(!p){
        cout << "\nNot enough memory";
        exit(0);
    }
    p->value = r_value;
    p->pNext = nullptr;
    p->pPrev = nullptr;
    return p;
}

void insertLast(DList* w_list, int r_value){
    SNode* p = getNode(r_value);
    if(!p){
        exit(0);
    }
    if(w_list->pHead == nullptr){
        w_list->pHead = w_list->pTail = p;
    }
    else{
        p->pPrev = w_list->pTail;
        w_list->pTail->pNext = p;
        w_list->pTail = p;
    }
}

void insertFirst(DList* w_list, int r_value){
    SNode* p = getNode(r_value);
    if(!p){
        exit(0);
    }
    if(w_list->pHead == nullptr){
        w_list->pHead = w_list->pTail = p;
    }
    else{
        w_list->pHead->pPrev = p;
        p->pNext = w_list->pHead;
        w_list->pHead = p;
    }
}

void Input(DList* w_list, int n){
    for(int i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        insertLast(w_list,value);
    }
}

void printList(DList* r_list){
    if(r_list == nullptr){
        cout <<"\nEmpty list.";
        exit(0);
    }
    SNode* node = r_list->pHead;
    while(node != nullptr){
        cout << node->value << " ";
        node = node->pNext;
    }
    cout << endl;
}

void deinitialize(DList** w_list){
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

int Length(DList* r_list){
    int length = 0;
    SNode* p = r_list->pHead;
    if(!p){
        exit(0);
    }
    while(p != nullptr){
        p=p->pNext;
        length++;
    }
    return length;
}

void InDeCrease(DList* w_list, int n){
    insertLast(w_list,1);
    for(int i = 2; i < n+1; i++){
        insertFirst(w_list, i);
        insertLast(w_list, i);
    }
}

void insertAt(DList* w_list, int r_pos, int r_value){
    if(r_pos == 0){
        insertFirst(w_list,r_value);
    }
    else if(r_pos == Length(w_list)){
        insertLast(w_list,r_value);
    }
    else{
        SNode* currentNode = w_list->pHead;
        for(int i = 0; i < r_pos; i++){
            currentNode = currentNode->pNext;
        }
        SNode* prevNode = currentNode->pPrev;
        SNode* insertNode = getNode(r_value);
        if(!insertNode){
            exit(0);
        }
        prevNode->pNext = insertNode;
        insertNode->pPrev = prevNode;
        insertNode->pNext = currentNode;
        currentNode->pPrev = insertNode;
    }
}

void deleteFirst(DList* w_list){
    SNode* p = w_list->pHead;
    if(!p){
        cout << "\nNot enough memory";
        exit(0);
    }
    w_list->pHead = w_list->pHead->pNext;
    w_list->pHead->pPrev = nullptr;
    delete p;
}

void deleteLast(DList* w_list){
    SNode* p = w_list->pTail;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    w_list->pTail = w_list->pTail->pPrev;
    w_list->pTail->pNext = nullptr;
    delete p;
}

void deleteAt(DList* w_list, int r_pos){
    SNode* p = w_list->pHead;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    if(r_pos == 0){
        deleteFirst(w_list);
    }
    else if(r_pos == Length(w_list) - 1){
        deleteLast(w_list);
    }
    else{
        for(int i = 0; i < r_pos; i++){
            p = p->pNext;
        }
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
        delete p;
    }
}

int main(){
    DList* randomList;
    Initialize(&randomList);
    int n = 0;
    cin >> n;
    Input(randomList,n);
    printList(randomList);
    int k = 0;
    cin >> k;
    deleteAt(randomList,k);
    printList(randomList);
    deinitialize(&randomList);
    return 0;
}