import java.util.*;
import java.io.*;

class Node {
	int val;
	Node left;
	Node right;	

	public Node(int val) {
		this.val = val;
		left = null;
		right = null;
	}
};

public class BinarySearchTree {

	public static Node root;

	public BinarySearchTree(){
		this.root = null;
	}
	
	public void insert(int val){
		
		Node newNode = new Node(val);
		if(root==null) {
			root = newNode;
			return;
		}
		
		Node ptr = root;
		Node parent = null;
		
		while(true) {
			parent = ptr;
			if(val<ptr.val) {				
				ptr = ptr.left;
				if(ptr==null) {
					parent.left = newNode;
					return;
				}
			}
			
			else {
				ptr = ptr.right;
				if(ptr==null) {
					parent.right = newNode;
					return;
				}
			}
		}
	}
	
	public void delete(int val) {
		Node parent = root;
		Node ptr = root;
		
		while(ptr.val != val) {
			parent = ptr;
			if(val < ptr.val) {
				ptr = ptr.left;
			}
			
			else {
				ptr = ptr.right;
			}
			
			if(ptr==null) {
				return;
			}
		}
		
		//case 1: node has no children
		if(ptr.left==null && ptr.right==null) {
			if(ptr==root) {
				root = null;
			}
			
			else if(parent.left.val == val) {
				parent.left = null;
			}
			
			else {
				parent.right = null;
			}
		}
		
		//case 2: node has one child
		
		//subcase1: node is the left child
		else if(ptr.right==null) {
			if(ptr==root) {
				root = ptr.left;
			}
			
			else if(parent.left.val == val) {
				parent.left = ptr.left;
			}
			
			else {
				parent.right = ptr.left;
			}
		}
		
		//subcase2: node is the right child
		else if(ptr.left==null) {
			if(ptr==root) {
				root = ptr.left;
			}
			
			else if(parent.left.val == val) {
				parent.left = ptr.right;
			}
			
			else {
				parent.right = ptr.right;
			}
		}
		
		else if(ptr.left!=null && ptr.right!=null) {
			Node inorderSuccessor = ptr.right;
			Node parentInorderSuccessor = null;
			while(inorderSuccessor.left!=null) {
				parentInorderSuccessor = inorderSuccessor;
				inorderSuccessor = inorderSuccessor.left;
			}
			
			parentInorderSuccessor.left = inorderSuccessor.right;
			
			if(ptr == root) {
				root.val = inorderSuccessor.val;
				inorderSuccessor.left = root.left;
				inorderSuccessor.right = root.right;
			}
			else {
				ptr.val = inorderSuccessor.val;
				inorderSuccessor.left = ptr.left;
				inorderSuccessor.right = ptr.right;
			}
		}
	}
	
	
	
	public void display(Node root) {
		if(root!=null) {
			display(root.left);
			System.out.print(" --> " + root.val);
			display(root.right);
		}
	}
	
	public Node constructTreeFromPreorder(int preorder[], int size) {
		Node root = new Node(preorder[0]);
		Stack<Node> stack = new Stack<Node>();
		
		stack.push(root);
		
		for(int i=1;i<size;++i) {
			Node temp = null;
			while(!stack.isEmpty() && preorder[i] > stack.peek().val) {
				temp = stack.pop();
			}
			
			if(temp!=null) {
				temp.right = new Node(preorder[i]);
				stack.push(temp.right);
			}
			
			else {
				temp = stack.peek();
				temp.left = new Node(preorder[i]);
				stack.push(temp.left);
			}
		}
		
		return root;
	
	}
	
	
	public static void main(String[] args) {
		BinarySearchTree bst = new BinarySearchTree();
		
		bst.insert(3);
		bst.insert(8);
		bst.insert(1);
		bst.insert(4);
		bst.insert(6);
		bst.insert(2);
		bst.insert(10);
		bst.insert(9);
		bst.insert(20);
		bst.insert(25);
		bst.insert(15);
		bst.insert(16);
		
		bst.display(bst.root);	
		System.out.println("");
		
		bst.delete(3);
		
		bst.display(bst.root);
		
		System.out.print("Root: " + bst.root.val);
		bst.delete(4);
		System.out.print("Root: " + bst.root.val);
		
		bst.display(bst.root);
		
		int preorderArray[] = new int[]{10,5,1,7,40,50};
		int size = preorderArray.length;
		
		Node newRoot = bst.constructTreeFromPreorder(preorderArray, size);
		
		bst.display(newRoot);
		
		//Node temp = bst.search(9);
		//if(temp == null) System.out.print("Node not found!");
		//else System.out.print(temp.val);
		
	}
};


