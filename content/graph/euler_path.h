auto euler_path = [](vector<vector<pair<int,int>>> &g,int start,int edges) -> vector<int> {
    int n = int(g.size());

    for(int i = 0;i<n;++i)
	if(int(g[i].size())&1) 
	    return vector<int>{};

    vector<int> edge_ind(n,0);
    vector<bool> used(edges,false);
    vector<int> path;

    stack<int> st;
    st.push(start);
    while(!st.empty()) {
	int node = st.top();
	bool good = false;
	while(edge_ind[node] < int(g[node].size())) {
	    auto [val,id] = g[node][edge_ind[node]++];
	    if(used[id]) continue;
	    used[id] = true;
	    st.push(val);
	    good = true;
	    break;
	}
	if(!good) {
	    path.push_back(node);
	    st.pop();
	}
    }
    return path;
};
