class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> set;
        vector<vector<int>> ans;
        std::cout << std::endl;
        for(int i = 0; i < n - 2; ++i){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)k--;
                else j++;
            }
        }
        for(auto e: set){
            ans.push_back(e);
        }
        return ans;
    }
};
