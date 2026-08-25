class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        const long long INV2 = 500000004; // modular inverse of 2

        long long res = k;
        long long operations = 0;

        for (int x : nums) {
            if (res < x) {
                long long need = x - res;
                long long cnt = (need + k - 1) / k;

                operations += cnt;
                res += cnt * 1LL * k;
            }
            res -= x;
        }

        long long ans = (operations % MOD) * ((operations + 1) % MOD) % MOD;
        ans = ans * INV2 % MOD;

        return ans;
    }
};