class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        std::unordered_map<int, int> islandSize; // Stores island ID -> size
        int islandId = 2;  
        int maxIsland = 0;


        auto dfs = [&](int r, int c, int id, auto&& dfs_ref) -> int {
            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = id;  // Mark cell with island ID
            return 1 + dfs_ref(r + 1, c, id, dfs_ref) + dfs_ref(r - 1, c, id, dfs_ref)
                     + dfs_ref(r, c + 1, id, dfs_ref) + dfs_ref(r, c - 1, id, dfs_ref);
        };

        // Step 1: Label islands and store their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    islandSize[islandId] = dfs(i, j, islandId, dfs);
                    maxIsland = std::max(maxIsland, islandSize[islandId]);
                    islandId++;
                }
            }
        }

        // Step 2: Try converting each `0` into `1` to form a larger island
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> seen;
                    int newSize = 1;  // Flip this 0 to 1

                    // Check adjacent islands
                    for (auto [dx, dy] : std::vector<std::pair<int, int>>{{0,1},{1,0},{0,-1},{-1,0}}) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            int id = grid[x][y];
                            if (seen.find(id) == seen.end()) {
                                newSize += islandSize[id];
                                seen.insert(id);
                            }
                        }
                    }
                    maxIsland = std::max(maxIsland, newSize);
                }
            }
        }

        // Step 3: If no zero was flipped, return the max found in step 1
        return maxIsland;
    }
};