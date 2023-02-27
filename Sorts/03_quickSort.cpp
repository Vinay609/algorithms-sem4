#include "arrHelper.cpp"
#include <iostream>
using namespace std;

pair<int, int> partition(int arr[], int begin, int end)
{
    // randomized sorting
    srand(time(NULL));
    int random = begin + rand() % (end - begin);
    swap(arr[random], arr[end]);

    // simple algo
    int pivot = arr[end];
    int cnt = 0;

    int i = begin - 1;
    for (int j = begin; j < end; j++)
    {
        cnt++;
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[end]);
    return {i, cnt};
}

int quickSort(int arr[], int begin, int end)
{
    if (begin >= end)
        return 0;

    pair<int, int> data = partition(arr, begin, end);
    int pivot = data.first;
    int cnt = data.second;

    cnt += quickSort(arr, begin, pivot - 1);
    cnt += quickSort(arr, pivot + 1, end);

    return cnt;
}

int quickSort(int arr[], int n)
{
    return quickSort(arr, 0, n - 1);
}

int partitionYT(int arr[], int low, int high)
{
    int pivot = low, i = low, j = high;
    while (i < j)
    {
        while (i <= high && arr[i] <= arr[pivot])
            i++;
        while (j >= low && arr[j] > arr[pivot])
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivot]);
    return j;
}

void quickSortYT(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pivot = partitionYT(arr, low, high);

    quickSortYT(arr, low, pivot - 1);
    quickSortYT(arr, pivot + 1, high);
}

// int main()
// {
//     cout << "Enter n: ";
//     int n;
//     cin >> n;
//     int arr[n];

//     input(arr, n);

//     // *******************************
//     int num_comp = quickSort(arr, n);
//     // *******************************

//     cout << "\nArray after sorting:\n";
//     print(arr, n);
//     cout << "\nNumber of comparisons: " << num_comp;
//     cout << endl;
// }

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);

    // *******************************
    quickSortYT(arr, 0, n - 1);
    // *******************************

    cout << "\nArray after sorting:\n";
    print(arr, n);
    cout << endl;
}