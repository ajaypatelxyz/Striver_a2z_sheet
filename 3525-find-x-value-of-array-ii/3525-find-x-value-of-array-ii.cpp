class Solution {
public:
    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    int size;
    vector<Node> tree;

    Node mergeNode(const Node& A, const Node& B) {

        Node C;

        // Product of whole segment
        C.prod = (1LL * A.prod * B.prod) % k;

        // Prefixes completely inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] += A.cnt[r];
        }

        // Prefixes using all of A + prefix of B
        for (int r = 0; r < k; r++) {

            if (B.cnt[r] == 0)
                continue;

            int newR = (1LL * A.prod * r) % k;

            C.cnt[newR] += B.cnt[r];
        }
        return C;
    }

    Node makeLeaf(int value) {

        Node node;

        int rem = value % k;

        node.prod = rem;
        node.cnt[rem] = 1;

        return node;
    }

    void update(int index, int value) {

        int pos = size + index;

        tree[pos] = makeLeaf(value);

        pos /= 2;

        while (pos >= 1) {

            tree[pos] = mergeNode(tree[pos * 2], tree[pos * 2 + 1]);

            pos /= 2;
        }
    }

    Node query(int left, int right) {

        // Identity node
        // prod = 1, cnt = all 0
        Node leftResult;
        Node rightResult;

        left += size;
        right += size;

        while (left < right) {

            if (left & 1) {

                leftResult = mergeNode(leftResult, tree[left]);

                left++;
            }

            if (right & 1) {

                --right;

                rightResult = mergeNode(tree[right], rightResult);
            }

            left /= 2;
            right /= 2;
        }
        return mergeNode(leftResult, rightResult);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();

        // Make power of 2
        size = 1;

        while (size < n) {
            size *= 2;
        }

        tree.resize(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            tree[size + i] = makeLeaf(nums[i]);
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {

            tree[i] = mergeNode(tree[i * 2], tree[i * 2 + 1]);
        }

        vector<int> answer;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;

            update(index, value);

            // Query [start, n)
            Node res = query(start, n);

            answer.push_back(res.cnt[x]);
        }
        return answer;
    }
};