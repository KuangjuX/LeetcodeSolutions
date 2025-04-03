class Solution {
public:
    void gen(vector<string>& ans, string s, int left, int right, int n){
        if(left == n && right == n){
            ans.push_back(s);
            return;
        }
        if(left < n){
            s.push_back('(');
            left++;
            gen(ans, s, left, right, n);
            s.pop_back();
            left--;
        }
        if(left > right){
            if(right < n){
                s.push_back(')');
                right++;
                gen(ans, s, left, right, n);
                s.pop_back();
                right--;
            }
        }

    }

    vector<string> generateParenthesis(int n) {
        std::vector<string> ans;
        string s;
        gen(ans, s, 0, 0, n);
        return ans;
    }
};
