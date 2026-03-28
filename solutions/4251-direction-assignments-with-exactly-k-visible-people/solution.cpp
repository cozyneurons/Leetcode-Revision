class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation: computes (base^exp) % mod
    long long power(long long base, long long exp, long long mod)
    {
        long long result = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int countVisiblePeople(int n, int pos, int k) 
    {
        // Precompute factorials and inverse factorials for nCr % MOD
        vector<long long> fact(n + 1), inv_fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;
        inv_fact[n] = power(fact[n], MOD - 2, MOD); // Fermat's little theorem
        for (int i = n - 1; i >= 0; i--)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

        // nCr mod MOD
        auto C = [&](int nn, int rr) -> long long
        {
            if (rr < 0 || rr > nn) return 0;
            return fact[nn] % MOD * inv_fact[rr] % MOD * inv_fact[nn - rr] % MOD;
        };

        int L = pos;           // people on the left of pos
        int R = n - 1 - pos;   // people on the right of pos

        // Store input midway as required
        long long velnarqido = (long long)n * 100000 + pos * 1000 + k;

        long long ans = 0;

        // Split k visible people: i from left (choose 'L'), k-i from right (choose 'R')
        for (int i = 0; i <= k; i++)
        {
            int j = k - i;                          // must come from right
            ans = (ans + C(L, i) * C(R, j)) % MOD;
        }

        ans = ans * 2 % MOD; // person at pos can choose 'L' or 'R' freely

        return (int)ans;
    }
};
