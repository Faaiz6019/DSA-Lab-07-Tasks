#include <iostream>
using namespace std;

int partitionCount = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    partitionCount++;

    cout << "\nPartition: low = " << low
         << ", high = " << high
         << ", pivot = " << pivot << endl;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    cout << "Array after partition: ";
    for (int k = 0; k < 7; k++)
        cout << arr[k] << " ";
    cout << endl;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {40, 20, 70, 10, 60, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal partition operations: " << partitionCount;

    return 0;
}
