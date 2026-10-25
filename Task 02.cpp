#include <iostream>
using namespace std;

int comparisons = 0;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    cout << "Left subarray: ";
    for (int i = 0; i < n1; i++)
        cout << L[i] << " ";

    cout << "\nRight subarray: ";
    for (int i = 0; i < n2; i++)
        cout << R[i] << " ";
    cout << endl;

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        comparisons++;

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted prices: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal comparisons: " << comparisons;

    return 0;
}
