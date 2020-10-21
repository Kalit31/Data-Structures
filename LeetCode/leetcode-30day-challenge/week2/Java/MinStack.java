import java.util.Stack;

class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> stack;
    Stack<Integer> auxStack;

    public MinStack() {
        stack = new Stack<Integer>();
        auxStack = new Stack<Integer>();
    }

    public void push(int x) {
        if (stack.isEmpty()) {
            stack.push(x);
            auxStack.push(x);
        } else if (auxStack.peek() < x) {
            stack.push(x);
        } else {
            stack.push(x);
            auxStack.push(x);
        }

    }

    public void pop() {
        if (stack.peek().equals(auxStack.peek())) {
            stack.pop();
            auxStack.pop();
        } else {
            stack.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return auxStack.peek();
    }
}