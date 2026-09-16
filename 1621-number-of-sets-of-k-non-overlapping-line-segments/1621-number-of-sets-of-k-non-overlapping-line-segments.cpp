
class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int choose = 2 * k;

        vector<long long> fact(total + 1);
        vector<long long> invFact(total + 1);

        fact[0] = 1;

        for (int i = 1; i <= total; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[total] = power(fact[total], MOD - 2);

        for (int i = total; i > 0; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return fact[total] * invFact[choose] % MOD
             * invFact[total - choose] % MOD;
    }
};