class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int baseCount[26] = {0};
        for (char c : s) baseCount[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            int cnt[26];
            memcpy(cnt, baseCount, sizeof(cnt));

            bool feasible = true;
            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';
                if (cnt[c] == 0) { feasible = false; break; }
                cnt[c]--;
            }
            if (!feasible) continue;

            int found = -1;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) { found = c; break; }
            }
            if (found == -1) continue;

            cnt[found]--;
            string ans = target.substr(0, i) + char('a' + found);
            for (int c = 0; c < 26; c++)
                ans += string(cnt[c], char('a' + c));
            return ans;
        }
        return "";
    }
};