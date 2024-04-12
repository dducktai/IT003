#include <iostream>
#define MAX 10000

using namespace std;

//Tạo random 
int random(int minN, int maxN) {
    return minN + rand() % (maxN + 1 - minN);
}


//input mảng random
void Input(int Arr[], int& n) {
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Arr[i] = random(-n, n);
    }
    cout << endl;
}

//Hàm hoán vị 
void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

// Hàm chia mảng thành hai phần
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hàm Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}


//Tìm kiếm nhị phân
int BinarySearch(int arr[], int left, int right, int x, int& comparisons)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            comparisons++;
            return mid;
        }

        if (arr[mid] < x) {
            comparisons++;
            left = mid + 1;
        }

        else {
            comparisons++;
            right = mid - 1;
        }
    }
    return -1;
}


// Tìm kiếm nhị phân (Đệ quy)
int BinarySearch_update(int arr[], int l, int r, int x ,int& comparisons2) {
    if (r >= l) {
        comparisons2++;
        int mid = l + (r - l) / 2; 
        comparisons2++;
        if (arr[mid] == x)
            return mid;
        comparisons2++;
        if (arr[mid] > x)
            return BinarySearch_update(arr, l, mid - 1, x, comparisons2);

        return BinarySearch_update(arr, mid + 1, r, x, comparisons2);
    }
    return -1;
}

int main() {
    int comparisons = 0, comparisons2 = 0;
    int Arr[MAX], n;
    Input(Arr, n);
    quickSort(Arr,0,n);
    int option;
    cout << "Moi chon thuat toan: " << endl;
    cout << "   1. Dau day" << endl << "   2. Giua day" << endl << "   3. Cuoi day " << endl;

    do {
        cout << "Nhap thuat toan ban muon chon: ";
        cin >> option;
        if (option < 1 || option > 3)
            cout << "Thuat toan khong hop le. Vui long nhap lai." << endl;
    } while (option < 1 || option > 3);

    int kq, kq2;

    switch (option) {
        case 1:
            kq = BinarySearch(Arr, 0, n-1, Arr[0], comparisons);
            kq2 = BinarySearch_update(Arr, 0, n-1, Arr[0], comparisons2);
            cout << "   Khong de quy: ";
            cout << "Gia tri muon tim nam o vi tri "<< kq << " voi so lan so sanh la " << comparisons << endl;
            
            cout << "   Dung de quy: ";
            cout << "Gia tri muon tim nam o vi tri " << kq2 << " voi so lan so sanh la " << comparisons2 << endl;
            break;
        case 2:
            kq = BinarySearch(Arr, 0, n-1, Arr[n / 2], comparisons);
            kq2 = BinarySearch_update(Arr, 0, n-1, Arr[n / 2], comparisons2);
            cout << "   Khong de quy: ";
            cout << "Gia tri muon tim nam o vi tri "<< kq << " voi so lan so sanh la " << comparisons << endl;
            
            cout << "   Dung de quy: ";
            cout << "Gia tri muon tim nam o vi tri " << kq2 << " voi so lan so sanh la " << comparisons2 << endl;
            break;
        case 3:
            kq = BinarySearch(Arr, 0, n-1, Arr[n - 1], comparisons);
            kq2 = BinarySearch_update(Arr, 0, n-1, Arr[n - 1], comparisons2);
            cout << "   Khong de quy: ";
            cout << "Gia tri muon tim nam o vi tri " << kq << " voi so lan so sanh la " << comparisons << endl;

            cout << "   Dung de quy: ";
            cout << "Gia tri muon tim nam o vi tri " << kq2 << " voi so lan so sanh la " << comparisons2 << endl;
            break;
    }
    return 0;
}
