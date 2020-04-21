import java.util.Stack;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {

    }

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode root = new TreeNode(preorder[0]);
        stack.push(root);
        TreeNode current = root;
        for (int i = 1; i < preorder.length; i++) {
            TreeNode temp = new TreeNode(preorder[i]);
            if (temp.val < stack.peek().val) {
                current.left = temp;
                stack.push(temp);
                current = temp;
            } else {
                TreeNode poppedNode = new TreeNode();
                while (!stack.isEmpty() && stack.peek().val < preorder[i]) {
                    poppedNode = stack.pop();
                }
                poppedNode.right = temp;
                stack.push(temp);
                current = temp;
            }
        }
        return root;
    }
}