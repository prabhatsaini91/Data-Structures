import java.util.*;
import java.io.*;

class Stack {
	private int stack[];
	private int tos;
	
	Stack(int size)  {
		stack = new int[size];
		tos = -1;
	}
	
	public void push(int val) {
		if(tos == stack.length - 1) {
			System.out.println("Stack Overflow");
		}
		
		else {
			stack[++tos] = val;
		}
	}
	
	public int pop() {
		if(tos == -1) {
			System.out.println("Stack Underflow");
			return -1;
		}
		
		else {
			return stack[tos--];
			
		}
	}
	
	public void display() {
		for(int i=tos;i>=0;--i) {
			System.out.print(stack[i]+"-->");
		}
	}
};

class DS1 {
	public static void main(String args[]) {
		
		Scanner in = new Scanner(System.in);
		int size = in.nextInt();
		Stack newStack = new Stack(size);
		
		for(int i=0;i<size;++i) {
			int temp = in.nextInt();
			newStack.push(temp);
		}
		
		newStack.display();
		
		System.out.println("\n"+newStack.pop());		
		System.out.println(newStack.pop());
		
		newStack.display();
	}
};

