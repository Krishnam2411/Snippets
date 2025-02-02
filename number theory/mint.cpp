mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll myRand(ll B) {
    return (ull)rng() % B;
}

const ll MOD = 1e9 + 7;

template <ll mod = MOD>
struct mint {
    ll x;

    mint() : x(0) {}
    mint(ll _x) { x = (_x % mod + mod) % mod; }

    mint& operator+=(const mint& a) {
        x = (x + a.x) % mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        x = (x - a.x + mod) % mod;
        return *this;
    }
    mint& operator*=(const mint& a) {
        x = (ull)x * a.x % mod;
        return *this;
    }
    mint pow(ll pw) const {
        mint res = 1, cur = *this;
        while (pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
    mint inv() const {
        assert(x != 0);
        ll t = x, res = 1;
        while (t != 1) {
            ll z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }
    
    mint operator+(const mint& a) const { return mint(*this) += a; }
    mint operator-(const mint& a) const { return mint(*this) -= a; }
    mint operator*(const mint& a) const { return mint(*this) *= a; }
    mint operator/(const mint& a) const { return mint(*this) /= a; }
    
    bool operator==(const mint& a) const { return x == a.x; }
    bool operator!=(const mint& a) const { return x != a.x; }
    bool operator<(const mint& a) const { return x < a.x; }
};

template <ll mod = MOD>
struct Factorials {
    using Mint = mint<mod>;
    vector<Mint> f, fi;

    Factorials(int n) : f(n + 10), fi(n + 10) {
        f[0] = 1;
        for (int i = 1; i < n + 10; i++) f[i] = f[i - 1] * i;
        fi[n + 9] = f[n + 9].inv();
        for (int i = n + 9; i > 0; i--) fi[i - 1] = fi[i] * i;
    }
    
    Mint C(int n, int k) {
        return (k < 0 || k > n) ? 0 : f[n] * fi[k] * fi[n - k];
    }
};

template <ll mod = MOD>
struct Powers {
    using Mint = mint<mod>;
    vector<Mint> p, pi;

    Powers(int n, Mint x) : p(n + 10, 1), pi(n + 10, 1) {
        Mint xi = x.inv();
        for (int i = 1; i < n + 10; i++) {
            p[i] = p[i - 1] * x;
            pi[i] = pi[i - 1] * xi;
        }
    }
    
    Mint pow(int n) { return (n >= 0) ? p[n] : pi[-n]; }
};

template <ll mod = MOD>
struct Inverses {
    using Mint = mint<mod>;
    vector<Mint> ii;

    Inverses(int n) : ii(n + 10, 1) {
        for (int x = 2; x < n + 10; x++)
            ii[x] = Mint() - ii[mod % x] * (mod / x);
    }
    
    Mint inv(Mint x) {
        assert(x.x != 0);
        ll t = x.x, res = 1;
        while (t >= (int)ii.size()) {
            ll z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return ii[t] * res;
    }
};

using Mint = mint<>;