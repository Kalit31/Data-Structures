class Solution {
    public String stringShift(String s, int[][] shift) {

        // assuming left shift: +ve, right shift: -ve
        int shiftAmt = 0;
        for (int i = 0; i < shift.length; i++) {
            shiftAmt += shift[i][0] == 0 ? shift[i][1] : -shift[i][1];
        }

        shiftAmt = shiftAmt > 0 ? shiftAmt % (s.length()) : -((-shiftAmt) % (s.length()));

        if (shiftAmt >= 0)
            return s.substring(shiftAmt) + s.substring(0, shiftAmt);
        else
            return s.substring(s.length() + shiftAmt) + s.substring(0, s.length() + shiftAmt);
    }
}