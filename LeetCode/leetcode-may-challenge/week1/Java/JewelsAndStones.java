
class JewelsAndStones {
    public int numJewelsInStones(String J, String S) {
        int jewels = 0;
        char[] charArr = S.toCharArray();
        for (int i = 0; i < S.length(); i++) {
            if (J.indexOf(charArr[i]) != -1)
                jewels++;
        }
        return jewels;
    }
}