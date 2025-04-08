class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <long> maxF(nums.begin(),nums.end()), minF(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max((long)nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min((long)nums[i], maxF[i - 1] * nums[i]));
            if(minF[i]<INT_MIN) {
                minF[i]=nums[i];
            }
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};
