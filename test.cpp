typedef pair<int, int> PII;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
class Solution {
public:
    int m, n;
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int left = -1, right = m * n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(grid, mid)) left = mid;
            else right = mid - 1;
        }
        return left < m * n ? left : 1e9;

    }

    bool fire_spread(queue<PII> &fire, vector<vector<bool>>& st){
        // 层序遍历，扩展每一层的数据
        int len = fire.size();
        while(len--){
            auto [x, y] = fire.front();
            fire.pop();
            for(int i = 0; i < 4; i++) {
                int a = dx[i] + x;
                int b = dy[i] + y;
                if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b] && grid[a][b]!=2){
                    st[a][b] = true;
                    fire.push({a, b});
                }
            }
        }
    }
    bool check(vector<vector<int>>& grid, int t){
        // 火先燃烧t秒
        queue<PII> fire, person;
        vector<vector<bool>> st(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]==1){
                    fire.push({i, j});
                    st[i][j] = true;
                }
            }
        }
        while(t-- && fire.size()){
            fire_spread(fire, st);
        }
        // 火与人同时走, 人要先走
        if(st[0][0]) return false;
        person.push({0,0});
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[0][0] = true;
        while(person.size()){
            
            // 人走一步 👨🏻/👩🏻
            int len = person.size();
            while(len--){
                auto [x, y] = person.front();
                person.pop();
                if(st[x][y]) continue;  // 这里很关键，要判断人往四周走的时候，原位置是否被火🔥烧到了
                for(int i = 0; i < 4; i++) {
                    int a = dx[i] + x;
                    int b = dy[i] + y;
                    if(a >= 0 && a < m && b >= 0 && b < n && !st[a][b] && !vis[a][b] && grid[a][b] != 2){
                        if(a == m-1 && b == n-1) return true;
                        vis[a][b] = true;
                        person.push({a, b});
                    }
                }
            }

            // 火走一步 🔥
            fire_spread(fire, st);
        }
        return false;
    }
    
};

[64,37,33,5,13,47,35,3,67,26,50,44,55,7,62,10,16,45,27,68,69,93,49,67,21,64,97,88,51,23,62,31,76,57,69,52,70,32,55,14,92,50,41,9,98,50,82,14,31,85,89,80,96,62,10,19,47,40,25,27,49,40,72,18,12,21,53,94,69,90,6,93,47,14,18,81,73,60,36,2,62,14,7,95,96,16,40,9,72,50,40,14,67,51,30,31,82,35,70,14,22,53,11,13,67,90,16,46,70,6,79,31,94,52,62,65,1,32,51,2,27,64,42,11,55,61,45,55,11,1,34,86,84,21,58,40,76,45,68,17,75,79,96,78,80,31,59,63,78]
91
11