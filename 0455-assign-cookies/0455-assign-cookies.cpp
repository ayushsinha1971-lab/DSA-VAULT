class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        // unordered_set <int> c;
        // for(auto it:s){
        //     c.insert(it);
        // }
        int k=0;
        for(int i=0;i<s.size()&&k<g.size();i++){
            if(g[k]<=s[i]){
                count++;
                k++;
            }
        }
        return count;
    }
};