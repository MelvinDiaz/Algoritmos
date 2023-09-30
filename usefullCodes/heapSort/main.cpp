#include "heapsort.hpp"

int main(){
    int arr[6] = { 12, 11, 13, 5, 6, 7 };
    Heap hp;
    hp.heapSort(arr, 6);
    hp.printArray();
    return 0;
}