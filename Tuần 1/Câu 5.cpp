#include <iostream>
#include <ctime>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <stdlib.h>


using namespace std;

int random(int minn, int maxx)
{
 return minn + rand() % (maxx + 1 - minn);
}

void input_arr(int a[], int &n)
{
    cin >> n;
    cout << "n = " << n;
    cout << endl;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-1000,1000);
        a[i] = r;
    }
}


int partition(int arr[], int low, int high, int x)
{

    if (x == 2)  {
        int mid = low + (high - low) / 2;
        swap(arr[mid], arr[high]);}

    else if (x != 1) { swap(arr[low], arr[high]); }
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}


void quickSort(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int stack[n];

    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {

        high = stack[top--];
        low = stack[top--];


        int pivot_index = partition(arr, low, high, x);


        if (pivot_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot_index - 1;
        }


        if (pivot_index + 1 < high) {
            stack[++top] = pivot_index + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    int n;
    int arr[1000000];
    srand(time(NULL));
    input_arr(arr, n);

    clock_t start = clock();
    quickSort(arr, n, 2);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Thoi gian khi x CHINH GIUA day: " << fixed << time_taken << setprecision(6) << "s." << endl;


    start = clock();
    quickSort(arr, n, 1);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Thoi gian khi x DAU day: " << fixed << time_taken << setprecision(6) << "s." << endl;


    start = clock();
    quickSort(arr, n, 3);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Thoi gian khi x CUOI day: " << fixed << time_taken << setprecision(6) << "s." << endl;

}
