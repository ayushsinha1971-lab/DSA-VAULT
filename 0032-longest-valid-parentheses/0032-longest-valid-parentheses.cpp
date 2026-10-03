class Solution {
public:
    int fsearch(string s){
        int h=0,t=0;
        int count=0;
        for (auto ch:s){
            if(ch=='('){
                h++;
            }
            else if (ch==')'){
                t++;
            }
            if(h==t){
                count=max(count,h+t);
            }
            else if(h<t){
                h=t=0;
            }
        }
        return count;
    }
    int bsearch(string s){
        int h=0,t=0;
        int count=0;
        for (int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                h++;
            }
            else if (s[i]==')'){
                t++;
            }
            if(h==t){
                count=max(count,h+t);
            }
            else if(h>t){
                h=t=0;
            }
        }
        return count;
    }
    int longestValidParentheses(string s) {
        int max1=0;
        int max2=0;
        max1=fsearch(s);
        // reverse(s.begin(),s.end());
        max2=bsearch(s);
        int maxi=max(max1,max2);
        return maxi;
    }
};