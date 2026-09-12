class Solution {
public:
    struct State {
        long long score;
        vector<int> indices;
    };

    bool better(State &a, State &b) {
        if (a.score != b.score)
            return a.score > b.score;

        // Same score -> lexicographically smaller indices
        return a.indices < b.indices;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [left, right, weight, originalIndex]
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort according to starting point
        sort(arr.begin(), arr.end());

        // Store all starting points
        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }

        // next[i] = first interval whose left > arr[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            next[i] =
                upper_bound(starts.begin(), starts.end(), arr[i][1])
                - starts.begin();
        }

        // dp[i][k] = best answer from i onward
        // when we can still choose at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        // dp[n][k] = score 0, no indices
        for (int k = 0; k <= 4; k++) {
            dp[n][k].score = 0;
            dp[n][k].indices = {};
        }

        // If k = 0, cannot choose anything
        for (int i = 0; i < n; i++) {
            dp[i][0].score = 0;
            dp[i][0].indices = {};
        }

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't choose this interval
                State skip = dp[i + 1][k];

                // Option 2: Choose this interval
                State take;

                take.score = arr[i][2] + dp[next[i]][k - 1].score;

                take.indices = dp[next[i]][k - 1].indices;

                // Add original index
                take.indices.push_back(arr[i][3]);

                // We need indices in increasing order
                sort(take.indices.begin(), take.indices.end());

                // Choose better option
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }
        return dp[0][4].indices;
    }
};