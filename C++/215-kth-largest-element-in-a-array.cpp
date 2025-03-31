class Solution {
public:

    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[low];
        while(low < high){
            while(low < high && arr[high] >= pivot)high--;
            arr[low] = arr[high];
            while(low < high && arr[low] <= pivot)low++;
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    void quickSelect(vector<int>& arr, int low, int high, int pos) {
        if(low >= high)return;
        int pivot = partition(arr, low, high);
        if(pivot == pos)return;
        else if(pivot < pos) quickSelect(arr, pivot + 1, high, pos);
        else if(pivot > pos) quickSelect(arr, low, pivot - 1, pos);  
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickSelect(nums, 0, n - 1, n - k);
        std::cout << std::endl;
        return nums[n - k];
    }
};
