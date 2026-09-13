class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> pts1, pts2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) pts1.push_back({i, j});
                if (img2[i][j]) pts2.push_back({i, j});
            }
        if (pts1.empty() || pts2.empty()) return 0;
        unordered_map<int, int> count;
        int best = 0;
        for (auto& [x1, y1] : pts1) {
            for (auto& [x2, y2] : pts2) {
                int key = (x1 - x2 + n) * 200 + (y1 - y2 + n);
                int c = ++count[key];
                if (c > best) best = c;
            }
        }
        return best;
    }
};