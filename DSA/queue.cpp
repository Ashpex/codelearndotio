#include <iostream>
#include <math.h>
using namespace std;

struct SNode{
    int data;
    SNode* pNext;
};

struct Queue{
    SNode* front;
    SNode* back;
};

void Initialize(Queue** w_queue){
    *w_queue = new Queue{nullptr,nullptr};
}

SNode* getNode(int r_value){
    SNode* p = new SNode;
    if(!p){
        cout << "\nNot enough memory" << endl;
        exit(0);
    }
    p->data = r_value;
    p->pNext = nullptr;
    return p;
}

int Size(Queue* r_queue){
    int size = 0;
    SNode* p = r_queue->front;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    while(p != nullptr){
        p=p->pNext;
        size++;
    }
    delete p;
    return size;
}

int Front(Queue* r_queue){
    if(r_queue->front == nullptr){
        cout << "\nQueue is empty.";
        exit(0);
    }
    else return r_queue->front->data;
}

int Back(Queue* r_queue){
    if(r_queue->front == nullptr){
        cout << "\nQueue is empty.";
        exit(0);
    }
    if(r_queue->front == r_queue->back){
        return r_queue->front->data;
    }
    else return r_queue->back->data;
}

bool isEmpty(Queue* r_queue){
    if(r_queue->front == nullptr){
        return true;
    }
    else return false;
}

void Push(Queue* u_queue, int r_value){
    SNode* p = getNode(r_value);
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    if(u_queue->front ==  nullptr){
        u_queue->front = u_queue->back = p;
    }
    else{
        u_queue->back->pNext = p;
        u_queue->back = p;
    }
}

int Pop(Queue* u_queue){
    int value = u_queue->front->data;
    SNode* p = u_queue->front;
    u_queue->front = u_queue->front->pNext;
    delete p;
    return value;
}

void Deinit(Queue* w_queue){
    while (!isEmpty(w_queue)){
       Pop(w_queue);
    }   
}

void Input(Queue* u_queue, int size){
    for(int i = 0; i < size; i++){
        int value = 0;
        cin >> value;
        Push(u_queue,value);    
    }
}

void Output(Queue* u_queue){
    SNode* p = u_queue->front;
    if(!p){
        cout << "\nStack is empty or not enough memory";
        exit(0);
    }
    while(p != nullptr){
        cout << p->data << " ";
        p = p->pNext;
    }
}

void Reverse(Queue* u_queue, int r_steps){
    for(int i = 0; i < r_steps; i++){
        int value = Pop(u_queue);
        Push(u_queue,value);
    }
}

bool isPrimeNumber(int r_value){
    if(r_value < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(r_value);i++){
        if(r_value%i == 0){
            return false;
        }
    }
    return true;
}

void isSuperPrimeNumber(Queue* u_queue, int r_value){
    for(int i = 0; i < r_value; i++){
        if(isPrimeNumber(i)){
            Push(u_queue,i);
        }
    }
    while(!isEmpty(u_queue)){
        for(int i = 1; i < 9; i++){
            int k = Front(u_queue)*10 + i;
            if(k <= r_value && isPrimeNumber(k)){
                Push(u_queue,Front(u_queue)*10+i);
            }
        }
        cout << Front(u_queue) << " " ;
        Pop(u_queue);
    }
}

int main(){
    Queue* randomQueue;
    Initialize(&randomQueue);
    int n = 0;
    cin >> n;
    isSuperPrimeNumber(randomQueue,n);
    Deinit(randomQueue);
    return 0;
}