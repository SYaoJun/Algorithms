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