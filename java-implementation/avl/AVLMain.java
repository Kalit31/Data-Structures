package avl;

public class AVLMain {
    public static void main(String[] args) {
        AVLTree tree = new AVLTree();

        tree.insert(30);
        tree.levelOrderTraversal();
        tree.insert(10);
        tree.levelOrderTraversal();
        tree.insert(5);
        tree.levelOrderTraversal();
        tree.insert(3);
        tree.levelOrderTraversal();
        tree.insert(4);
        tree.levelOrderTraversal();
        tree.insert(50);
        tree.levelOrderTraversal();
        tree.insert(65);
        tree.levelOrderTraversal();
        tree.insert(1);
        tree.levelOrderTraversal();

        tree.deleteNodeOfBST(5);//LL Condition
        tree.levelOrderTraversal();
        tree.insert(2);
        tree.levelOrderTraversal();
        tree.deleteNodeOfBST(4);//LR Condition
        tree.levelOrderTraversal();
        tree.insert(20);
        tree.levelOrderTraversal();
        tree.deleteNodeOfBST(65);//RR Condition
        tree.levelOrderTraversal();
        tree.insert(40);
        tree.levelOrderTraversal();
        tree.deleteNodeOfBST(20);//RL Condition
        tree.levelOrderTraversal();
    }

}
