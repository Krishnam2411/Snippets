ll fact(ll n, ll mod) {
    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

vector<ll> factv(ll n, ll mod) {
    vector<ll> f(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    return f;
}
