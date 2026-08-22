class Solution {
    struct Node {
        int len, pref, suff, best;
        char leftChar, rightChar;

        Node() : len(0), pref(0), suff(0), best(0), leftChar('#'), rightChar('#') {}

        Node(char c) : len(1), pref(1), suff(1), best(1),
                       leftChar(c), rightChar(c) {}
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            tree[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            tree[idx] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, c);
        else
            update(2 * idx + 1, mid + 1, r, pos, c);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};