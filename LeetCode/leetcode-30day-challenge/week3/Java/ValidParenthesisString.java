import java.util.Stack;

class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> stack = new Stack<Integer>();
        Stack<Integer> starStack = new Stack<Integer>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                stack.push(i);
            else if (s.charAt(i) == '*') {
                starStack.push(i);
            } else {
                if (!stack.isEmpty()) {
                    stack.pop();
                } else if (!starStack.isEmpty()) {
                    starStack.pop();
                } else
                    return false;
            }
        }

        while (!stack.isEmpty()) {
            if (starStack.isEmpty()) {
                return false;
            } else if (stack.peek() < starStack.peek()) {
                stack.pop();
                starStack.pop();
            } else
                return false;
        }
        return true;
    }
}