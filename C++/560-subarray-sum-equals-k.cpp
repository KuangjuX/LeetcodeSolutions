class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == k)return 1;
            else return 0;
        }
        vector<int> prefix(n + 1, 0);
        // 计算前缀和
        for(int i = 1; i < n + 1; ++i){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int counts = 0;

        for(int i = 1; i < n + 1; ++i){
            for(int j = 0; j < i; ++j){
                if(prefix[i] - prefix[j] == k)counts++;
            }
        }
        return counts;
    }
};
