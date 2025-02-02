const int N = 1e6+5;

// @returns bool array [1...N]
vector<bool> is_prime(N, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// @returns array of primes [1...N]
vector<ll> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
