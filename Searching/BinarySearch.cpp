#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid; // Element found
    }
    else if (target < arr[mid])
    {
        return BinarySearch(arr, left, mid - 1, target); // Search left half
    }
    else
    {
        return BinarySearch(arr, mid + 1, right, target); // Search right half
    }
}

int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " sorted elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int index = BinarySearch(arr, 0, size - 1, target);

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}