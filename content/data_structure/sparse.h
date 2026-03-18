template<typename T,typename F>
struct sparse {
    sparse(vector<T> &a,F _f) : f(_f) {
        n = int(a.size()); 
        LOG = __lg(n) + 1;
        lt.resize(LOG,vector<T>(n));
        for(int i = 0;i<n;++i) lt[0][i] = a[i]; 
        for(int i = 1;i<LOG;++i) 
            for(int j = 0;j + (1<<i) <= n;++j) 
                lt[i][j] = f(lt[i-1][j],lt[i-1][j + (1<<(i-1))]);
    }
    ll get(int l,int r) {
        int d = __lg(r - l + 1);
        return f(lt[d][l],lt[d][r-(1<<d)+1]);
    }
private:
    vector<vector<T>> lt;
    F f;
    int LOG,n;
};
