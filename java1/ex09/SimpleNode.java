class SimpleNode{
    int value;
    SimpleNode next;
    SimpleNode prev;

    void setNext(SimpleNode node){ next = node; }
    void setPrev(SimpleNode node){ prev = node; }
    void setKey(int key){ value = key; }
    SimpleNode getNext(){ return next; }
    SimpleNode getPrev(){ return prev; }
    int getKey(){ return value; }
}
