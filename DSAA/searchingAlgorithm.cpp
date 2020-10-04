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

int binarySearch(int a[], int& n, int r_value){
    int foundPos = -1;
    int left = 0;
    int right = n - 1;
    int mid = (left + right)/2;
    while(true){
        if(a[left] == a[right] == r_value){
            foundPos = left;
            return foundPos;
        }
        else if(left == right){
            return foundPos;
        }
        else{
            if(a[mid] < r_value){
                left = mid + 1;
                mid = (left + right)/2;
            }
            else if(a[mid] > r_value){
                right = mid;
                mid = (left + right)/2;
            }
            if(a[mid] == r_value){
                foundPos = mid;
                right = mid;
                mid = (left + right)/2;
            }
        }
    }
}

// Shorter version of binary search

int binSearch(int a[], int& n, int r_value){
    int left = 0;
    int right = n - 1;
    while(left < right){
        int mid = (left + right)/2;
        if(a[mid] < r_value){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    if(a[left] == r_value){
        return left;
    }
    return -1;
}

void printArray(int a[], int& n, int r_startPos, int r_endPos){
    for(int i = r_startPos; i <= r_endPos; i++){
        cout << a[i] << " ";
    }
}

bool continuousArray(int a[], int b[], int& n, int r_value){
    b[0] = a[0];
    for(int i = 1; i < n; i++){
        b[i] = b[i-1] + a[i];
    }
    for(int i = 0; i < n; i++){
        if(b[i] == r_value){
            printArray(a,n,0,i);
            return true;
        }
        if(b[i] > r_value){
            int l = binSearch(b,n,b[i] - r_value);
            if(l != -1){
                printArray(a,n,l+1,i);
                return true;
            }
        }
    }
    return -1;
}

int main(){
    int a[MAX];
    int b[MAX];
    int n = 0;
    cin >> n;
    inputArray(a,n);
    int x = 0;
    cin >> x;
    continuousArray(a,b,n,x);
    if(!continuousArray){
        cout << "-1";
    }
    return 0;
}