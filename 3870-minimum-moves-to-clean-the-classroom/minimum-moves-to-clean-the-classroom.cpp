#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size(), n = grid[0].size();
        int sr = 0, sc = 0;
        
        // Map litter positions to bit indices
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (grid[i][j] == 'L') {
                    litter_id[i][j] = k++;
                }
            }
        }

        // Target mask: all bits set to 1 for k litters
        int initial_mask = (1 << k) - 1;

        // Flatten state space: (r, c, mask, energy)
        // Dimensions: m * n * 2^k * (energy + 1)
        int mask_states = 1 << k;
        int energy_states = energy + 1;
        int total_states = m * n * mask_states * energy_states;

        // Use a single 1D vector instead of nested 4D vectors for speed & memory
        vector<bool> vis(total_states, false);

        auto get_state_id = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * mask_states + mask) * energy_states) + e;
        };

        // Queue stores: tuple<r, c, mask, e>
        queue<tuple<int, int, int, int>> q;

        // Start at 'S' with full energy and all litters to be collected
        q.push({sr, sc, initial_mask, energy});
        vis[get_state_id(sr, sc, initial_mask, energy)] = true;

        int moves = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Level-by-level BFS
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                // If mask is 0, all litter has been collected
                if (mask == 0) return moves;

                // Cannot move if energy is depleted
                if (e == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Boundary and obstacle check
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 'X') {
                        continue;
                    }

                    int ne = e - 1;
                    int nmask = mask;

                    // If cell is a recharge station, refill energy to max
                    if (grid[nr][nc] == 'R') {
                        ne = energy;
                    }
                    // If cell is an uncollected litter tile, clear its bit
                    else if (grid[nr][nc] == 'L' && litter_id[nr][nc] != -1) {
                        nmask &= ~(1 << litter_id[nr][nc]);
                    }

                    int state_id = get_state_id(nr, nc, nmask, ne);
                    if (!vis[state_id]) {
                        vis[state_id] = true;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};