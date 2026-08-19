class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int UNREACHABLE = amount + 1;  // larger than any valid answer

        // minCoins[target] = fewest coins needed to make exactly `target`
        vector<int> minCoins(amount + 1, UNREACHABLE);
        minCoins[0] = 0;

        for (int target = 1; target <= amount; target++) {
            for (int coin : coins) {
                if (coin > target) continue;          // coin doesn't fit
                int remainder = target - coin;
                int candidate = minCoins[remainder] + 1;
                if (candidate < minCoins[target])
                    minCoins[target] = candidate;
            }
        }

        return minCoins[amount] == UNREACHABLE ? -1 : minCoins[amount];
    }
};
