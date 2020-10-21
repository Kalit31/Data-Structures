package divideAndConquer;

public class LongestPalindromicSubsequence {

    public static int LPS(String st, int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }
        if (startIndex == endIndex) {
            return 1;
        }
        int count1 = 0;
        if (st.charAt(startIndex) == st.charAt(endIndex)) { //CASE#1 - If index pointed characters matches, then we add 2 to the existing known palindrome length
            count1 = 2 + LPS(st, startIndex + 1, endIndex - 1);
        }
        int Count2 = LPS(st, startIndex + 1, endIndex); //CASE#2 - Skip one element from beginning
        int Count3 = LPS(st, startIndex, endIndex - 1); //CASE#3 - Skip one element from end
        return Math.max(count1,Math.max(Count2, Count3));
    }

    public static void main(String[] args) {
        String st = "elrmenmet";
        System.out.println("Longest Palindromic Sequence: " + LPS(st,0,st.length()-1));
    }
}
