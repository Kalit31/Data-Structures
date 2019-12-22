package binarySearchTree;

import node.BinaryNode;

import java.util.LinkedList;
import java.util.Queue;

public class BinarySearchTree {
    BinaryNode root;

    public BinaryNode getRoot() {
        return root;
    }

    public BinarySearchTree() {
        root = null;
    }

    public void insert(int value){
        root = insert(root,value);
    }

    public BinaryNode insert(BinaryNode currentNode,int value){
        if (currentNode == null) {
            System.out.println("Successfully inserted " + value + " in BST");
            return createNewNode(value);
        } else if (value <= currentNode.getValue()) {
            currentNode.setLeft(insert(currentNode.getLeft(), value));
            return currentNode;
        } else {
            currentNode.setRight(insert(currentNode.getRight(), value));
            return currentNode;
        }
    }

    public BinaryNode createNewNode(int value) {
        BinaryNode node = new BinaryNode();
        node.setValue(value);
        return node;
    }

    public void searchForValue(int value) {
        searchForValue(root, value);
    }

    public BinaryNode searchForValue(BinaryNode node, int value) {
        if (node == null) {
            System.out.println("Value: " + value + " not found in BST.");
            return null;
        } else if (node.getValue() == value) {
            System.out.println("Value: " + value + " found in BST.");
            return node;
        } else if (value < node.getValue()) {
            return searchForValue(node.getLeft(), value);
        } else {
            return searchForValue(node.getRight(), value);
        }
    }

    public static BinaryNode minimumElement(BinaryNode root) {
        if (root.getLeft() == null)
            return root;
        else {
            return minimumElement(root.getLeft());
        }
    }

    public void levelOrderTraversal() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        System.out.println("\nPrinting Level order traversal of Tree...");
        if (root == null) {
            System.out.println("Tree does not exists !");
            return;
        }
        while (!queue.isEmpty()) {
            BinaryNode presentNode = queue.remove();
            System.out.print(presentNode.getValue() + " ");
            if (presentNode.getLeft() != null)
                queue.add(presentNode.getLeft());
            if (presentNode.getRight() != null)
                queue.add(presentNode.getRight());
        }
    }

    public void deleteNodeOfBST(int value) {
        System.out.println("\n\nDeleting " + value + " from BST...");
        deleteNodeOfBST(root,value);
    }

    public BinaryNode deleteNodeOfBST(BinaryNode root, int value) {
        if (root == null) {
            System.out.println("Value not found in BST");
            return null;
        }
        if (value < root.getValue()) {
            root.setLeft(deleteNodeOfBST(root.getLeft(), value));
        } else if (value > root.getValue()) {
            root.setRight(deleteNodeOfBST(root.getRight(), value));
        } else {
            if (root.getLeft() != null && root.getRight() != null) {
                BinaryNode temp = root;
                BinaryNode minNodeForRight = minimumElement(temp.getRight());
                root.setValue(minNodeForRight.getValue());
                root.setRight(deleteNodeOfBST(root.getRight(), minNodeForRight.getValue()));
            } else if (root.getLeft() != null) {
                root = root.getLeft();
            } else if (root.getRight() != null) {
                root = root.getRight();
            } else
                root = null;
        }
        return root;
    }


    public void deleteTree() {
        System.out.println("Deleting entire Tree...");
        root = null;
        System.out.println("Tree deleted successfully !");
    }

}
