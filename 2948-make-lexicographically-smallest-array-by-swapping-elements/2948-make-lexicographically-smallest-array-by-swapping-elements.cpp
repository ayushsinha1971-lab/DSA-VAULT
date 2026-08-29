class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector <deque<int>>groups;
        unordered_map <int ,int> gp;
        vector <int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int n: sorted){
            if(groups.empty()||abs(n-groups.back().back())>limit){
                groups.push_back(deque <int> ());

            }
            groups.back().push_back(n);
            gp[n]=groups.size()-1;
        }
        vector <int> res;
        for(int n: nums){
            int g=gp[n];
            int val=groups[g].front();
            groups[g].pop_front();
            res.push_back(val);
        }
        return res;
    }
};