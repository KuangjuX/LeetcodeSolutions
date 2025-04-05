class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second < n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 使用哈希表存储所有元素出现的频率
        std::unordered_map<int, int> freq;
        // 最小堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(freq.find(nums[i]) != freq.end()){
                freq[nums[i]]++;
            }else{
                freq[nums[i]] = 1;
            }
        }

        for(auto &[k, v]: freq){
            q.push({k, v});
        }

        while(k--){
            auto ele = q.top();
            q.pop();
            ans.push_back(ele.first);
        }
        
        return ans;
    }
};
