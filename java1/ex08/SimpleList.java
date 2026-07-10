class SimpleList implements Aggregate{
    private SimpleNode nil;

    private int flag = 0;

    SimpleList() { init(); }

    void init() {
        nil = new SimpleNode();
        nil.setNext(nil);
        nil.setPrev(nil);
    }


    SimpleNode listSearch(int key){
        for (SimpleNode node = nil.getNext(); node != nil; node = node.getNext()) {
            if(node.value == key){ return node; }
        }
        return null;
    }

    void printList(){
        if( flag == 0 ){
            System.out.println();
            flag = 1;
        }
        for (SimpleNode node = nil.getNext(); node != nil; node = node.getNext()) {
            System.out.print(node.value + " ");
        }
        System.out.println();
    }

    void delete(int key){
        SimpleNode delnode = listSearch(key);
        if (delnode == null) return;
        delnode.getNext().setPrev(delnode.getPrev());
        delnode.getPrev().setNext(delnode.getNext());
    }

    void insert(int key){
        SimpleNode newnode = new SimpleNode();
        newnode.value = key;
        newnode.setNext(nil.getNext());
        nil.getNext().setPrev(newnode);
        nil.setNext(newnode);
        newnode.setPrev(nil);
        
        if(nil.getPrev() == nil){
            nil.setPrev(newnode);
        }
    }

    SimpleNode getNil(){ return nil;}

    public Iterator forwardIterator(){
	    return new SimpleListForwardIterator(this);
    }

    public Iterator backwardIterator(){
        return new SimpleListBackwardIterator(this);
    }
}
