package dynamicProgramming;

public class ConvertStringToAnotherTopToBottom {
    public static void main(String[] args) {
        String s1 = "table";
        String s2 = "tbres";
        Integer[][] dp = new Integer[s1.length()+1][s2.length()+1];
        System.out.println(findMinOperationsRecursive(dp,"table", "tbres",0,0));

    }
    private static int findMinOperationsRecursive(Integer[][] dp, String s1, String s2, int i1, int i2) {
        if(dp[i1][i2] == null) {
            if(i1 == s1.length()) // if we have reached the end of s1, then insert all the remaining characters of s2
                dp[i1][i2] = s2.length() - i2;

            else if(i2 == s2.length()) // if we have reached the end of s2, then delete all the remaining characters of s1
                dp[i1][i2] = s1.length() - i1;

            else if(s1.charAt(i1) == s2.charAt(i2)) // If the strings have a matching character, recursively match for the remaining lengths.
                dp[i1][i2] = findMinOperationsRecursive(dp, s1, s2, i1+1, i2+1);

            else {
                int c1 = findMinOperationsRecursive(dp, s1, s2, i1+1, i2); //delete
                int c2 = findMinOperationsRecursive(dp, s1, s2, i1, i2+1); //insert
                int c3 = findMinOperationsRecursive(dp, s1, s2, i1+1, i2+1); //replace
                dp[i1][i2] = 1 + Math.min(c1, Math.min(c2, c3));
            }
        }//end of if-else
        return dp[i1][i2];
    }
}
