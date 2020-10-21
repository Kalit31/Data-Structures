// Definition for a binary tree node.
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

    public boolean isValidSequence(TreeNode root, int[] arr) {
        return dfsVisit(root, arr, 0);
    }

    public boolean dfsVisit(TreeNode node, int[] arr, int index) {
        if (node == null) {
            return false;
        }

        if (node.val == arr[index]) {
            if (index == arr.length - 1) {
                return node.left == null && node.right == null;
            }

            if (dfsVisit(node.left, arr, index + 1)) {
                return true;
            } else if (dfsVisit(node.right, arr, index + 1)) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
}