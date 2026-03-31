#include <string.h>
void merge(int* arr,int left, int mid, int right)
{
    int temp[right-left+1];
    int i = left;
    int j = mid+1;
    int k = 0;

    while(i <= mid && j <=right)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    int length = sizeof(temp) / sizeof(temp[0]);

    for(int x = 0; x <length; x++)
    {
        arr[left + x] = temp[x];
    }
}

void mergeSort(int* arr, int left,int right)
{
    if(left == right)
    {
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr,left,mid,right);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* mergedArray = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    memcpy(mergedArray, nums1, nums1Size * sizeof(int));
    memcpy(mergedArray+nums1Size, nums2, nums2Size * sizeof(int));

    int mergedArraySize = nums1Size+nums2Size;
    mergeSort(mergedArray, 0 ,mergedArraySize-1);


    printf("%d ", mergedArraySize);

    if(mergedArraySize % 2 == 0)
    return (mergedArray[mergedArraySize / 2  - 1] + mergedArray[mergedArraySize / 2])/2.0;

    return mergedArray[mergedArraySize/2];

}
