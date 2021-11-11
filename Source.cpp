// LAB 6.3 rec
// KUYLK OLEH
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(4) << a[i] << ",";
    if (i < size - 1)
        Print(a, size, i + 1);
}
template <typename T>
T IFirst(T* a, const int size, T& min, int i)
{
    if (a[i] % 2 != 0)
    {
        min = a[i];
        return i;
    }

    if (i < size - 1)
        return IFirst(a, size, min, i + 1);
    else
        return -1;
}
template <typename T>
T Min(T* a, const int size, T min, int i)
{
    if (a[i] < min && a[i] % 2 != 0)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, min, i + 1);
    else
        return min;
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i] << ",";
    if (i < size - 1)
        Print(a, size, i + 1);
}

int IFirst(int* a, const int size, int& min, int i)
{
    if (a[i] % 2 != 0)
    {
        min = a[i];
        return i;
    }

    if (i < size - 1)
        return IFirst(a, size, min, i + 1);
    else
        return -1;
}

int Min(int* a, const int size, int min, int i)
{
    if (a[i] < min && a[i] % 2 != 0)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, min, i + 1);
    else
        return min;
}

int main()
{

    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;
    int* a = new int[n];
    int Low;
    int High;
    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;

    Create(a, n, Low, High, 0);
    cout << "a[" << n << "] = {";
    Print(a, n, 0);
    cout << "}"; cout << endl;
    int min;
    int imin = IFirst(a, n, min, 0);
    if (imin == -1)
        cerr << "ERROR" << endl;
    else
        cout << "less min odd number = " << Min(a, n, min, imin + 1) << endl;

    Create<int>(a, n, Low, High, 0);
    cout << "a[" << n << "] = {";
    Print<int>(a, n, 0);
    cout << "}"; cout << endl;
    imin = IFirst<int>(a, n, min, 0);
    if (imin == -1)
        cerr << "ERROR" << endl;
    else
        cout << "less min odd number = " << Min<int>(a, n, min, imin + 1) << endl;
    return 0;
}
