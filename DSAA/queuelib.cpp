#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

void Deinit(queue<int>& w_queue){
    while (!w_queue.empty()){
        w_queue.pop();
    }
}

void Input(queue<int>& u_queue, int size){
    for(int i = 0; i < size; i++){
        int value = 0;
        cin >> value;
        u_queue.push(value);    
    }
}

void Output(queue<int>& u_queue){
    queue<int> copy = u_queue;
    while(!copy.empty()){
        cout << copy.front() << " ";
        copy.pop();
    }
}

void Reverse(queue<int>& u_queue, int r_steps){
    for(int i = 0; i < r_steps; i++){
        int value = u_queue.front();
        u_queue.pop();
        u_queue.push(value);
    }
}

int main(){
    queue<int> randomQueue;
    int n = 0;
    int k = 0;
    cin >> n;
    Input(randomQueue, n);
    cin >> k;
    Reverse(randomQueue, k);
    Output(randomQueue);
    Deinit(randomQueue);
    return 0;
}