package dynamicProgramming;

public class LongestPalindromicSubstringTB {
    public static void main(String[] args) {
        String str = "ABCCBUA";
        Integer[][] dp = new Integer[str.length()][str.length()];
        System.out.println("Longest Palindromic Substring: " + lps(dp, str,0,str.length()-1));
    }
    public static int lps(Integer[][] dp,String string, int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }
        if (startIndex == endIndex) {
            return 1;
        }
        if(dp[startIndex][endIndex]==null) {
        int c1 = 0;
        if (string.charAt(startIndex) == string.charAt(endIndex)) {  //CASE#1 - If index pointed characters matches then we
            int remainingLength = endIndex - startIndex - 1;
            //add 2 to the existing known palindrome length only if remaining string is a palindrome too
            if (remainingLength == lps(dp,string, startIndex + 1, endIndex - 1))
                c1 = remainingLength + 2;
        }
        int c2 = lps(dp,string, startIndex + 1, endIndex);//CASE#2 - Skip one element from beginning
        int c3 = lps(dp,string, startIndex, endIndex - 1);//CASE#3 - Skip one element from end
            dp[startIndex][endIndex] =  Math.max(c1, Math.max(c2, c3));
        }
        return dp[startIndex][endIndex];
    }
}
