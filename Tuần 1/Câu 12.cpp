#include <iostream>

using namespace std;

void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout <<a[i]<<" ";
    }
    cout << "\n";
}
void BubbleSort(int a[], int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n - 1; i++) {
        
        haveSwap = false;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                haveSwap = true; 
            }
            XuatMang(a,n);
        }
        if (haveSwap == false) {
            break;
        }
    }
}
void SelectionSort(int a[], int n)
{
    int i, j, min_i;
    
    for (i = 0; i < n - 1; i++)
    {
        
        min_i = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_i])
                min_i = j;
 
        swap(a[min_i], a[i]);
        XuatMang(a, n);
    }
}

void InsertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        XuatMang(a, n);
    }
}
int main() {
    int a[100];
    int n;
    cin >> n;
    NhapMang(a, n);
    InsertionSort(a, n);
    return 0;
}