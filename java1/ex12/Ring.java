import java.util.Scanner;

class Ring{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

	String ring = sc.next();
	String p = sc.next();

	search:
	for(int i = 0; i < ring.length(); i++){
            if(p.charAt(0) == ring.charAt(i)){
		for(int j = 0; j < p.length(); j++){
		    if(p.charAt(j) != ring.charAt((i+j)%ring.length())){
			continue search;
		    }
		}
		System.out.println("Yes");
	        return;
	    }
	}
	System.out.println("No");
    }
}
