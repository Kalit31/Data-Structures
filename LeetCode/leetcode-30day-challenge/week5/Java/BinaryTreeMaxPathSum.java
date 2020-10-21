
//  Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    int max = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        calculate(root);
        return max;
    }

    public int calculate(TreeNode node) {
        if (node == null)
            return 0;
        max = Math.max(node.val, max);
        int lValue = calculate(node.left);
        int rValue = calculate(node.right);
        max = Math.max(max, node.val + lValue);
        max = Math.max(max, node.val + rValue);
        max = Math.max(max, lValue + rValue + node.val);
        return Math.max(node.val, Math.max(lValue, rValue) + node.val);
    }
}