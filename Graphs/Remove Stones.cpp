class Solution {
public:

    int find_parent(int i, vector<int> &parent) {
        if (i == parent[i]) return i;
        return parent[i] = find_parent(parent[i], parent);
    }

    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
    
            if (hash1 != hash2) {
                return hash1 ^ hash2;             
            }
            
            // If hash1 == hash2, their XOR is zero.
            return hash1;
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = 0, node = 1, mRow = 0, mCol = 0;
        unordered_map<pair<int, int>, int, hash_pair> uMap;
        for(auto itr : stones) {
            uMap[{itr[0], itr[1]}] = node;
            node++;
            mRow = max(mRow, itr[0]);
            mCol = max(mCol, itr[1]);
        }
        vector<int> parent(node + 1, 0), row(mRow + 1, -1), col(mCol + 1, -1);
        for(int i = 1; i < node; i++) parent[i] = i;
        for(auto itr : stones) {
            int nde = uMap[{itr[0], itr[1]}];
            if(row[itr[0]] == -1 && col[itr[1]] == -1) {
                row[itr[0]] = nde;
                col[itr[1]] = nde;
            } else if (row[itr[0]] == -1 || col[itr[1]] == -1){
                if (row[itr[0]] == -1) {
                    int i = find_parent(col[itr[1]], parent);
                    parent[nde] = i;
                    row[itr[0]] = nde;
                }
                if (col[itr[1]] == -1) {
                    int i = find_parent(row[itr[0]], parent);
                    parent[nde] = i;
                    col[itr[1]] = nde;
                }
            } else {
                int i = find_parent(col[itr[1]], parent);
                int j = find_parent(row[itr[0]], parent);
                if (i != j) parent[i] = j;
                parent[nde] = j;
            }
        }
        for(int i = 1; i < node; i++) if(find_parent(i, parent) == i) ans++;
        return n - ans;
    }
};