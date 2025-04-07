class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int ptr = 0;
        while(ptr < s.size()) {
            if(s[ptr] == '(' || s[ptr] == '[' || s[ptr] == '{')st.push(s[ptr]);
            else{
                if(st.empty())return false;
                if(s[ptr] == '}'){if(st.top() != '{')return false;}
                else if(s[ptr] == ')'){if(st.top() != '(')return false;}
                else if(s[ptr] == ']'){if(st.top() != '[')return false;}
                else return false;
                st.pop();
            }
            ++ptr;
        }
        return st.empty();
    }
};
