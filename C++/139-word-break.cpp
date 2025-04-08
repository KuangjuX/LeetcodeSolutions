class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        unordered_set<string> wordDictSet;
        for(auto &word: wordDict){
            wordDictSet.insert(word);
        }

        for(int i = 1; i < s.size() + 1; ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
