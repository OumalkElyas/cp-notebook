struct SCC {
    SCC(int n) : n(n) {
        scc.resize(n,-1);
        vis.resize(n,false);
        adj.resize(n);
        rev.resize(n);
    }
    void add(int u,int v) {
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    void dfs(int u) {
        if(vis[u]) return ;
        vis[u] = true;
        for(auto x : adj[u]) {
            dfs(x);
        }
        order.push_back(u);
    }
    void dfs2(int u) {
        if(scc[u]!=-1) return ;
        scc[u] = d;
        for(auto x : rev[u]) {
            dfs2(x);
        }
    }
    pair<int,vector<int>> build() {
        fill(vis.begin(),vis.end(),false);
        fill(scc.begin(),scc.end(),-1);
        for(int i = 0;i<n;++i) 
            if(!vis[i]) dfs(i);
        d = 1;
        while(!order.empty()) {
            if(scc[order.back()] == -1) dfs2(order.back()),++d;
            order.pop_back();
        }
        return {d-1,scc};
    }
    private:
    int n,d;
    vector<vector<int>> adj,rev;
    vector<int> order,scc;
    vector<bool> vis;
};
