typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define all(v) begin(v),end(v)
#define mst(a,v) memset(a,v,sizeof(a))
#define mcp(a,v) memcpy(a,v,sizeof(a));
#define bitcnt(a) __builtin_popcount(a)
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define debug(x...) cout<<#x<<" -> ",Err(x)
void Err() {cout<<'\n';}
template<class T, class... Ts>
void Err(const T& A,const Ts&... As){cout<<A<<" ";Err(As...);}
const int MOD = 1e9 + 7, INF = 0x3f3f3f3f;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

class Solution {
public:
    int m, n;
    int maximumMinutes(vector<vector<int>>& grid) {
        // 1. 先求人到目的地的最短路径
        m = grid.size();
        n = grid[0].size();
        // 1火 2墙
        int l = -1, r = m*n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(grid, mid)) l = mid;
            else r = mid - 1;
        }
        return left < m*n? left: (int)1e9;
    }
    bool check(vector<vector<int>>& grid, int t){
        // 火先燃烧t秒
        queue<pair<int, int>> q, qq;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]==1){
                    q.push({i, j});
                    st[i][j] = true;
                }
            }
        }
        while(t--){
            int len = q.size();
            while(len--){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int a = dx[i] + x;
                    int b = dy[i] + y;
                    if(a >= 0 && a < m && b >= 0 && b < n){
                        if(grid[a][b]==1 || grid[a][b] == 2 || st[a][b]) continue;
                        st[a][b] = true;
                        q.push({a, b});
                    }
                }
            }
        }
        // 火与人同时走
        if(st[0][0]) return false;
        qq.push({0,0});
        while(qq.size()){
            
            // 火走一步 火走的路径上不能有人的痕迹
            int len2 = q.size();
            while(len2--){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int a = dx[i] + x;
                    int b = dy[i] + y;
                    if(a >= 0 && a < m && b >= 0 && b < n){
                        if(grid[a][b] == 1 || grid[a][b] == 2 || st[a][b]) continue;
                        st[a][b] = true;
                        q.push({a, b});
                    }
                }
            }
            // 人走一步
            int len = qq.size();
            while(len--){
                auto [x, y] = qq.front();
                if(x == m-1 && y == n-1) return true;
                qq.pop();
                for(int i = 0; i < 4; i++) {
                    int a = dx[i] + x;
                    int b = dy[i] + y;
                    if(a >= 0 && a < m && b >= 0 && b < n){
                        if(grid[a][b]==1 || grid[a][b] == 2 || st[a][b]) continue;
                        
                        qq.push({a, b});
                    }
                }
            }
            
        }
        return false;
    }
};
