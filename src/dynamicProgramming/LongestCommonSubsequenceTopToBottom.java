package dynamicProgramming;

public class LongestCommonSubsequenceTopToBottom {
    public static void main(String[] args) {
        String s1="houdini";
        String s2="hdupti";
        Integer[][] dp = new Integer[s1.length()][s2.length()];
        for (int i = 0; i < s1.length(); i++) // initialize all values with '-1'
            for (int j = 0; j < s2.length(); j++)
                dp[i][j] = -1;
        System.out.println(findLCSLength(dp,s1, s2,0,0));
    }
    public static int findLCSLength(Integer[][] dp,String s1, String s2, int i1, int i2) {
        if (i1 == s1.length() || i2 == s2.length())
            return 0;
        if (dp[i1][i2] == -1)
            if (s1.charAt(i1) == s2.charAt(i2)) {//If current character in both the string matches, then increase the index by 1 in both the strings.
                dp[i1][i2] = 1 + findLCSLength(dp,s1, s2, i1 + 1, i2 + 1);
                return dp[i1][i2];
            }else {
                int c1 = findLCSLength(dp, s1, s2, i1, i2 + 1);//Increase index of 2nd String
                int c2 = findLCSLength(dp, s1, s2, i1 + 1, i2);//Increase index of 1st String
                dp[i1][i2] = Math.max(c1,c2);
            }
        return dp[i1][i2];
    }
}
