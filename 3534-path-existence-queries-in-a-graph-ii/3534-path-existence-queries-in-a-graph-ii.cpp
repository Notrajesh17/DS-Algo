class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<int> component(n, 0);

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff) {
                component[i] = component[i - 1] + 1;
            } else {
                component[i] = component[i - 1];
            }
        }

        vector<int> next(n);

        int right = 0;

        for (int i = 0; i < n; i++) {
            right = max(right, i);

            while (right + 1 < n &&
                   arr[right + 1].first - arr[i].first <= maxDiff) {
                right++;
            }

            next[i] = right;
        }

        int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = next[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            int left = pos[u];
            int rightPos = pos[v];

            if (left > rightPos) {
                swap(left, rightPos);
            }

            if (component[left] != component[rightPos]) {
                answer.push_back(-1);
                continue;
            }

            if (left == rightPos) {
                answer.push_back(0);
                continue;
            }

            int jumps = 0;
            int current = left;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][current] < rightPos) {
                    current = up[j][current];
                    jumps += (1 << j);
                }
            }
            answer.push_back(jumps + 1);
        }

        return answer;
        
    }
};