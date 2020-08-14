/**
 * 问题：
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 * 
 * 解决思路：
 * 归并排序，当右半边的数组的元素arr[r]小于左半边的数组的元素arr[l]时，表示有mid-l+1个逆序对。
*/
#include <vector>

using namespace std;

class Solution {
private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (right == left) {
            return 0;
        }
        int mid = left + ((right - left) >> 1);
        int l = mergeSort(nums, left, mid);
        int r = mergeSort(nums, mid + 1, right);
        return l + r + merge(nums, left, mid, right);
    }
    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> arr(right - left + 1, 0);
        int a = left, b = mid + 1;
        int i = 0;
        int count = 0;
        while (a <= mid && b <= right) {
            if (nums[a] <= nums[b]) {
                arr[i++] = nums[a++];
            }
            else {
                arr[i++] = nums[b++];
                count+=mid-a+1;  //从arr[a]~arr[mid]的元素都比arr[b]大，故有mid-a+1个逆序对。
            }
        }
        if (b > right) {
            while (a <= mid) {
                arr[i++] = nums[a++];
            }
        }
        for (int x = 0; x < i; ++x) {
            nums[left + x] = arr[x];
        }
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};