#include <iostream>
using namespace std;

template <typename T>
void input(T arr[], int n)
{   
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

template <typename T>
void print(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}