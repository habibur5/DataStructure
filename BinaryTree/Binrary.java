import java.util.LinkedList;
import java.util.Queue;

public class Binrary{
    static class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static class BinraryTree{
        static int idx = -1;
        public static Node buildTree(int nodes[]){
            idx++;
            if(nodes[idx] == -1){
                return null;
            }
            Node newNode = new Node(nodes[idx]);
            newNode.left = buildTree(nodes);
            newNode.right = buildTree(nodes);
            return newNode;
        }
    }

    public static void preorderTraversal(Node root){

        if(root == null) return;
        System.out.print(root.data+ " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }
    
    public static void inorderTraversal(Node root){
        if( root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data+" ");
        inorderTraversal(root.right);
    }

    public static void postorderTraversal(Node root){
        if(root == null) return;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data+" ");
    }
    public static void levelOrderTraversal(Node root){
        if(root == null) return;
        Queue<Node>q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while (!q.isEmpty()) {
            Node currentNode = q.remove();
            if(currentNode == null){
                System.out.println();
                if(q.isEmpty()){
                    break;
                }else{
                    q.add(null);
                }
            }else{
                System.out.print(currentNode.data+" ");
                if(currentNode.left !=null) q.add(currentNode.left);
                if(currentNode.right!=null) q.add(currentNode.right);
            }
        }

    }
    public static int contOfNodes(Node root){
        if(root == null) return 0;
        int leftNodes = contOfNodes(root.left);
        int rightNodes = contOfNodes(root.right);
        return leftNodes+rightNodes+1;
    }
    
    public static int sumOfNodes(Node root){
        if(root == null) return 0;

        int leftNodes = sumOfNodes(root.left);
        int rightNodes = sumOfNodes(root.right);
        return leftNodes+rightNodes+root.data;
    }
    public static int height(Node root){
        if(root== null) return 0;
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        return Math.max(leftHeight, rightHeight)+1;
    }
    // longest path  of tree
    /*!  Approch1( O(n^2)) */

    public static int diameter(Node root){
        if(root == null) return 0;

        int diam1 = diameter(root.left);
        int diam2 = diameter(root.right);
        int diam3 = height(root.left) +height(root.right)+1;
        return Math.max(diam3, Math.max(diam2, diam1));
    }
    // Approch 2

    static class TreeInfo{
        int ht;
        int diam;

        TreeInfo(int ht, int diam){
            this.ht=ht;
            this.diam = diam;
        }
    }
    public static TreeInfo diameter2(Node root){

        if(root == null) return new TreeInfo(0, 0);

        TreeInfo left = diameter2(root.left);
        TreeInfo right = diameter2(root.right);
        int treeHeight = Math.max(left.ht,right.ht)+1;
        int diam1 = left.diam;
        int diam2 = right.diam;
        int diam3 = left.ht + right.ht + 1;
        int diam  = Math.max(diam1,Math.max(diam2, diam3));

        return new TreeInfo(treeHeight, diam);

    } 
    
    public static boolean isIdentical(Node root, Node subroot){
        if(root== null && subroot == null) return true;
        if(root == null || subroot==null) return false;

        if(root.data == subroot.data)
            return isIdentical(root.left, subroot.left) && isIdentical(root.right, subroot.right);
        return false;
    }
    public static boolean isSubtree(Node root, Node subtree){
        if(subtree == null) return true;

        if(root == null) return  false;

        if(root.data == subtree.data){
            if(isIdentical(root, subtree)) return true;
        }
        
        return isSubtree(root.left, subtree) || isSubtree(root.right, subtree);
    
        
    }
    public static void main(String args[]){
        int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
        Node root = BinraryTree.buildTree(nodes);

        /* System.out.println(root.data);
        preorderTraversal(root);
        System.out.println();
        inorderTraversal(root);
        System.out.println();
        postorderTraversal(root);
        System.out.println();
        levelOrderTraversal(root);

        System.out.println();
        System.out.println(contOfNodes(root));
        System.out.println(sumOfNodes(root));
        System.out.println(height(root));
 */
        System.out.println(diameter2(root).diam);
        System.out.println(diameter(root));



    }
}
