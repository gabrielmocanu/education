import java.util.*;

public class Duplicate{

  public static void main(String[] args) {

      SimpleLinkedList list = new SimpleLinkedList();
      list.appendList(2);
      list.appendList(3);
      list.appendList(4);
      list.appendList(5);
      list.appendList(3);
      list.appendList(4);
      list.appendList(8);
      list.appendList(9);
      list.printNodes();
      deleteDuplication(list);
      list.printNodes();
  }

  public static void deleteDuplication(SimpleLinkedList list)
  {
      Node first;
      Node second;
      first = list.head;
      second = list.head;

      while(first.next != null )
      {
          second = first;
          while(second.next != null)
          {
            if(first.data == second.next.data)
            {
                second.next = second.next.next;
            }
            second = second.next;
          }
          first = first.next;
      }
  }

}
