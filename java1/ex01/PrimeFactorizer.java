import java.util.Scanner;

class PrimeFactorizer{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int F = sc.nextInt();
	int i = 2;

	System.out.print(F + ": ");

	while(F != 1){
	    if(F%i == 0){
		F/=i;
		System.out.print(i + " ");
		continue;
	    }
	    i++;
	}

	System.out.println();
    }
}
