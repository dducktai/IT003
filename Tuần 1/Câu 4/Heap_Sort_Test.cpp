#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void heap(int arr[], int n, int i, int &num_assignments, int &y)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    y += 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    y += 2;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        x += 3;
        swap(arr[i], arr[largest]);
        heap(arr, n, largest, x, y);
    }
}

void heapSort(int arr[], int n, int &x, int &y) {
    for (int i = n/2 - 1; i >= 0; i--)
        heap(arr, n, i, x, y);

    for (int i = n-1; i > 0; i--) {
        x += 3;
        swap(arr[0], arr[i]);
        heap(arr, i, 0, x, y);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 0;
    int y = 0;

    auto start = high_resolution_clock::now();
    heapSort(arr, n, x, y);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTime taken by function: " << duration.count() << " microseconds\n";
    cout << "Number of assignments: " << x << endl;
    cout << "Number of comparisons: " << y << endl;

    return 0;
}
