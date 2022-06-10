import java.util.*;

public class Partition{

	public static void main(String [] args)
	{
		SimpleLinkedList list = new SimpleLinkedList();
		list.appendList(3);
		list.appendList(5);
		list.appendList(8);
		list.appendList(5);
		list.appendList(10);
		list.appendList(2);
		list.appendList(1);
		list.printNodes();
		SimpleLinkedList list2 = new SimpleLinkedList();
		list2 = partition(list,5);

		list2.printNodes();

	}

	public static SimpleLinkedList partition(SimpleLinkedList list,int x)
	{
			SimpleLinkedList newList = new SimpleLinkedList();
			Node cur = list.head;
			while(cur != null)
			{
				if(cur.data >= x)
				{
							newList.appendList(cur.data);
				}
				else
				{
						 newList.push(cur.data);
				}
				cur = cur.next;
			}

			return newList;
	}
}
