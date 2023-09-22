#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right ,int x){

    if (right >= left){
        int mid = left + (right - left)/2;

        if (arr[mid] == x) 
            return mid;
        else if (arr[mid] > x) 
            return binarySearch(arr, left, mid-1, x);
        else 
            return binarySearch(arr, mid+1, right, x);
    }

    return -1;
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;

    cout << "Your element is at index: " << binarySearch(arr, 0, n - 1, x) << endl;

    return 0;
}