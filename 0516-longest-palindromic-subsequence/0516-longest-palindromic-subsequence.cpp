// Approach 1: Top Down

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    vector<vector<int>> mem(n, vector<int>(n));
    return lps(s, 0, n - 1, mem);
  }

 private:
  // Returns the length of LPS(s[i..j]).
  int lps(const string& s, int i, int j, vector<vector<int>>& mem) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (mem[i][j] > 0)
      return mem[i][j];
    if (s[i] == s[j])
      return mem[i][j] = 2 + lps(s, i + 1, j - 1, mem);
    return mem[i][j] = max(lps(s, i + 1, j, mem), lps(s, i, j - 1, mem));
  }
};

//Approach 2: Bottom Down

// class Solution {
//  public:
//   int longestPalindromeSubseq(string s) {
//     const int n = s.length();
//     // dp[i][j] := the length of LPS(s[i..j])
//     vector<vector<int>> dp(n, vector<int>(n));

//     for (int i = 0; i < n; ++i)
//       dp[i][i] = 1;

//     for (int d = 1; d < n; ++d)
//       for (int i = 0; i + d < n; ++i) {
//         const int j = i + d;
//         if (s[i] == s[j])
//           dp[i][j] = 2 + dp[i + 1][j - 1];
//         else
//           dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//       }

//     return dp[0][n - 1];
//   }
// };
