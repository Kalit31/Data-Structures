
class Solution {
    public int firstUniqChar(String s) {
        int result = Integer.MAX_VALUE;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int index = s.indexOf(ch);
            if (index != -1 && index == s.lastIndexOf(ch)) {
                result = Math.min(result, index);
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
// int[] count = new int[26];
// for(int i=0;i<s.length();i++){
// count[s.charAt(i)-'a']++;
// }
// for(int i=0;i<s.length();i++){
// if(count[s.charAt(i)-'a']==1)
// return i;
// }
