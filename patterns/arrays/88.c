void merge(int* nums1, int nums1Size, int m,
           int* nums2, int nums2Size, int n) {

    int i = 0;      // pointer for nums1
    int j = 0;      // pointer for nums2
    int k = 0;      // pointer for temp array

    int temp[m + n];   // temporary array

    // Compare from front
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            temp[k++] = nums1[i++];
        } else {
            temp[k++] = nums2[j++];
        }
    }

    // Copy remaining elements
    while (i < m) {
        temp[k++] = nums1[i++];
    }

    while (j < n) {
        temp[k++] = nums2[j++];
    }

    // Copy back to nums1
    for (int x = 0; x < m + n; x++) {
        nums1[x] = temp[x];
    }
}