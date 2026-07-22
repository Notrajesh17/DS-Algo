class SegmentTree {
    int n;
    vector<int> arr, seg;

    void build(int p, int l, int r) 
    {
        if (l == r) 
        {
            seg[p] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        
        build(p * 2, l, mid);

        build(p * 2 + 1, mid + 1, r);

        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    }

    int queryUtil(int p, int l, int r, int L, int R) 
    {
        if (L <= l && r <= R) return seg[p];

        int mid = (l + r) / 2;

        int ans = 0;

        if (L <= mid)
        {
            ans = max(ans, queryUtil(p * 2, l, mid, L, R));
        }
        if (R > mid)
        {
            ans = max(ans, queryUtil(p * 2 + 1, mid + 1, r, L, R));
        }

        return ans;

    }

public:
    SegmentTree(vector<int> &v) 
    {
        arr = v;

        n = arr.size();
        seg.assign(4 * max(1, n), 0);

        if (n) build(1, 0, n - 1);
    }

    int query(int l, int r) 
    {
        if (l > r || n == 0) return 0;

        return queryUtil(1, 0, n - 1, l, r);
    }
};

class Solution 
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) 
    {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<int> zeroLen;
        vector<int> leftPos;
        vector<int> rightPos;

        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) i++;

            if (s[st] == '0') 
            {
                zeroLen.push_back(i - st);
                leftPos.push_back(st);
                rightPos.push_back(i - 1);
            }
        }

        int m = zeroLen.size();

        if (m < 2) 
        {
            return vector<int>(queries.size(), ones);
        }

        vector<int> sum(m - 1);
        for (int i = 0; i < m - 1; i++) 
        {
            sum[i] = zeroLen[i] + zeroLen[i + 1];
        }

        SegmentTree seg(sum);

        vector<int> ans;

        for (auto &q : queries) 
        {
            int l = q[0];
            int r = q[1];

            int L = lower_bound(rightPos.begin(), rightPos.end(), l) - rightPos.begin();
            int R = upper_bound(leftPos.begin(), leftPos.end(), r) - leftPos.begin() - 1;

            if (L > m - 1 || R < 0 || L >= R) 
            {
                ans.push_back(ones);
                continue;
            }

            int first = rightPos[L] - max(leftPos[L], l) + 1;
            int last = min(rightPos[R], r) - leftPos[R] + 1;

            if (L + 1 == R) 
            {
                ans.push_back(ones + first + last);
                continue;
            }

            int x = first + zeroLen[L + 1];
            int y = zeroLen[R - 1] + last;
            int z = seg.query(L + 1, R - 2);

            ans.push_back(ones + max({x, y, z}));
        }

        return ans;
        
    }
};