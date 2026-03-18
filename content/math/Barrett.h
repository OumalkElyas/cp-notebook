template<class T>
ull Barrett(T a){
    static ull m = -1ull / Mod;
    ull q = (__uint128_t(m) * a) >> 64;
    ull r = a - q * Mod;
    if(r >= Mod) r -= Mod;
    return r;
}
