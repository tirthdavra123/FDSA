#include <iostream>
using namespace std;
int binaryLoop(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int binaryRecursion(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binaryRecursion(arr, mid + 1, high, target);
    else
        return binaryRecursion(arr, low, mid - 1, target);
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int target = 30;

    cout << "Loop: Position = "
         << binaryLoop(arr, n, target) + 1 << endl;

    cout << "Recursion: Position = "
         << binaryRecursion(arr, 0, n - 1, target) + 1 << endl;

    return 0;
}