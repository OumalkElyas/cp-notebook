auto negCyc = [&](vector<edge> &edges,int n) {
    vector<long long> dist(n,1e18);
    vector<int> par(n,-1);
    int d = -1;
    for(int i = 0;i<n;++i) {
	d = -1;
	for(auto [u,v,w] : edges) {
	    if(dist[v] > dist[u] + w) {
		dist[v] = dist[u] + w;
		par[v] = u;
		d = v;
	    }
	}
	if(d==-1) return vector<int>();
    }
    for(int i = 0;i<n;++i) d = par[d];
    vector<int> ans(1,d);
    int e = par[d];
    while(e!=d) {
	ans.push_back(e);
	e = par[e];
    }
    ans.push_back(d);
    reverse(ans.begin(),ans.end());
    return ans;
};
