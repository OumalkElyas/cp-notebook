struct DSU {
    DSU(int n) {
        lead.resize(n);
        sz.resize(n,1);
        iota(lead.begin(),lead.end(),0);
        sets = n;
    }
    int find(int u) { return lead[u] == u ? u : lead[u] = find(lead[u]); }
    bool add(int u,int v) {
        int x = find(u), y = find(v);
        if(x==y) return false;
        if(sz[x] < sz[y]) swap(x,y);
        lead[y] = x;
        sz[x] += sz[y];
        --sets;
        return true;
    }
private:
    vector<int> lead,sz;
    int sets;
};
