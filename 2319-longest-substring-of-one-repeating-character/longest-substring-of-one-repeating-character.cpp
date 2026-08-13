class Solution {
public:
    struct Node {
        int len, pref, suff, best;
        char left, right;
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        if (a.pref == a.len && a.right == b.left)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.right == b.left)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);
        if (a.right == b.left)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,vector<int>& queryIndices) {
        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};