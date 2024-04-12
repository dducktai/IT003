#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int a[], int l, int m, int r, int &x, int &y) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
        x++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[m + 1+ j];
        x++;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        y++;
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        x++;
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
        x++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
        x++;
    }
}

void Merge_Sort(int a[], int l, int r, int &x, int &y) {
    if (l < r) {
        int m = l+(r-l)/2;
        Merge_Sort(a, l, m, x, y);
        Merge_Sort(a, m+1, r, x, y);
        merge(a, l, m, r, x, y);
    }
}

int main() {
    int a[] = {100,34,23,56,85,1};
    int n = sizeof(a)/sizeof(a[0]);
    int x = 0;
    int y = 0;

    auto start = high_resolution_clock::now();
    Merge_Sort(a, 0, n-1, x, y);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\nTime taken by function: " << duration.count() << " microseconds\n";
    cout << "Number of assignments: " << x << endl;
    cout << "Number of comparisons: " << y << endl;
    return 0;
}
