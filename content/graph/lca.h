auto lca = [&](int u,int v) {
    if(d[u] < d[v])
	swap(u,v);
    for(int i = 19; ~i; --i)
	if(d[u] - (1<<i)>=d[v])
	    u = anc[u][i];
    if(u==v) return u;
    for(int i = 19; ~i; --i)
	if(anc[u][i]^anc[v][i])
	    u = anc[u][i], v = anc[v][i];
    return anc[u][0];
};
