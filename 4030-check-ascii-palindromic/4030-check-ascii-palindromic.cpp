#include <bitset>

class Solution {
public:
    bool isPalindromic(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            ans+=bitset<8> ((int)s[i]).to_string();
            
        }
        int n=ans.length();
        for(int i=0;i<n/2;i++){
            if(ans[i]!=ans[n-i-1])
                return false ;
        }
        return true;
    }
};