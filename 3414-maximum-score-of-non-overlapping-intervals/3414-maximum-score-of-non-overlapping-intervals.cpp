class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    static bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a;
        a.reserve(n);

        for (int i = 0; i < n; ++i) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // left endpoints for binary search
        vector<long long> left(n);
        for (int i = 0; i < n; ++i)
            left[i] = a[i][0];

        // nxt[i] = first interval whose left endpoint > a[i].right
        vector<int> nxt(n);
        for (int i = 0; i < n; ++i) {
            nxt[i] = upper_bound(
                left.begin(),
                left.end(),
                a[i][1]
            ) - left.begin();
        }

        // dp[i][k]:
        // best result using intervals i..n-1,
        // choosing at most k intervals.
        vector<array<State, 5>> dp(n + 1);

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                // Option 1: skip interval i
                State skip = dp[i + 1][k];

                // Option 2: take interval i
                State take = dp[nxt[i]][k - 1];
                take.score += a[i][2];

                int originalIndex = (int)a[i][3];

                // Keep indices sorted so vector comparison gives
                // the required lexicographical ordering.
                take.ids.insert(
                    lower_bound(
                        take.ids.begin(),
                        take.ids.end(),
                        originalIndex
                    ),
                    originalIndex
                );

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].ids;
    }
};