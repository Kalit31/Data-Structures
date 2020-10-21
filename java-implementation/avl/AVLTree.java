package avl;

import node.BinaryNode;

import java.util.LinkedList;
import java.util.Queue;

public class AVLTree {
    BinaryNode root;

    public BinaryNode getRoot() {
        return root;
    }

    public AVLTree(){
        root = null;
    }

    public void levelOrderTraversal() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        System.out.println("Printing Level order traversal of AVL Tree...");
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
        System.out.println();
    }

    public void insert(int value){
        root = insert(root,value);
    }

    public BinaryNode insert(BinaryNode currentNode, int value){
        if(currentNode==null){
            System.out.println("Successfully inserted " + value + " in AVL Tree");
            return createNewNode(value);
        }else if(value <= currentNode.getValue()){
            currentNode.setLeft(insert(currentNode.getLeft(),value));
        }else{
            currentNode.setRight(insert(currentNode.getRight(),value));
        }

        int balance = checkBalance(currentNode.getLeft(),currentNode.getRight());
        if(balance>1){
            if(checkBalance(currentNode.getLeft().getLeft(),currentNode.getLeft().getRight())>0){
                currentNode = rightRotate(currentNode);
            }else{
                currentNode.setLeft(leftRotate(currentNode.getLeft()));
                currentNode = rightRotate(currentNode);
            }
        }else if(balance<-1){
            if(checkBalance(currentNode.getRight().getRight(),currentNode.getRight().getLeft())>0){
                currentNode = leftRotate(currentNode);
            }else{
                currentNode.setRight(rightRotate(currentNode.getRight()));
                currentNode = leftRotate(currentNode);
            }
        }

        if(currentNode.getLeft() != null){
            currentNode.getLeft().setHeight(calculateHeight(currentNode.getLeft()));
        }
        if(currentNode.getRight()!=null){
            currentNode.getRight().setHeight(calculateHeight(currentNode.getRight()));
        }
        currentNode.setHeight(calculateHeight(currentNode));
        return currentNode;
    }

    public int checkBalance(BinaryNode rootLeft,BinaryNode rootRight){
        if(rootLeft==null && rootRight == null)
            return 0;
        else if(rootLeft==null){
            return -1*(rootRight.getHeight()+1);
        }else if(rootRight == null){
            return (rootLeft.getHeight() + 1);
        }else{
            return rootLeft.getHeight()-rootRight.getHeight();
        }
    }

    public BinaryNode rightRotate(BinaryNode currentNode){
        BinaryNode newRoot = currentNode.getLeft();
        currentNode.setLeft(currentNode.getLeft().getRight());
        newRoot.setRight(currentNode);
        currentNode.setHeight(calculateHeight(currentNode));
        newRoot.setHeight(calculateHeight(newRoot));
        return newRoot;
    }

    public BinaryNode leftRotate(BinaryNode currentNode){
        BinaryNode newRoot= currentNode.getRight();
        currentNode.setRight(currentNode.getRight().getLeft());
        newRoot.setLeft(currentNode);
        currentNode.setHeight(calculateHeight(currentNode));
        newRoot.setHeight(calculateHeight(newRoot));
        return newRoot;
    }

    public int calculateHeight(BinaryNode node){
        if(node == null){
            return 0;
        }
        return 1+ Math.max((node.getLeft() != null ? node.getLeft().getHeight():-1),
                (node.getRight()!=null? node.getRight().getHeight():-1));
    }

    public BinaryNode createNewNode(int value){
        BinaryNode node = new BinaryNode();
        node.setValue(value);
        node.setHeight(0);
        return node;
    }

    public BinaryNode getMinimumElement(BinaryNode root){
        if(root.getLeft() == null){
            return root;
        }else{
           return getMinimumElement(root.getLeft());
        }
    }

    public void deleteNodeOfBST(int value) {
        System.out.println("Deleting " + value + " from AVL Tree ...");
        root = deleteNode(root, value);
    }


    public BinaryNode deleteNode(BinaryNode currentNode, int value){
        if(currentNode == null){
            return null;
        }
        if(value<currentNode.getValue()){
            currentNode.setLeft(deleteNode(currentNode.getLeft(),value));
        }else if(value > currentNode.getValue()){
            currentNode.setRight(deleteNode(currentNode.getRight(),value));
        }else{
            if(currentNode.getLeft()!=null && currentNode.getRight()!=null){
                BinaryNode temp = currentNode;
                BinaryNode min = getMinimumElement(currentNode.getRight());
                currentNode.setValue(min.getValue());
                deleteNode(currentNode.getRight(),min.getValue());
            }else if(currentNode.getLeft()!=null){
                currentNode = currentNode.getLeft();
            }else if(currentNode.getRight()!=null){
                currentNode = currentNode.getRight();
            }else{
                currentNode = null;
                return  currentNode;
            }
        }

        int balance = checkBalance(currentNode.getLeft(),currentNode.getRight());
        if(balance>1){
            if(checkBalance(currentNode.getLeft().getLeft(),currentNode.getLeft().getRight())>0){
                currentNode = rightRotate(currentNode);
            }else{
                currentNode.setLeft(leftRotate(currentNode.getLeft()));
                currentNode = rightRotate(currentNode);
            }
        }else if(balance<-1){
            if(checkBalance(currentNode.getRight().getRight(),currentNode.getRight().getLeft())>0){
                currentNode = leftRotate(currentNode);
            }else{
                currentNode.setRight(rightRotate(currentNode.getRight()));
                currentNode = leftRotate(currentNode);
            }
        }
        if(currentNode.getLeft() != null){
            currentNode.getLeft().setHeight(calculateHeight(currentNode.getLeft()));
        }
        if(currentNode.getRight()!=null){
            currentNode.getRight().setHeight(calculateHeight(currentNode.getRight()));
        }
        currentNode.setHeight(calculateHeight(currentNode));
        return currentNode;
    }


}
