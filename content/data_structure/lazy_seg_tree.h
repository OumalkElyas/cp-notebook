class lazysegtree {
    int n;
    vector<ll> tr;
    vector<ll> lz;
public: 
    lazysegtree(const vector<ll> &a) {
        n = a.size();
        tr.resize(4*n,0);
        lz.resize(4*n,0);
        build(1,0,n-1,a);
    }
    void build(int x,int l,int r,const vector<ll> &a) {
        if(r < l) return ;
        if(l == r) {
            tr[x] = a[l];
            return ;
        }
        int m = (l+r)/2;
        build(2*x,l,m,a);
        build(2*x+1,m+1,r,a);
        tr[x] = max(tr[2*x],tr[2*x+1]);
    }
    void push(int x) {
        if(lz[x] == 0) return ;
        tr[2*x] += lz[x];
        tr[2*x+1] += lz[x];
        lz[2*x] += lz[x];
        lz[2*x+1] += lz[x];
        lz[x] = 0;
    }
    void upd(int x,int l,int r,int a,int b,ll val) {
        if(a>r || b<l) return ;
        if(a<=l && b>=r) {
            tr[x] += val;
            lz[x] += val;
            return;
        } 
        push(x);
        int m = (l+r)/2;
        upd(2*x,l,m,a,b,val);
        upd(2*x+1,m+1,r,a,b,val);
        tr[x] = max(tr[2*x],tr[2*x+1]);
    }
    long long qry(int x,int l,int r,int a,int b) {
        if(a>r || b<l) return -Inf;
        else if(a<=l && b>=r) {
            return tr[x];
        } 
        push(x);
        int m = (l+r)/2;
        ll lm = qry(2*x,l,m,a,b);
        ll rm = qry(2*x+1,m+1,r,a,b);
        return max(lm,rm);
    }
};
