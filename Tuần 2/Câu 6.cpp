//Cau a:

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <vector>


using namespace std;



int random(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}


void input_arr(int a[], int &n, int &k)
{

    int r;
    cout << "n = " ;
    n = random(100, 10000);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        r = random(-n,n);
        a[i] = r;
    }
    k = a[random(0, n-1)];
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


int linear_search_linh_canh(int arr[], int n, int x)
{
    int i = 0;
    arr[n] = x;
    while (arr[i] != x)
        i++;
    if (i == n)
        return 0;
    else
        return i;
}


void solve(int a[], int n, int k)
{
    double time_use = 0.0;
    clock_t start = 0, end = 0;
    start = clock();
    linear_search(a, n, k);
    end = clock();
    time_use = (double)(end - start)/CLOCKS_PER_SEC;
    cout << "- Thoi gian chay Linear Search khong co linh canh: " << fixed << time_use << "s" << endl;

}

void solve_2(int a[], int n, int k)
{
    double time_use = 0.0;
    clock_t start = 0, end = 0;
    start = clock();
    linear_search_linh_canh(a, n, k);
    end = clock();
    time_use = (double)(end - start)/CLOCKS_PER_SEC;
    cout << "- Thoi gian chay Linear Search co linh canh: " << fixed << time_use << "s" << endl;

}



int main()
{
    int k, n;
    int a[1000000];
    input_arr(a, n, k);
    solve(a, n, k);
    solve_2(a, n, k);
}


//Cau B:
/*
 - Kỹ thuật "lính canh" được sử dụng để tối ưu hóa thời gian thực hiện của thuật toán tìm kiếm tuyến tính trong trường hợp mảng đã được sắp xếp.
 - Tuy nhiên, nếu mảng chưa được sắp xếp, kỹ thuật này không có tác dụng và ta phải duyệt qua từng phần tử của mảng để tìm kiếm phần tử cần tìm, với độ phức tạp tuyến tính.
 - Vì vậy, thời gian thực hiện của thuật toán tìm kiếm tuyến tính sử dụng kỹ thuật "lính canh" và khi không sử dụng kỹ thuật này sẽ không có tỷ lệ tuyến tính với nhau khi tăng hoặc giảm số phần tử N. Thời gian thực hiện của thuật toán sẽ phụ thuộc vào thứ tự các phần tử trong mảng.
 - Nếu mảng đã được sắp xếp, việc sử dụng kỹ thuật "lính canh" sẽ giúp giảm thời gian thực hiện của thuật toán, còn nếu mảng chưa được sắp xếp thì thời gian thực hiện của thuật toán sẽ tương đương khi sử dụng hay không sử dụng kỹ thuật "lính canh".
 */
