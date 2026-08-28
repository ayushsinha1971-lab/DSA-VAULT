class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> countS(26,0);
        for (char c : s) countS[c-'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++)
            if (countS[c] % 2) { oddCount++; oddChar = c; }
        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1))
            return "";

        vector<int> half(26,0);
        for (int c = 0; c < 26; c++) half[c] = countS[c] / 2;
        char midChar = (n % 2 == 1) ? char('a' + oddChar) : 0;
        int m = n / 2;

        vector<vector<int>> pref(n+1, vector<int>(26,0));
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i];
            pref[i+1][target[i]-'a']++;
        }

        auto buildFromH = [&](const string& H) {
            string full = H;
            if (n % 2 == 1) full += midChar;
            for (int i = (int)H.size()-1; i >= 0; i--) full += H[i];
            return full;
        };

        bool exactMatch = true;
        for (int c = 0; c < 26; c++)
            if (pref[m][c] != half[c]) { exactMatch = false; break; }

        if (exactMatch) {
            string H = target.substr(0, m);
            bool decided = false, greater = false;
            if (n % 2 == 1) {
                if (midChar > target[m]) { decided = true; greater = true; }
                else if (midChar < target[m]) { decided = true; greater = false; }
            }
            if (!decided) {
                int start = m + (n % 2);
                for (int k = 0; k < m; k++) {
                    char hc = H[m-1-k], tc = target[start+k];
                    if (hc > tc) { decided = true; greater = true; break; }
                    if (hc < tc) { decided = true; greater = false; break; }
                }
            }
            if (decided && greater) return buildFromH(H);
        }

        for (int i = m-1; i >= 0; i--) {
            bool feasible = true;
            for (int c = 0; c < 26; c++)
                if (pref[i][c] > half[c]) { feasible = false; break; }
            if (!feasible) continue;

            vector<int> remaining(26);
            for (int c = 0; c < 26; c++) remaining[c] = half[c] - pref[i][c];

            int found = -1;
            for (int c = target[i]-'a'+1; c < 26; c++)
                if (remaining[c] > 0) { found = c; break; }
            if (found == -1) continue;

            remaining[found]--;
            string H = target.substr(0, i) + char('a'+found);
            for (int c = 0; c < 26; c++)
                H += string(remaining[c], char('a'+c));
            return buildFromH(H);
        }

        return "";
    }
};