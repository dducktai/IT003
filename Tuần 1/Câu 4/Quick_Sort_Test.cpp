#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void quickSort(int arr[], int low, int high, int &gan, int &sosanh)
{
    while (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            sosanh++;
            if (arr[j] < pivot)
            {
                i++;
                gan += 3;
                swap(arr[i], arr[j]);
            }
        }
        gan += 3;
        swap(arr[i + 1], arr[high]);

        if (i - low < high - i - 1)
        {
            quickSort(arr, low, i, gan, sosanh);
            low = i + 2;
        }
        else
        {
            quickSort(arr, i + 2, high, gan, sosanh);
            high = i;
        }
    }
}

int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int gan = 0;
    int sosanh = 0;
    double time = 0.0;

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1, gan, sosanh);
    auto end = high_resolution_clock::now();

    time = duration_cast<duration<double>>(end - start).count();

    cout << "Day sau khi xep: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nThoi gian: " << fixed << time << " seconds\n";
    cout << "So phep gan: " << gan << endl;
    cout << "So phep so sanh: " << sosanh << endl;

    return 0;
}
