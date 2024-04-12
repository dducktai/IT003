#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int random(int minN, int maxN)
{
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n)
{
    cout << "n = ";
    cin >> n;
    cout << endl;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-1000,1000);
        a[i] = r;
    }
}


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot)
        { 
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1; 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}



int main() {
    int arr[1000000];
    int n;
    clock_t start, end;
    
    input_arr(arr, n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cout << "Thời gian chạy giải thuật khi lấy x là phần tử chính giữa dãy: " << fixed <<(double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

   
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cout << "Thời gian chạy giải thuật khi lấy x là phần tử đầu dãy: " << fixed << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;


    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cout << "Thời gian chạy giải thuật khi lấy x là phần tử cuối dãy: " << fixed << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

}




