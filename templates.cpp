// 筛素数
const int N = 2e5+10;
bool st[N];
int primes[N];
int k = 0;
void getPrimes(int n){
    for(int i = 2; i <= n; i ++) {
        if(!st[i]) primes[k++] = i;
        for(int j = 0; primes[j] <= n / i; j++) {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
// 二维三角形面积
double get(vector<int>& a, vector<int>& b, vector<int>& c){
    vector<int> ab{b[0]-a[0], b[1]-a[1]};
    vector<int> ac{c[0]-a[0], c[1]-a[1]};
    return abs((ab[0]*ac[1] - ab[1]*ac[0])/ 2.0);
}
// 字符流
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string str;
        int cnt = 0;
        while(ss >> str){
            cnt++;
        }
        return cnt;
    }
};
// 随机数
#include <random>
int main(){
    std::mt19937 rnd(std::random_device{}());
    cout<<rnd()<<endl;
}
// 并查集.cpp
struct DSU{
    int n;
    vector<int> p;
    vector<int> rk;
    DSU(int n){
        this->n = n;
        p.resize(n+1);
        rk.resize(n+1);
        init();
    }
    void init() { for (int i = 1; i <= n; i++) p[i] = i, rk[i] = 1; }
    int inline find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void inline merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rk[x] > rk[y]) swap(x, y);
        rk[y] += rk[x], p[x] = y;
    }
};
// 树状数组
class BIT{
    using LL = long long;
    vector<LL> tr;
    vector<LL> d1;
    vector<LL> d2;
    int n;
public:
    BIT(int n){
        n += 10;
        this->n = n;
        tr.resize(n);
        d1.resize(n);
        d2.resize(n);
    }
    int lowbit(int index){
        return index&-index;
    }
    void add(int index, LL value) {
        add(tr, index, value);
    }
    LL query(int index){
        return query(tr, index);
    }
    void add_range(int l, int r, LL value){
        add(d1, l, value);
        add(d2, l, l*value);
        add(d1, r+1, -value);
        add(d2, r+1, -(r+1)*value);
    }
    LL query_range(int index){
        return query(d1, index)*(index+1) - query(d2, index);
    }
private:
    void add(vector<LL> &t, int index, LL value) {
        for(int i = index; i < n; i+= lowbit(i)) t[i] += value;
    }
    LL query(vector<LL> &t, int index){
        LL res = 0;
        for(int i = index; i; i-= lowbit(i)) res += t[i];
        return res;
    }
};


// 凸包
void inline andrew() {
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        while (top > 1 && area(p[s[top - 1]], p[s[top]], p[i]) < 0) {
            if (area(p[s[top - 1]], p[s[top]], p[i]) <= 0) st[s[top--]] = false;
            else top--;
        }
        st[i] = true, s[++top] = i;
    }
    st[1] = false;
    for (int i = n; i; i--) {
        if (!st[i]) {
            while (top > 1 && area(p[s[top - 1]], p[s[top]], p[i]) <= 0) 
                st[s[top--]] = false;
            st[i] = true, s[++top] = i;
        }
    }
    for (int i = 0; i < top; i++) s[i] = s[i + 1];
    top--;
}
// 最大公约数

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

// 最小公倍数


int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

//判断素数
//时间复杂度$O(sqrt(n)/3)$
//根据质数分布规律：大于等于5的质数一定是和6的倍数相邻。

bool check(int x) {
    if(x == 2|| x == 3 ||x == 5) return true;
    if(x <= 5) return false;
    if(x%6 != 1 && x%6 != 5) return false;
    for(int i = 5; i*i <= x; i += 6){
        if(x % i == 0 || x % (i+2)==0) return false;
    }
    return true;
}
// 埃氏筛法

int primes[N];
bool p[N] = {0};
int k = 0;
void get_primes(){
    for(int i = 2; i < N; i++){
        if(!p[i]){
            primes[k++] = i;
            for(int j = i+i; j < N; j += i){
                p[j] = 1;
            }
        }
    }
}

// Dijkstra算法
// 朴素版Dijkstra算法
// 通常用邻接矩阵存，顶点数在500范围内，注意图的边初始化为正无穷。
int Dijkstra(){
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for(int i = 0; i < n; i++){ //迭代n次
        int u = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (u == -1 || d[u] > d[j])){
                u = j;
            }
        if(u == -1) return -1;
        st[u] = true;
        for(int v = 1; v <= n; v++){
            d[v] = min(d[v], d[u] + G[u][v]);
        }
    }
    if(d[n] == 0x3f3f3f3f) return -1;
    else return d[n];
}

//2. 堆优化版的Dijkstra算法
//        通常用邻接表存，顶点数在$10^5$范围内，注意邻接表表头的初始化。

void add(int a, int b, int c){ //加边加权
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a]=idx++;
}
int dijkstra(){
    memset(d, 0x3f, sizeof d);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    d[1] = 0;
    pq.push({0, 1});
    while(pq.size()){
        auto t = pq.top();
        pq.pop();
        int ver = t.second, dist = t.first;
        if(st[ver]) continue; //用于处理重边和自环
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] > w[i] + dist){ //注意这里的更新方式， 是从现有的最短距离上，判断加上边权能否改变
                d[j] = w[i] + dist;
                pq.push({d[j], j});
            }
        }
    }
    if(d[n]==0x3f3f3f3f) return -1;
    else return d[n];
}
//## SPFA算法
//$O(mlogm)$
//        处理有负权但是没有负环的单源最短路径
//这里是用的队列，而Dijkstra堆优化用的是优先队列
int spfa(int s){
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;  //注意，这里要对在队列中的顶点进行标记
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] > d[t]+ w[i]){
                d[j] = d[t]+ w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }

    }
    if(d[n] == 0x3f3f3f3f) return -1;
    else return d[n];
}
//## Floyd算法
//$O(n^3)$
//        用邻接矩阵存储，通常顶点数小于200
void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

//## 拓扑排序
//        图使用邻接表存储
bool topsort(){
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!ind[i]) q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        cnt++;
        for(int j = 0; j < G[t].size(); j++){
            int v = G[t][j];
            ind[v]--;
            if(!ind[v]) q.push(v);
        }
    }
    if(cnt == n) return 1;
    else return 0;
}


//## Trie树
int son[N][26], cnt[N], idx = 0;
void insert(string &word){
    int p = 0;
    for(int i = 0; i < word.size(); i++){
        int u = word[i] - 'a';
        if(son[p][u] == 0) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}
int query(string &word){
    int p = 0;
    for(int i = 0; i < word.size(); i++){
        int u = word[i] - 'a';
        if(son[p][u] == 0) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

// 01背包
for(int i = 1; i <= N; i++){
for(int c = V; c >= w[i]; c--){
dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
}
}

//2. 完全背包

for(int i = 1; i <= N; i++){
for(int c = w[i]; c <= V; c++){
dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
}
}

//## 字符串哈希

using ULL = unsigned long long;
static const int N = 2e3;
ULL p[N], h[N];
const int static P = 131;
ULL get(int l, int r){
    return h[r] - h[l-1] * p[r - l + 1];
}

// main
int n = s.size();
s = ' ' + s;
// 预处理字符串前缀
p[0] = 1;
for(int i = 1; i <= n; i++) {
p[i] = p[i-1] * P;
h[i] = h[i-1] * P + s[i];
}