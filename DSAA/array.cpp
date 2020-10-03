#include <iostream>
#include <math.h>
using namespace std;
#define MAX 30

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

void insertElement(int a[], int& n, int r_pos, int r_value){
    for(int i = n; i > r_pos; i--){
        a[i] = a[i-1];
    }
    a[r_pos] = r_value;
    n++;
}

void deleteElement(int a[], int& n, int r_pos){
    for(int i = r_pos; i < n-1; i++){
        a[i] = a[i+1];
    }
    n--;
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



void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[], int& n){
    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n; j++){
            if(a[j] < a[i]){
                swap(a[i],a[j]);
            }
        }
    }
}

int countOccurences(int a[], int& n, int r_pos){
    int value = a[r_pos];
    int count = 1;
    for(int i = r_pos; i < n; i++){
        if(a[i] == a[i+1]){
            count ++;
        }
        else return count;
    }
    return count;
}

void outputOccurences(int a[], int& n){
    for(int i = 0; i < n;){
        int occurences = countOccurences(a,n,i);
        cout << a[i] << " - " << occurences<<"; ";
        i += occurences;
    }
}

bool simpleSequence(int a[], int n){
    bool flag = true;
    if(a[0] < a[1]){
        for(int i = 0; i < n-1; i++){
            if(a[i] > a[i+1]){
                flag = false;
            }
        }
        return flag;
    }
    else if(a[0] > a[1]){
        for(int i = 0; i < n-1; i++){
            if(a[i] < a[i+1]){
                flag = false;
            }
        }
        return flag;
    }
    return flag;
}

void combineArray(int a[], int b[], int c[], int& nA, int& nB, int& nC){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < nA && j < nB){
        if(a[i] <= b[j]){
            c[k] = a[i];
            k++;
            i++;
        }
        else if(a[i] >= b[j]){
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while(i < nA){
        c[k] = a[i];
        i++;
        k++;
    }
    while(j < nB){
        c[k] = b[j];
        j++;
        k++;
    }
    nC = k;
}

void input2DArray(int a[MAX][MAX], int& row, int& col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> a[i][j];
        }
    }
}

void output2DArray(int a[MAX][MAX], int& row, int& col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
}

int sum(int a[MAX][MAX], int& row, int& col){
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum += a[i][j];
        }
    }
    return sum;
}

int main(){
    int a[MAX][MAX];
    int n = 0;
    int m = 0;
    cin >> m;
    cin >> n;
    input2DArray(a,m,n);
    cout << sum(a,m,n) << endl;
    return 0;
}