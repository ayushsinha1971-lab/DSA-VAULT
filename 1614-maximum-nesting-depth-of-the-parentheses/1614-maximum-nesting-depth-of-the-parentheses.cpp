class Solution {
public:
    int maxDepth(string s) {
        int maxi =0;
        int fr=0;
        int bck=0;
        for(auto it: s){
            if(it=='('){
                fr++;
                maxi=max(maxi,fr);
            }
            if(it==')'&&it){
                fr--;
            }
        }
        return maxi;
    }
};