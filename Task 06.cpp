#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int output[7];
    int count[10] = {0};

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

    cout << "\nArray after pass: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
