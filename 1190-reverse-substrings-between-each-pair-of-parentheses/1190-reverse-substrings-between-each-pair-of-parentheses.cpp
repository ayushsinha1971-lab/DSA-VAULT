class Solution {
public:
    string reverseParentheses(string s) {
        stack <char> st;
        string ans="";
        int i=0;
        for(auto it : s){
            if(it==')'){
                vector <char> temp;
                while(!st.empty()&&st.top()!='('){
                    if(st.top()!=')'){
                        char c=st.top();
                        temp.push_back(c);
                    }
                    st.pop();
                }
                st.pop();
                for(auto c:temp)st.push(c);
            }
            else{
                st.push(it);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};