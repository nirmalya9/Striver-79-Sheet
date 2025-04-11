//Approach 1: Top Down
class Solution {
public:
    int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> mem(n + 2, vector<int>(n + 2));
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    return maxCoins(nums, 1, n, mem);
  }

 private:
  // Returns maxCoins(nums[i..j]).
  int maxCoins(const vector<int>& nums, int i, int j,
               vector<vector<int>>& mem) {
    if (i > j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    for (int k = i; k <= j; ++k)
      mem[i][j] = max(mem[i][j], maxCoins(nums, i, k - 1, mem) +
                                     maxCoins(nums, k + 1, j, mem) +
                                     nums[i - 1] * nums[k] * nums[j + 1]);

    return mem[i][j];
    }
};

//Approach 2: Bottom Up
// class Solution {
//  public:
//   int maxCoins(vector<int>& nums) {
//     const int n = nums.size();
//     // dp[i][j] := maxCoins(nums[i..j])
//     vector<vector<int>> dp(n + 2, vector<int>(n + 2));

//     nums.insert(nums.begin(), 1);
//     nums.insert(nums.end(), 1);

//     for (int d = 0; d < n; ++d)
//       for (int i = 1; i + d <= n; ++i) {
//         const int j = i + d;
//         for (int k = i; k <= j; ++k)
//           dp[i][j] = max(dp[i][j],                      //
//                          dp[i][k - 1] + dp[k + 1][j] +  //
//                              nums[i - 1] * nums[k] * nums[j + 1]);
//       }

//     return dp[1][n];
//   }
// };


