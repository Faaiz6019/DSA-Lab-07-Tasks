#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    cout << "\nFrequency count: ";
    for (int i = 0; i < 10; i++)
        cout << count[i] << " ";

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    cout << "\nCumulative count: ";
    for (int i = 0; i < 10; i++)
        cout << count[i] << " ";

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    cout << "\nOutput array: ";
    for (int i = 0; i < n; i++)
        cout << output[i] << " ";

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    cout << "\nArray copied back: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    delete[] output;
}

void radixSort(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int trackingIDs[] = {
        4721, 305, 472, 89, 3005, 721,
        1000, 305, 9999, 42, 870, 100
    };

    int n = sizeof(trackingIDs) / sizeof(trackingIDs[0]);

    cout << "Initial array: ";
    for (int i = 0; i < n; i++)
        cout << trackingIDs[i] << " ";
    cout << endl;

    radixSort(trackingIDs, n);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < n; i++)
        cout << trackingIDs[i] << " ";

    return 0;
}
