
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int l1 = text1.length();
        int l2 = text2.length();

        int[][] dp = new int[l1 + 1][l2 + 1];

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[l1][l2];
    }
}

class Solution2 {
    public int longestCommonSubsequence(String text1, String text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        int[][] dp = new int[l1][l2];
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                dp[i][j] = -1;
            }
        }
        return calculate(dp, text1, text2, 0, 0);
    }

    public int calculate(int[][] dp, String t1, String t2, int i1, int i2) {
        if (i1 == t1.length() || i2 == t2.length())
            return 0;
        if (dp[i1][i2] == -1) {
            int c3 = 0;
            if (t1.charAt(i1) == t2.charAt(i2))
                c3 = 1 + calculate(dp, t1, t2, i1 + 1, i2 + 1);
            int c1 = calculate(dp, t1, t2, i1, i2 + 1);
            int c2 = calculate(dp, t1, t2, i1 + 1, i2);
            dp[i1][i2] = Math.max(c1, Math.max(c2, c3));
        }
        return dp[i1][i2];
    }
}