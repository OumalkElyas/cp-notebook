void sieve() {
    iota(spf,spf+N,0);
    mu[1] = 1;
    for(int i = 2;i<N;++i) {
	if(spf[i]==i) { 
	    primes.push_back(i);
	    mu[i] = -1;
	}
	for(int p : primes) {
	    if(i*p >=  N || p > spf[i]) break;
	    spf[i*p] = p;

	    if(spf[i] == p) mu[i*p] = 0;
	    mu[i*p] = spf[i] == p ? 0 : -mu[i];
	}
    }
}
