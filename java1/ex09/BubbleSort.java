class BubbleSort implements Strategy{
    public void sort( int[] data ){
        for ( int i = 0; i < data.length - 1; i++){
            for ( int j = 1; j < data.length - i; j++){
                if ( data[j] < data[j-1] ){
                    int tmp = data[j];
		    data[j] = data[j-1];
		    data[j-1] = tmp;
		}
	    }
	}
    }
}
