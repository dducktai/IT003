#include <iostream>
#define MAX 10000
using namespace std;

//tao random 
int random(int minN, int maxN) {
    return minN + rand() % (maxN + 1 - minN);
}


//input mang random
void Input(int Arr[], int& n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Arr[i] = random(-n, n);
    }
    cout << endl;
}


// Tao Heap
void heapify(int arr[], int n, int i) {
    int max = i;
    int l = i * 2 + 1;
    int r = l + 1;
    if (l<n && arr[l] > arr[max])
        max = l;

    if (r<n && arr[r] > arr[max])
        max = r;

    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

//Thuat toan sap xep
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int j = n - 1; j > 0; j--) {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
}

//Thuat toan tim kiem
void LinearSearch(int Arr[], int n, int x) {
    int i = 0, dem = 0;
    while (i < n) {
        dem++;
        if (Arr[i] == x) {
            cout << "  Gia tri can tim nam o vi tri: " << i << " voi so lan so sanh: " << dem * 2 << endl;
            break;
        }
        i++;
    }
    if (i >= n) {
        cout << "  Khong tim thay gia tri can tim" << endl;
    }
}

//Tim kiem cai tien
void LinearSearchUpdate(int Arr[], int n, int x) {
    int i = 0;
    Arr[n] = x;
    while (Arr[i] != x)
        i++;
    if (i != n)
        cout << "  Gia tri can tim nam o vi tri: " << i << " voi so lan so sanh: " << i + 1 << endl;
    else
        cout << "  Khong tim thay gia tri can tim" << endl;
}

int main() {
    int Arr[MAX], n;
    Input(Arr, n);
    heapSort(Arr, n);
    cout << endl << "Cau a: " << endl;
    cout << "Ket qua tim kiem:" << endl;
    cout << " Dau day: ";
    LinearSearch(Arr, n, Arr[0]);
    cout << " Giua day: ";
    LinearSearch(Arr, n, Arr[n / 2]);
    cout << " Cuoi day: ";
    LinearSearch(Arr, n, Arr[n - 1]);
    cout << "\nCau b: \n";
    cout << "Ket qua tim kiem:\n";
    cout << " Dau day: ";
    LinearSearchUpdate(Arr, n, Arr[0]);
    cout << " Giua day: ";
    LinearSearchUpdate(Arr, n, Arr[n / 2]);
    cout << " Cuoi day: ";
    LinearSearchUpdate(Arr, n, Arr[n - 1]);
    cout << "Cau c: " << endl;
    cout << " Cau b tiet kiem bo nho va co thao tac it hon vi so lan so sanh it hon rat nhieu so voi cau a";

    return 0;
}
