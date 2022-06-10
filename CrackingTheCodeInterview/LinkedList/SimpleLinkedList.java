import java.util.*;

public class SimpleLinkedList{

	Node head;

	void appendList(int d)
	{
		Node newNode = new Node(d);

		if(head == null)
		{
			head = new Node(d);
			return ;
		}

		Node n = head;
		while(n.next != null)
			n = n.next;

		n.next = newNode;
		return;
	}

	void push(int d)
	{
		Node newNode = new Node(d);
		if(head == null)
		{
			head = new Node(d);
			return ;
		}

		newNode.next = head;
		head = newNode;

	}

	public void insertAtPos(int d, int pos)
	{
		Node newNode = new Node(d);
		Node n = head;
		if(pos == 1)
			push(d);

		for(int i = 1; i < pos - 1; i++)
			n = n.next;

		newNode.next = n.next;
		n.next = newNode;

	}

	void printNodes()
	{
		Node n = head;
		while(n != null)
		{
			System.out.print(n.data + " ");
			n = n.next;
		}
		System.out.println();
	}

//	public static void main(String [] args)
//	{

//		SimpleLinkedList list = new SimpleLinkedList();
//		list.appendList(10);
//		list.appendList(5);
//		list.appendList(3);
//		list.push(1);
//		list.insertAtPos(12,2);
//		list.printNodes();

//	}
}
