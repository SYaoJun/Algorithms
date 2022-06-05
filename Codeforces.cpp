/*head*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) begin(v),end(v)
#define mst(a,v) memset(a,v,sizeof(a))
#define mcp(a,v) memcpy(a,v,sizeof(a));
#define bitcnt(a) __builtin_popcount(a)
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define subset(i,a) for(int i=a;i;i=a&i-1)
#define cnr(i,n,r) for(int i=(1<<r)-1,_,a=1<<n;i<a;_=i+(i&-i),i=(i&~_)>>__builtin_ffs(i)|_)
#define debug(x...) cout<<#x<<" -> ",Err(x)
const int MOD = 1e9 + 7, INF = 0x3f3f3f3f;
void Err() {cout<<'\n';}
template<class T, class... Ts>
void Err(const T& A,const Ts&... As){cout<<A<<" ";Err(As...);}
const int dirs[8][2] {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
static const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
template <class T>inline bool chmax(T& a, const T& b){return a<b?a=b,1:0;}
template <class T>inline bool chmin(T& a, const T& b){return a>b?a=b,1:0;}

void solve(){
    cout<<"hello world"<<endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}