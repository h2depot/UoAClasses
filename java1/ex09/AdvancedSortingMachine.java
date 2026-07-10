class AdvancedSortingMachine extends SortingMachine{
    public AdvancedSortingMachine(Strategy strategy){
	super(strategy);
    }
    
    public void sort(int[] data){
        long start, end;

	start = System.currentTimeMillis();
	super.sort(data);
	end = System.currentTimeMillis();

	System.out.println("time: "+  (end - start));
    }
}
