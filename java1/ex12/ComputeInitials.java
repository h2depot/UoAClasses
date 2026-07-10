class ComputeInitials{
    public static void main(String[] args){
	int len = 0;
        for(String s: args){
	    len += s.length();
	}
	
        char[] initial = new char[len];
        int cnt_in = 0;
	
	for(String s: args){
            for(int i = 0; i < s.length(); i++){
		int c = s.charAt(i);
		if(c >= 65 && c <= 90){
		    initial[cnt_in++] = (char)c;
		}
	    }
	}

	System.out.println(new String(initial, 0, cnt_in));
    }
}
