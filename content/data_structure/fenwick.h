template<class T> 
class fenwick {
    int n;
    vector<T> bit;
public:
    fenwick(int sz) : n(sz) { bit.resize(n+1,0); }
    void add(int idx,T val) {
        assert(idx>0 && idx<n+1);
        for(;idx<=n; idx += (idx&-idx)) bit[idx] += val;
    }
    T qry(int r) {
        assert(r>=0 && r<n+1);
        T s = 0;
        for(; r>0; r-=(r&-r)) s += bit[r];
        return s;
    }
    T rqry(int l,int r) { return qry(r) - qry(l-1); }
};
