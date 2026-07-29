class Solution {
public:
    using ll = long long;
    ll LIMIT;
    ll safeNcr(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k; 
        
        if (k > 62) return LIMIT;

        __int128 res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res > LIMIT) return LIMIT;
        }
        return (ll)res;
    }
    ll countWays(const vector<int>& cnt, int len) {
        __int128 ans = 1;
        int rem = len;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ll comb = safeNcr(rem, cnt[i]);
            ans *= comb;
            if (ans > LIMIT) return LIMIT;
            rem -= cnt[i];
        }

        return (ll)ans;
    }

    string smallestPalindrome(string s, int k) {
        LIMIT = (ll)k;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            halfLen += half[i];
            if (freq[i] % 2) {
                if (!mid.empty()) return ""; 
                mid = char('a' + i);
            }
        }

        if (countWays(half, halfLen) < k)
            return "";

        string left;
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--; 
                ll ways = countWays(half, halfLen - pos - 1);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break; 
                } else {
                    k -= ways;
                    half[c]++; 
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};