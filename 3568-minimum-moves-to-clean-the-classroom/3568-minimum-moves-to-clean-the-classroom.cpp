class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        int litter_cnt = 0;
        int litter_id[20][20];
        memset(litter_id, -1, sizeof(litter_id));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_cnt++;
                }
            }
        }
        
        if (litter_cnt == 0) return 0;
        
        int target_mask = (1 << litter_cnt) - 1;
        
        // Queue stores: {row, col, current_energy, mask}
        queue<tuple<int, int, int, int>> q;
        
        // best_energy[r][c][mask] stores the max energy we've had at this cell with this mask
        vector<vector<vector<int>>> best_energy(m, vector<vector<int>>(n, vector<int>(1 << litter_cnt, -1)));
        
        q.push({start_r, start_c, energy, target_mask});
        best_energy[start_r][start_c][target_mask] = energy;
        
        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, cur_e, mask] = q.front();
                q.pop();
                
                if (mask == 0) return moves;
                
                if (cur_e == 0) continue; // Cannot move further without energy unless on 'R' (handled on arrival)
                
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    
                    int next_mask = mask;
                    if (classroom[nr][nc] == 'L' && (mask & (1 << litter_id[nr][nc]))) {
                        next_mask ^= (1 << litter_id[nr][nc]);
                    }
                    
                    if (next_mask == 0) return moves + 1;
                    
                    int next_e = (classroom[nr][nc] == 'R') ? energy : cur_e - 1;
                    
                    if (next_e > best_energy[nr][nc][next_mask]) {
                        best_energy[nr][nc][next_mask] = next_e;
                        q.push({nr, nc, next_e, next_mask});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};