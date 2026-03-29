#include <iostream>
#include "Bucket.h"

int N = 10000;

template <typename T>
bool testSorting(T* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void insertionSort(T* array, int size, int gap) {
    for (int gapI = 0; gapI < gap; gapI++) {
        for (int i = size - 1 - gapI - gap; i >= 0; i -= gap) {
            for (int j = i; j < size - gapI - 1; j += gap) {
                if (array[j] > array[j + gap]) {
                    int helper = array[j];
                    array[j] = array[j + gap];
                    array[j + gap] = helper;
                }
                else {
                    break;
                }
            }
        }
    }
}

template <typename T>
void quickSort(T* array, int left, int right) {
    int helper;
    helper = array[left + ((right - left) / 2)];
    array[left + ((right - left) / 2)] = array[right];
    array[right] = helper;

    int j = left;
    for (int i = left; i < right; i++) {
        if (array[i] < array[right]) {
            helper = array[i];
            array[i] = array[j];
            array[j] = helper;
            j++;
        }
    }

    helper = array[right];
    array[right] = array[j];
    array[j] = helper;

    /*for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;*/

    if (j - 1 > left) {
        quickSort(array, left, j - 1);
    }

    if (j + 1 < right) {
        quickSort(array, j + 1, right);
    }
}

template <typename T>
void shellSort(T* array, int size) {
    int gap = size / 2;
    for (; gap >= 1; gap /= 2) {
        insertionSort(array, size, gap);
    }
}

template <typename T>
void bucketSort(T* array, int size) {
    Bucket* buckets = new Bucket[size];
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
        }
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }
    int bucketSize = (maxValue - minValue) / size;
    if (bucketSize < 1) {
        bucketSize = 1;
    }
    for (int i = 0; i < size; i++) {
        int min = i * bucketSize + minValue;
        int max;
        if (i == size - 1) {
            max = maxValue + 1;
        }
        else {
            max = min + bucketSize;
        }
        int items = 0;
        int* tempBucket = new int[size];
        for (int j = 0; j < size; j++) {
            if (array[j] >= min && array[j] < max) {
                tempBucket[items] = array[j];
                items++;
            }
        }
        int* bucketArray = new int[items];
        //std::cout << std::endl << min << "-" << max << ": ";
        for (int j = 0; j < items; j++) {
            bucketArray[j] = tempBucket[j];
            //std::cout << bucketArray[j] << " ";
        }

        delete[] tempBucket;

        buckets[i].setBucket(min, max, items, bucketArray);
        if (buckets[i].getSize() > 1) {
            insertionSort(buckets[i].getBucketArray(), buckets[i].getSize(), 1);
        }
    }
    //std::cout << std::endl;

    int pos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i].getSize(); j++) {
            array[pos] = buckets[i].getBucketArray()[j];
            pos++;
        }

        delete[] buckets[i].getBucketArray();
    }

    delete[] buckets;
}

int main() {
    srand(time(0));

    int* array = new int[N];
    int* arrayCopy = new int[N];
    for (int iteration = 0; iteration < 100; iteration++) {
        for (int i = 0; i < N; i++) {
            array[i] = rand();
            arrayCopy[i] = array[i];
        }

        quickSort(array, 0, N - 1);
        if (!testSorting(array, N)) {
            std::cout << "Error for quick sort\n";
        }

        for (int i = 0; i < N; i++) {
            array[i] = arrayCopy[i];
        }

        shellSort(array, N);
        if (!testSorting(array, N)) {
            std::cout << "Error for shell sort\n";
        }

        for (int i = 0; i < N; i++) {
            array[i] = arrayCopy[i];
        }

        bucketSort(array, N);
        if (!testSorting(array, N)) {
            std::cout << "Error for bucket sort\n";
        }
    }

    delete[] array;
    delete[] arrayCopy;

    return 0;
}