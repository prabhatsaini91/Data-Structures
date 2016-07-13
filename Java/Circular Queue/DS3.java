import java.util.*;
import java.io.*;

class CircularQueue {
	
	private int queue[];
	private int front;
	private int rear;

	CircularQueue(int size) {
		queue = new int[size];
		front = rear = -1;
	}
	
	public void push(int val) {
		if((front==0 && rear==queue.length-1) || (front==rear+1)) {   //queue is full when front is first or front is ahead of rear
			System.out.println("Queue Overflow");
			return;
		}
		
		else {
		
			if(rear==-1) {	//queue is empty completely
				front=rear=0;
			}
			
			else if(rear==queue.length-1) {  //rear is at the last, nothing about front is known
				rear=0;
			}
			
			else {		//normal operation
				++rear;
			}
		}
		
		queue[rear] = val;
	}
	
	public int pop() {
		if(front == -1) {
			System.out.println("Stack Underflow");
			return -1;
			
		}
		
		
		
		else {
			int toReturn = queue[front];	
			
			if(front == rear) {
				front = rear = -1;
			}
			
			else if(front == queue.length-1) {
				front = 0;
			}
			
			else {
				++front;
			}
			
			return toReturn;
		}
		
		
	}
	
	public void display() {
		/*int size = rear > front ? rear - front + 1 : queue.length - front + rear + 1;
		//System.out.println("Size : " + size);
		//System.out.print("front" + front + " - " + queue[front] + " -- " + "rear" + rear + " - " + queue[rear]);
		
		int f = front, r = rear;
		
		while(true) {
			
			System.out.print("-->" + queue[f]);
			f = (f+1) % queue.length;
			
			if(f==front-1) {
				break;
			}
			
		}*/
		
		int i = front;
		
		while(true) {
		
			if(i==rear) {
				System.out.print(queue[i]);
				break;
			}
			
			System.out.print(queue[i] + "-->");
			++i;
			
			
			if(i==queue.length) {
				i=0;
			}				
		}
	}
};

class DS3 {
	public static void main(String[] args) {
	
		Scanner in = new Scanner(System.in);
		int size = in.nextInt();
		CircularQueue newCqueue = new CircularQueue(size);
		
		for(int i=0;i<size;++i) {
			int temp = in.nextInt();
			//System.out.print(temp);
			newCqueue.push(temp);
		}
		
		System.out.println("\n" + newCqueue.pop());
		System.out.println(newCqueue.pop());
		System.out.println(newCqueue.pop());
		//System.out.println(newCqueue.pop());
		//System.out.println(newCqueue.pop());
		
		//newCqueue.push(5);
		newCqueue.push(342);
		newCqueue.push(34234);
		newCqueue.push(2);
		//newCqueue.push(1);
		
		newCqueue.display();
		
	}
};


