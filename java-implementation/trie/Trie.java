package trie;

import java.util.HashMap;
import java.util.Map;

public class Trie {

    public Trie() {
        root = new TrieNode();
    }

    public class TrieNode{
            Map<Character,TrieNode> children;
            boolean endOfWord;
            public TrieNode() {
                children = new HashMap<>();
                endOfWord = false;
            }
        }

    public final TrieNode root;

    public void insert(String word){
        TrieNode currentNode = root;
        for(int i =0;i<word.length();i++){
            char ch = word.charAt(i);
            TrieNode node = currentNode.children.get(ch);
            if(node == null){
                node = new TrieNode();
                currentNode.children.put(ch,node);
            }
            currentNode = node;
        }
        currentNode.endOfWord = true;
        System.out.println("Successfully inserted " + word + " in Trie !");
    }

    public boolean search(String word){
        TrieNode currentNode = root;
        for(int i =0;i<word.length();i++){
            char ch = word.charAt(i);
            TrieNode node = currentNode.children.get(ch);
            if(node == null){
                System.out.println("Word: " + word + " does not exists in Trie !");
                return false;
            }
            currentNode = node;
        }
        if(currentNode.endOfWord){
            System.out.println("Word: " + word + " exists in Trie !");
        }else{
            System.out.println("Word: " + word + " does not exists in Trie ! But this is a Prefix of another Word !");
        }
        return currentNode.endOfWord;
    }

    public void delete(String word){
        if (search(word)) {
            delete(root, word, 0);
        }
    }

    public boolean delete(TrieNode parentNode, String word, int index) {char ch = word.charAt(index);
        TrieNode currentNode = parentNode.children.get(ch);

        boolean canThisNodeBeDeleted;

        if (currentNode.children.size() > 1) {
            System.out.println("Entering Case#1");
            delete(currentNode, word, index + 1); // CASE#1
            return false;
        }

        if (index == word.length() - 1) { // CASE#2
            System.out.println("Entering Case#2");
            if (currentNode.children.size() >= 1) {
                currentNode.endOfWord = false;//updating endOfWord will signify that this word is not there in Trie
                return false;
            } else {
                System.out.println("Character " + ch + " has no dependency, hence deleting it from last");
                parentNode.children.remove(ch);
                return true;// If this word is not a prefix of some other word, and since this is last
                // character, we should
                // return true, indicating we are ok to delete this node
            }
        }


        if (currentNode.endOfWord) { // CASE#3
            System.out.println("Entering Case#3");
            delete(currentNode, word, index + 1);
            return false;
        }


        System.out.println("Entering Case#1");
        canThisNodeBeDeleted = delete(currentNode, word, index + 1); // CASE#4
        if (canThisNodeBeDeleted) {
            System.out.println("Character " + ch + " has no dependency, hence deleting it");
            parentNode.children.remove(ch);
            return true; // Current node can also be deleted
        } else {
            return false; // Someone is dependent on this node, hence dont delete it
        }
    }

}
