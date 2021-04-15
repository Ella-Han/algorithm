//
//  Sorting.cpp
//  baekjoon
//
//  Created by 한아름 on 2021/03/29.
//  Copyright © 2021 Ella-Han. All rights reserved.
//

#if 0
#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

#define SIZE    10

int sequence[10] = {10, 3, 2, 1, 9, 8, 7, 5, 6, 4};

void selectionSort() {
    for (int i=0; i<SIZE-1; i++) {
        int minIdx = i;
        for (int j=i+1; j<SIZE; j++) {
            if (sequence[minIdx] > sequence[j]) {
                minIdx = j;
            }
            
            swap(sequence[i], sequence[minIdx]);
        }
    }
}

void insertionSort() {
    for (int i=1; i<SIZE; i++) {
        for (int j=i; j>0; j--) {
            if (sequence[j-1] > sequence[j]) {
                swap(sequence[j-1], sequence[j]);
            } else {
                break;
            }
        }
    }
}

void quickSort(int start, int end) {
    if (start >= end) { return; }
    int pivot = start;
    int left = start + 1;
    int right = end;
    
    while (left <= right) {
        while (left <= end && sequence[left] <= sequence[pivot]) left++;
        while (right > start && sequence[right] >= sequence[pivot]) right--;
        if (left > right) {
            swap(sequence[pivot], sequence[right]);
        } else {
            swap(sequence[left], sequence[right]);
        }
    }
    
    quickSort(start, right-1);
    quickSort(right+1, end);
}

int temp[SIZE];

void merge(int start, int mid, int end, int* temp) {
    for (int i=start; i<=end; i++) {
        temp[i] = sequence[i];
    }
    
    int part1 = start;
    int part2 = mid + 1;
    int index = start;
    
    while (part1 <= mid && part2 <= end) {
        if (temp[part1] <= temp[part2]) {
            sequence[index] = temp[part1];
            part1++;
        } else {
            sequence[index] = temp[part2];
            part2++;
        }
        index++;
    }
    
    for (int i=part1; i<=mid; i++) {
        sequence[index] = temp[i];
        index++;
    }
}

void mergeSort(int start, int end) {
    if (start >= end) { return; }
    int mid = (start+end)/2;
    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start, mid, end, temp);
}



int main() {
    // 선택 정렬
    selectionSort();
    
    // 삽입 정렬
//    insertionSort();
//
//    // 퀵 정렬
//    quickSort(0, SIZE-1);
//
//    // 병합 정렬
//    mergeSort(0, SIZE-1);
    
    for (int i=0; i<10; i++) {
        printf("%d\n", sequence[i]);
    }
    
    return 0;
}
#endif
