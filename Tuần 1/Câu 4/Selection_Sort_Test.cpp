#include <bits/stdc++.h>
using namespace std;
//using namespace std::chrono;

void selectionSort(int a[], int n, int &x, int &y) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            y++;
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        x += 3;
        swap(a[min_idx], a[i]);
    }
}

int main() {
    int a[] = {64, 25, 12, 22, 11, 13, 11, 9, 100, -10, -1928, -192};
    int n = sizeof(a)/sizeof(a[0]);
    int x = 0;
    int y = 0;

    auto start = high_resolution_clock::now();
    selectionSort(a, n, x, y);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted aay: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTime taken by function: " << duration.count() << " microseconds\n";
    cout << "Number of assignments: " << x << endl;
    cout << "Number of comparisons: " << y << endl;

    return 0;
}
