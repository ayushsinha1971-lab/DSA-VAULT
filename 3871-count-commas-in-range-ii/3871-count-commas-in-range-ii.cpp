class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lo = 1;
        long long hi = 9;
        int d = 1;

        while (lo <= n) {
            long long rangeHi = min(n, hi);
            long long count = rangeHi - lo + 1;
            int commas = (d - 1) / 3;
            total += count * commas;

            lo = hi + 1;
            hi = hi * 10 + 9;
            d++;
        }

        return total;
    }
};