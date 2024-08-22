/*
 * file brief:
 * binary search: find the index of specified number
 *
 * */

#include "sorting.h"

int main() {
    int num[8] = { 1 , 2 , 26 ,45 , 50 , 62 , 78 , 88};
//    int a = binarySearch(num,8,50);
//    int a = LcRoBinarySearch(num,9,2);
    int a = binarySearchInsertMulti(num,8,47);

    printf("%d",a);
}


// both side closed search;
// j is in index,so i == j is possible situation
int binarySearch(int* num,int len,int target){
    int i = 0;
    int j = len - 1;

    // stop condition base on i,j
    // stop search when search interval is empty
    while (i <= j){
        // m change with loop
        // prevent overflow
        int m = i + ( j - i) / 2;

        if(num[m] > target)
            j = m - 1;
        else if(num[m] < target)
            i = m + 1 ;
        else
            // "return" in while loop will stop the function and return value
            return m;
    }
    // can't find the index
    return -1;
}


// Left close Right open binary search
int LcRoBinarySearch(int *num, int len ,int target){
    int i = 0;
    int j = len;
    while(i < j){
        int m = i + (j - i)/2;
        if( num[m] > target)
            j = m;
        if( num[m] < target)
            i = m;
        else if (num[m] == target)
            return m;
    }
    return -1;
}

// binarysearch used in insert num: insert in the  left index
// case: array has one same num: insert in the index of same num
// case: array doesn't have same num: insert in the index of i
//       which end up at the first bigger value compared with num

int binarySearchInsertSimple(int *num, int len ,int target){
    int i = 0;
    int j = len - 1;

    while (i <= j){
        int m  = i + ( j - i )/2;

        if(num[m] > target)
            j = m - 1;
        else if (num[m] < target)
            i = m + 1;
        else if (num[m] == target)
            return m;
    }
    return i;
}

// case: array has multi same num: insert in the index of same num
// after loop, i point to the first same value while j point to the num before index i
int binarySearchInsertMulti(int *num, int len ,int target){
    int i = 0;
    int j = len - 1;

    while (i <= j){
        int m  = i + ( j - i )/2;

        if(num[m] > target)
            j = m - 1;
        else if (num[m] < target)
            i = m + 1;
        else if (num[m] == target)
            j = m - 1;
    }
    return i;
}

// we want the leftmost target index
// if array doesn't have target, num[i] != target
// if array doesn't have target and target is to big , i == numsize
// note: i tend to move to the end;

int binarySearchLeftEdge(int *nums, int numSize, int target) {
    int i = binarySearchInsertMulti(nums,numSize,target);
    if( nums[i] != target  || i == numSize)
        return -1;
    return i;
}

// we want the rightmost target index
// reuse leftmost target function
int binarySearchRightEdge(int *nums, int numSize, int target) {
    int i = binarySearchInsertMulti(nums,numSize,target+1);
    // note: j = i - 1, tend to move to the end;
    if(nums[i-1] != target  || (i - 1)  == -1)
        return -1;
    return i - 1;
}

// we know that if array doesn't have the target value
// i will stop at the first bigger value index
// i will stop at the first smaller value index
// so we can construct (target - 0.5)  and return i to find left index
//  (target + 0.5)  and return j to find right index

