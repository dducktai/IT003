#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
double T1, T2, deltaT;
using namespace std;
void quick_sort(int a[], int left, int right);

int random(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n)
{
    int r;
    n = random(100,30000);
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-n,n);
        a[i] = r;
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}


int binary_search(int a[], int n, int X)
{
    int left, right, mid;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
        if (a[mid] == X)
            return mid;
        else if (a[mid] > X)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

void quick_sort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i] > x)
            i++;
        while (a[j] < x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort(a, left, j);
    if (i < right)
        quick_sort(a, i, right);
}



void output_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;


}


void solve(int a[])
{
    int k, n;
    double time_use = 0.0;
    clock_t start = 0, end = 0, time_sum = 0;
   
    for (int i = 1; i <= 100; i++)
    {
        input_arr(a, n);
        quick_sort(a, 0, n-1);
        k = a[random(0, n-1)];
        start = clock();
        binary_search(a, n, k);
        end = clock();
        time_sum = time_sum + (end - start);
    }
   
    time_use = (double)(time_sum)/CLOCKS_PER_SEC;
    cout << "- Thoi gian chay Binary Search: " << fixed << time_use << "s" << endl;
    T1 = time_use;
}

void solve_2(int a[])
{
    int k, n;
    double time_use = 0.0;
    clock_t start = 0, end = 0, time_sum = 0;
   
    for (int i = 1; i <= 100; i++)
    {
        input_arr(a, n);
        k = a[random(0, n-1)];
        start = clock();
        linear_search(a, n, k);
        end = clock();
        time_sum = time_sum + (end - start);
    }
   
    time_use = (double)(time_sum)/CLOCKS_PER_SEC;
    cout << "- Thoi gian chay Sequential Search: " << fixed << time_use << "s" << endl;
    T2 = time_use;
}


int main()
{
    int a[1000000];
    solve(a);
    solve_2(a);
    cout << "- Nhan xet: " << endl;
    cout << "+ T1 la thoi gian chay Binary Search, T1 = " << T1 << endl;
    cout << "+ T2 la thoi gian chay Sequential Search, T2 = " << T2 << endl;
    cout << "+ DeltaT = |T1 - T2| = " << abs(T1-T2) << endl;
    cout << "+ Binary Search nhanh gap Sequential Search: " << (T2/T1) << " lan." << endl;
    
}
