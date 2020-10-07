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

void selectionSort(int a[], int& n){
    int indexMin = 0;
    for(int i = 0; i < n-1; i++){
        indexMin = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[indexMin]){
                indexMin = j;
            }
        }
        if(i != indexMin){
            swap(a[i],a[indexMin]);
        }
    }
}

void merge(int a[], int l, int m, int r){
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for(i = 0; i < n1; i++){
        L[i] = a[l+i];
    }
    for(j = 0; j < n2; j++){
        R[j] = a[m+1+j];
    }
    i = 0;
    k = l;
    j = 0;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void shellSort(int a[], int& n){
    int interval, i, j, temp;
    for(interval = n/2; interval > 0; interval /= 2){
        for(i = interval; i < n; i++){
            temp = a[i];
            for(j = i; j >= interval && a[j-interval] > temp; j-= interval){
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l;
    int j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
            swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}

int uniqueSmalletsNum(int a[], int& n){
    quickSort(a,0,n-1);
    for(int i = 0; i < n; i++){
        if(a[0] > 0){
            return 0;
        }
        if( (a[i+1] != a[i]) && (a[i+1] - a[i] != 1)){
            return a[i] + 1;
        }
    }
}

int main(){
    int a[MAX];
    int n = 0;
    cin >> n;
    inputArray(a,n);
    cout << uniqueSmalletsNum(a,n) << endl;
    return 0;
}