package binaryTree;

import node.BinaryNode;
import queue.QueueLinkedList;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinaryTreeLinkedList {

    BinaryNode root;

    public BinaryTreeLinkedList() {
        this.root = null;
    }


    // Traversals

    public void preOrder(BinaryNode node){
        if(node == null)
            return;
        System.out.println(node.getValue()+" ");
        preOrder(node.getLeft());
        preOrder(node.getRight());
    }

    public void inOrder(BinaryNode node){
        if(node == null)
            return;
        inOrder(node.getLeft());
        System.out.println(node.getValue()+" ");
        inOrder(node.getRight());
    }

    public void postOrder(BinaryNode node){
        if(node == null)
            return;
        postOrder(node.getLeft());
        postOrder(node.getRight());
        System.out.println(node.getValue()+" ");
    }

    public void levelOrder(){
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            BinaryNode presentNode = queue.remove();
            System.out.println(presentNode);
            if(presentNode.getLeft()!=null)
                queue.add(presentNode.getLeft());
            if(presentNode.getRight()!=null)
                queue.add(presentNode.getRight());
        }

    }

    public void search(int value){
        if(root == null) {
            System.out.println("Value not found");
            return;
        }
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while(!queue.isEmpty()){
              BinaryNode presentNode = queue.remove();
              if(presentNode.getValue() == value){
                  System.out.println("Value found: "+value);
                  return;
              }
            if(presentNode.getLeft()!=null)
                queue.add(presentNode.getLeft());
            if(presentNode.getRight()!=null)
                queue.add(presentNode.getRight());
        }
        System.out.println("Value not found: "+value);
    }

    public void insert(int value){
        BinaryNode node = new BinaryNode();
        node.setValue(value);
        if(root == null){
            root = node;
            System.out.println("Successfully inserted new node at Root !");
            return;
        }
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            BinaryNode presentNode = queue.remove();
            if(presentNode.getLeft()==null){
                presentNode.setLeft(node);
                System.out.println("Successfully inserted new node !");
                return;
            }else if(presentNode.getRight() == null){
                presentNode.setRight(node);
                System.out.println("Successfully inserted new node !");
                return;
            }else{
                queue.add(presentNode.getLeft());
                queue.add(presentNode.getRight());
            }
        }
    }

    public void deleteNode(int value){
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            BinaryNode presentNode = queue.remove();
            if(presentNode.getValue() == value){
                BinaryNode deepestNode = getDeepestNode();
                presentNode.setValue(deepestNode.getValue());
                deleteDeepestNode();
                System.out.println("Deleted the node !!");
                return;
            }
            if (presentNode.getLeft() != null)
                queue.add(presentNode.getLeft());
            if (presentNode.getRight() != null)
                queue.add(presentNode.getRight());
        }
        System.out.println("Node not found!");
    }

    public void deleteDeepestNode(){
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        BinaryNode previousNode,presentNode=null;
        while(!queue.isEmpty()){
            previousNode = presentNode;
            presentNode = queue.remove();
            if(presentNode.getLeft()==null){
                previousNode.setRight(null);
                return;
            }else if(presentNode.getRight() == null){
                presentNode.setLeft(null);
                return;
            }
            queue.add(presentNode.getLeft());
            queue.add(presentNode.getRight());
        }
    }

    public BinaryNode getDeepestNode(){
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        BinaryNode presentNode = null;
        while(!queue.isEmpty()){
            presentNode = queue.remove();
            if(presentNode.getLeft()!=null)
                queue.add(presentNode.getLeft());
            if(presentNode.getRight()!=null)
                queue.add(presentNode.getRight());
        }
        return presentNode;
    }

    void deleteTree(){
        root = null;
        System.out.println("Binary Tree has been deleted successfully");
    }

}
