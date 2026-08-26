class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
            idx.push_back(i);
        }
        int m = idx.size();
        if (k > m) return "";
        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i<m-k+1; i++) {
            int l = idx[i];
            int r = idx[i + k - 1];
            int len = r - l + 1;

            if (len < minLen) {
                minLen = len;
                ans = s.substr(l, len);
            } else if (len == minLen) {
                string cand = s.substr(l, len);
                if (cand < ans) ans = cand;   // lexicographically smaller
            }
        }
        return ans;
    }
};