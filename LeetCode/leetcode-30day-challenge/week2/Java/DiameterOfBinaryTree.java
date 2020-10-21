class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution1 {

    public int height(TreeNode root) {
        if (root == null)
            return 0;

        int lh = height(root.left);
        int rh = height(root.right);

        return 1 + Math.max(lh, rh);
    }

    public int calculateDiameter(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int op1 = height(root.left) + height(root.right) + 1;
        int op2 = calculateDiameter(root.left);
        int op3 = calculateDiameter(root.right);
        return Math.max(op1, Math.max(op2, op3));
    }

    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return calculateDiameter(root) - 1;
    }
}

class Solution2 {
    int ans;

    public int diameterOfBinaryTree(TreeNode root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }

    public int depth(TreeNode node) {
        if (node == null)
            return 0;
        int L = depth(node.left);
        int R = depth(node.right);
        ans = Math.max(ans, L + R + 1);
        return Math.max(L, R) + 1;
    }
}
/**
 * Approach #1: Depth-First Search [Accepted] Intuition
 * 
 * Any path can be written as two arrows (in different directions) from some
 * node, where an arrow is a path that starts at some node and only travels down
 * to child nodes.
 * 
 * If we knew the maximum length arrows L, R for each child, then the best path
 * touches L + R + 1 nodes.
 * 
 * Algorithm
 * 
 * Let's calculate the depth of a node in the usual way: max(depth of node.left,
 * depth of node.right) + 1. While we do, a path "through" this node uses 1 +
 * (depth of node.left) + (depth of node.right) nodes. Let's search each node
 * and remember the highest number of nodes used in some path. The desired
 * length is 1 minus this number.
 * 
 * Complexity Analysis
 * 
 * Time Complexity: O(N). We visit every node once.
 * 
 * Space Complexity: O(N), the size of our implicit call stack during our
 * depth-first search.
 */
