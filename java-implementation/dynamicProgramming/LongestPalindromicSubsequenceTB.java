package dynamicProgramming;

public class LongestPalindromicSubsequenceTB {
    public static void main(String[] args) {
        String st = "elrmenmet";
        Integer[][] dp = new Integer[st.length()][st.length()];
        System.out.println("Longest Palindromic Sequence: " + LPS(dp,st,0,st.length()-1));
    }
    public static int LPS(Integer[][] dp,String st, int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }
        if (startIndex == endIndex) {
            return 1;
        }
        if(dp[startIndex][endIndex]==null) {
            int count1 = 0;
            if (st.charAt(startIndex) == st.charAt(endIndex)) { //CASE#1 - If index pointed characters matches, then we add 2 to the existing known palindrome length
                count1 = 2 + LPS(dp, st, startIndex + 1, endIndex - 1);
            }
            int Count2 = LPS(dp, st, startIndex + 1, endIndex); //CASE#2 - Skip one element from beginning
            int Count3 = LPS(dp, st, startIndex, endIndex - 1); //CASE#3 - Skip one element from end
            dp[startIndex][endIndex] =  Math.max(count1, Math.max(Count2, Count3));
        }
        return dp[startIndex][endIndex];
    }
}
