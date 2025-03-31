class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        if(nums[left] >= target)return left;
        else return left + 1;
    }
};
