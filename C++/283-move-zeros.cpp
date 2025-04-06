class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::vector<int> records;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                records.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(i < records.size())nums[i] = records[i];
            else nums[i] = 0;
        }
    }
};
