class DequeImplByDLL implements Deque{
   private SimpleDoublyLinkedList list;
   private int n; // the number of elements in the deque
   DequeImplByDLL(){
       list = new SimpleDoublyLinkedList();
       n = 0;
    }
  public void insertFront(int key) { 
    list.addFront(key);
    n++;
  }
  public void insertBack(int key) { 
    list.addBack(key); 
    n--;
  }
  public void removeFront(){ list.removeFront(); }
  public void removeBack() { list.removeBack(); }
  public int front() { return list.front(); }
  public int back() { return list.back(); }
  public int size() { return n; }
  public boolean empty() { return list.front() == list.back(); }
}