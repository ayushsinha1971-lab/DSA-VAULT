class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long,4>> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        sort(arr.begin(), arr.end(),
             [](const array<long long,4>& a, const array<long long,4>& b){
                 return a[0] < b[0];
             });

        vector<int> nxt(n);
        for (int i = 0; i < n; ++i) {
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (arr[mid][0] > arr[i][1]) hi = mid;
                else lo = mid + 1;
            }
            nxt[i] = lo;
        }

        vector<vector<long long>> f(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> g(n + 1, vector<vector<int>>(5));

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                long long skipScore = f[i + 1][k];
                vector<int> skipIdx = g[i + 1][k];

                int nx = nxt[i];
                long long takeScore = f[nx][k - 1] + arr[i][2];
                vector<int> takeIdx = g[nx][k - 1];
                int origIdx = (int)arr[i][3];
                takeIdx.insert(lower_bound(takeIdx.begin(), takeIdx.end(), origIdx), origIdx);

                if (takeScore > skipScore ||
                    (takeScore == skipScore && takeIdx < skipIdx)) {
                    f[i][k] = takeScore;
                    g[i][k] = move(takeIdx);
                } else {
                    f[i][k] = skipScore;
                    g[i][k] = move(skipIdx);
                }
            }
        }

        return g[0][4];
    }
};