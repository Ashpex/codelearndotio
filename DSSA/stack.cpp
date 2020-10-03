#include <iostream>
#include <string.h>
using namespace std;

struct SNode{
    char data;
    SNode* pNext;
};

struct Stack{
    SNode* top;
};

void Initialize(Stack** w_stack){
    *w_stack = new Stack{nullptr};
}

SNode* getNode(char r_value){
    SNode* p = new SNode;
    if(!p){
        cout << "\nNot enough memory";
        exit(0);
    }
    p->data = r_value;
    p->pNext = nullptr;
    return p;
}

bool isEmpty(const Stack* r_stack){
    if(r_stack->top == nullptr){
        return true;
    }
    else return false;
}

int size(const Stack* r_stack){
    int size = 0;
    SNode* p = r_stack->top;
    if(!p){
        cout << "\nNot enough memory.";
        exit(0);
    }
    while(p != nullptr){
        size++;
        p=p->pNext;
    }
    return size;
}

void Push(Stack* u_stack, char r_value){
    SNode* p = getNode(r_value);
    if(u_stack->top == nullptr){
        u_stack->top = p;
    }
    else{
        p->pNext = u_stack->top;
        u_stack->top = p;
    }
}

char Pop(Stack* u_stack){
    char ch = u_stack->top->data;
    SNode* p = u_stack->top;
    u_stack->top = u_stack->top->pNext;
    delete p;
    return ch;
}

char top(Stack* u_stack){
    return u_stack->top->data;
}

void reverse(Stack* u_stack, string randomString){
    for(int i = 0; i < randomString.length(); i++){
        Push(u_stack,randomString[i]);
    }
    while(!isEmpty(u_stack)){
        cout << Pop(u_stack);
    }
    cout << endl;    
}

void Deinit(Stack* w_stack){
    while (!isEmpty(w_stack)){
       Pop(w_stack);
    }   
}

string DecToBin(Stack* u_stack, int r_value){
    while(r_value > 0){
        int remainder = r_value % 2;
        Push(u_stack,remainder);
        r_value = r_value/2;
    }
    string binary;
    while(!isEmpty(u_stack)){
        int digit = Pop(u_stack);
        binary += to_string(digit);
    }
    return binary;
}

string encodeString(Stack* u_stack, string r_randomString){
    string result;
    for(int i = 0; i <= r_randomString.length(); i++){
        if(isEmpty(u_stack) || r_randomString[i] == top(u_stack)){
            Push(u_stack,r_randomString[i]);
        }
        else if(r_randomString[i] != top(u_stack)){
            int count = 0;
            result += top(u_stack);
            while(!isEmpty(u_stack)){
                Pop(u_stack);
                count ++;
            }
            result += to_string(count);
            Push(u_stack,r_randomString[i]);
        }
    }
    return result;
}

int main(){
    Stack* newStack;
    Initialize(&newStack);
    string randomString;
    getline(cin,randomString);
    cin.clear();
    cout << encodeString(newStack,randomString) << endl;
    Deinit(newStack);
    return 0;
}  