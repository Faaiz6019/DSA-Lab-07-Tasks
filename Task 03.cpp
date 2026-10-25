#include <iostream>
using namespace std;

int recursiveCalls = 0;
int mergeCount = 0;
int comparisons = 0;

void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    mergeCount++;

    while (i <= mid && j <= right)
    {
        comparisons++;

        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int temp[], int left, int right)
{
    recursiveCalls++;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: n must be greater than 0.";
        return 0;
    }

    int *arr = new int[n];
    int *temp = new int[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, temp, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nRecursive calls: " << recursiveCalls;
    cout << "\nMerge operations: " << mergeCount;
    cout << "\nElement comparisons: " << comparisons;

    delete[] arr;
    delete[] temp;

    return 0;
}
