package divideAndConquer;

public class LongestCommonSubsequence {
    public static void main(String[] args) {
        System.out.println(findLCSLength("houdini", "hdupti",0,0));
    }

    public static int findLCSLength(String s1, String s2, int i1, int i2) {
        if (i1 == s1.length() || i2 == s2.length())
            return 0;

        int c3 = 0;
        if (s1.charAt(i1) == s2.charAt(i2)) {//If current character in both the string matches, then increase the index by 1 in both the strings.
            c3 = 1 + findLCSLength(s1, s2, i1 + 1, i2 + 1);
        }

        int c1 = findLCSLength(s1, s2, i1, i2 + 1);//Increase index of 2nd String
        int c2 = findLCSLength(s1, s2, i1 + 1, i2);//Increase index of 1st String

        return Math.max(c3, Math.max(c1, c2));
    }
}
