class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector <int> e;
        vector <int> o;
        for(auto it: nums1){
            if(it%2==0)
            e.push_back(it);
            else
            o.push_back(it);
        }
        int n=nums1.size();
        vector <int> ans;
        if(e.size()==n||o.size()==n)
            return true;
        else
        if(o.size()!=0){
            return true;
        }
        return false;
    }
};