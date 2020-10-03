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

int linearSearch(int a[], int& n, int r_value){
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == r_value){
            pos = i;
            break;
        }
    }
    return pos;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapMinMax(int a[], int& n){
    int min = a[0];
    int minPos = 0;
    for(int i = 0; i < n; i++){
        if (a[i] < min){
            min = a[i];
            minPos = i;
        }

    }
    int max = a[n-1];
    int maxPos = n-1;
    for(int i = n-1; i >= 0; i--){
        if(a[i] > max){
            max = a[i];
            maxPos = i;
        }
    }
    swap(a[minPos],a[maxPos]);
}

int countOccurences(int a[], int& n, int r_value){
    int occurences = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == r_value){
            occurences++;
        }
    }
    return occurences;
}

void OddNumberInEvenPos(int a[], int& n){
    bool exist = false;
    for(int i = 0; i < n; i+=2){
        if (a[i] % 2 != 0){
            exist = true;
            cout << a[i] << " ";
        }
    }
    if(!exist){
        cout << "NULL";
    }
}

int main(){
    int a[MAX];
    int n = 0;
    cin >> n;
    inputArray(a,n);
    OddNumberInEvenPos(a,n);
    return 0;
}