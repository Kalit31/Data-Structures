package divideAndConquer;

public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        String str = "ABCCBUA";
        System.out.println("Longest Palindromic Substring: " + lps(str,0,str.length()-1));
    }

    public static int lps(String string, int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }
        if (startIndex == endIndex) {
            return 1;
        }
        int c1 = 0;
        if (string.charAt(startIndex) == string.charAt(endIndex)) {  //CASE#1 - If index pointed characters matches then we
            int remainingLength = endIndex - startIndex - 1;
            //add 2 to the existing known palindrome length only if remaining string is a palindrome too
            if (remainingLength == lps(string, startIndex + 1, endIndex - 1))
                c1 = remainingLength + 2;
        }
        int c2 = lps(string, startIndex + 1, endIndex);//CASE#2 - Skip one element from beginning
        int c3 = lps(string, startIndex, endIndex - 1);//CASE#3 - Skip one element from end
        return Math.max(c1, Math.max(c2, c3));//Take the max sized palindrome
    }
}