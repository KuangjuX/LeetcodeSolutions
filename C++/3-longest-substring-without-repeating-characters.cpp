class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slow = 0, fast = 0;
        int cnt = 0;
        unordered_set<char> set;
        while(fast < s.size()) {
            if(set.find(s[fast]) != set.end()){
                // 在 set 中找到了该元素
                set.erase(s[slow++]);
            }else{
                cnt = max(cnt, fast - slow + 1);
                set.insert(s[fast++]);
            }
        }
        return cnt;
    }
};
