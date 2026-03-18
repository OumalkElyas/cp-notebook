auto dijkstra = [&](int s) {
    dist[s] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.emplace(0LL,s);
    while(!q.empty()) {
	auto [cost,u] = q.top(); q.pop();
	if(cost > dist[u]) continue;
	for(auto [v,w] : adj[u]) {
	    if(cost + w < dist[v]) {
		dist[v] = cost + w;
		par[v] = u;
		q.emplace(dist[v],v);
	    }
	}
    }
};
