#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int size = right - left + 1;
    int temp[size];

    int i = left;
    int j = mid + 1;

    // Merge the two subarrays into the temporary array
    for (int k = 0; k < size; k++)
    {
        if (i > mid)
            temp[k] = arr[j++];
        else if (j > right)
            temp[k] = arr[i++];
        else if (arr[i] <= arr[j])
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++];
    }

    // Copy merged elements back to the original array
    for (int k = 0; k < size; k++)
    {
        arr[left + k] = temp[k];
    }
}

int main()
{
    int arr[] = {2, 5, 8, 1, 3, 7};

    int left = 0;
    int mid = 2;
    int right = 5;

    merge(arr, left, mid, right);

    cout << "Merged Array: ";

    for (int i = 0; i <= right; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}