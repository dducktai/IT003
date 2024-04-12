
#include <iostream>
#include <time.h>
#include <iomanip>

#define M 1000
#define N 1000

using namespace std;
void sortMatrix(int64_t a[M][N], int64_t m, int64_t n);


int64_t random(int64_t minN, int64_t maxN){
 return minN + rand() % (maxN + 1 - minN);
}


void input_arr(int64_t a[M][N], int64_t &n, int64_t &m, int64_t &k)
{
    cout << "n = " ;
    n = random(100, 10000);
    cout << n << endl;
    cout << "m = " ;
    m = random(100, 10000);
    cout << m << endl;
    srand((int)time(0));
    for (int64_t i = 0; i < m; i++)
        for (int64_t j = 0; j < n; j++)
            a[i][j] = random(1000, 1000);
    
    sortMatrix(a, m, n);
    k = a[random(0, n-1)][random(0, m-1)];
}


bool linear_search(int64_t arr[M][N], int64_t m, int64_t n, int64_t x)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == x)
                return true;
        }
    return false;
}

int linear_search_linh_canh(int64_t arr[M][N], int64_t m, int64_t n, int64_t x)
{
    int64_t row = 0, col = N-1;
    while (row < M && col >= 0)
    {
        if (arr[row][col] == x)
            return 1;
        
        else if (arr[row][col] > x)
            col--;
        
        else
            row++;
    }
    return 0;
}


void sortMatrix(int64_t a[M][N], int64_t m, int64_t n)
{
    int64_t MAX = M*N;
    int64_t Arr[MAX];
    int64_t k = 0;
    for (int64_t i = 0; i < m; i++) {
        for (int64_t j = 0; j < n; j++) {
            Arr[k++] = a[i][j];
        }
    }
    
    sort(Arr, Arr + k);
    k = 0;
    for (int64_t i = 0; i < m; i++) {
        for (int64_t j = 0; j < n; j++) {
            a[i][j] = Arr[k++];
        }
    }
}

void solve(int64_t a[M][N], int64_t m, int64_t n, int64_t k)
{
    double time_use = 0.0;
    clock_t start = 0, end = 0;
    start = clock();
    linear_search(a, m, n, k);
    end = clock();
    time_use = (double)(end - start)/CLOCKS_PER_SEC;
    cout << "- Thoi gian chay Linear Search khong co linh canh: " << fixed << time_use << "s" << endl;

}

void solve_2(int64_t a[M][N], int64_t m, int64_t n, int64_t k)
{
    double time_use = 0.0;
    clock_t start = 0, end = 0;
    start = clock();
    linear_search_linh_canh(a, m, n, k);
    end = clock();
    time_use = (double)(end - start)/CLOCKS_PER_SEC;
    cout << "- Thoi gian chay Linear Search co linh canh: " << fixed << time_use << "s" << endl;

}



int main()
{
    int64_t k, n, m;
    int64_t a[M][N];
    input_arr(a, n, m, k);
    solve(a, m, n, k);
    solve_2(a, m, n, k);

}


