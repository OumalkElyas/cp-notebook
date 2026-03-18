template<int M = int(1e9+7)>
struct matrix {
    matrix(int _n) : n(_n), mat(_n,vector<ll>(_n,0)) {}
    matrix(const vector<vector<ll>>& v) : n(int(v.size())),mat(v) {}
    matrix friend operator *(const matrix &a,const matrix &b) {
        int n = a.n;
        matrix c(n);
        for(int i = 0;i<n;++i) 
            for(int j = 0;j<n;++j)
                for(int k=0;k<n;++k)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j])%M;
        return c;
    }

    static matrix ident(int n) {
        matrix ret(n);
        for(int i = 0;i<n;++i) ret.mat[i][i] = 1;
        return ret;
    }

    vector<ll>& operator[](int i) { return mat[i]; }
    const vector<ll>& operator[](int i) const { return mat[i]; }

    matrix power(ll k) {
        matrix base = *this,ans = ident(n);
        while(k) {
            if(k&1) ans = ans * base;
            base = base * base;
            k>>=1;
        }
        return ans;
    }
private:
    vector<vector<ll>> mat;
    int n;
};
