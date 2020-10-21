import java.util.*;

public class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {

        List<List<String>> list = new ArrayList<List<String>>();
        Map<String, List<String>> map = new HashMap<String, List<String>>();

        for (String str : strs) {

            char tempArray[] = str.toCharArray();
            Arrays.sort(tempArray);
            String temp = new String(tempArray);
            if (map.containsKey(temp)) {
                List<String> ls = map.get(temp);
                ls.add(str);
                map.put(temp, ls);
            } else {
                List<String> ls = new ArrayList<String>();
                ls.add(str);
                map.put(temp, ls);
            }
        }

        for (List<String> ls : map.values()) {
            list.add(ls);
        }
        return list;
    }
}