class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<bool> flags, vector<int> group, int depth) {
        for(int i = 0; i < nums.size(); ++i){
            if(flags[i]){
                flags[i] = false;
                group.push_back(nums[i]);
                if(depth == nums.size()){
                    ans.push_back(group);
                    return;
                }
                depth++;
                dfs(nums, ans, flags, group, depth);
                group.pop_back();
                flags[i] = true;
                depth--;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> flags(nums.size(), true);
        vector<int> group;
        dfs(nums, ans, flags, group, 1);
        return ans;
    }
};
