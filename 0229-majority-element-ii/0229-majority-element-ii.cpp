class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if( n < 2 )
        {
            return nums;
        }
        unordered_map < int,int > mp;
        for( auto n : nums )
        {
            mp[n]++;
        }
        int req = (n/3);
        vector < int > ans ;
        for( auto it : mp )
        {
            if( it.second > req )
            {
                ans.push_back( it.first );
            }
        }
        return ans;
    }
};