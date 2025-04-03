class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slow = 0, fast = p.size() - 1;
        vector<int> ans;
        vector<int> pwords(26, 0);
        for(int x = 0; x < p.size(); ++x){
            pwords[p[x] - 'a']++;
        }
        while(fast < s.size()) {
            bool check = true;
            vector<int> words(26, 0);
            for(int x = slow; x <= fast; ++x){
                words[s[x] - 'a']++;
            }
            for(int x = 0; x < words.size(); ++x){
                if(pwords[x] != words[x])check = false;
            }
            if(check)ans.push_back(slow);
            slow++;
            fast++;
        }
        return ans;
    }
};
