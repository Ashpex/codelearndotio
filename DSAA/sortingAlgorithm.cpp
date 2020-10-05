#include <iostream>
using namespace std;
#define MAX 100

void inputArray(int a[], int& n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void outputArray(int a[], int& n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int& n){
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void insertionSort(int a[], int& n){
    for(int i = 1; i < n; i++){
        int index = i;
        int value = a[i];
        while(index > 0 && a[index-1] > value){
            a[index] = a[index - 1];
            index --;
        }
        a[index] = value;
    }
}

int main(){
    int a[MAX];
    int n = 0;
    cin >> n;
    inputArray(a,n);
    insertionSort(a,n);
    outputArray(a,n);
    return 0;
}