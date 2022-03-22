/*
    C++ template for quick select algorithm.
    Finds the Kth largest/smallest element in an array.
    Time complexity: O(n) average, in-place.
*/

#include <vector>
#include <iostream>
using namespace std;

int quickSelect(vector<int>& nums, int start, int end, int k) {
    if (start >= end)
        return nums[k - 1];
    int left = start, right = end;
    int pivot = nums[start + (end - start) / 2];
    while (left <= right) {
        while (left <= right && nums[left] > pivot)
            left++;
        while (left <= right && nums[right] < pivot)
            right--;
        if (left <= right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    if (k - 1 >= left)
        return quickSelect(nums, left, end, k);
    if (k - 1 <= right)
        return quickSelect(nums, start, right, k);
    return nums[k - 1];
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k);
}

int main() {
    vector<int> v1({3,2,1,5,6,4});
    vector<int> v2({3,2,3,1,2,4,5,5,6});
    cout << findKthLargest(v1, 2) << endl;
    cout << findKthLargest(v2, 4) << endl;
    return 0;
}
