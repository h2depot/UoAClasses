class SelectionSort implements Strategy{
    public void sort( int[] data ){
        for ( int i = 0; i < data.length; i++ ) {
	    int min = i;
	    for ( int j = i+1; j < data.length; j++) {
		if ( data[j] < data[min]) min = j;
	    }
	    int tmp = data[i];
	    data[i] = data[min];
	    data[min] = tmp;
	}
    }
}
