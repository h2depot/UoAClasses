import java.util.Scanner;

class Fahrenheit{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int F = sc.nextInt();
	
	double C = (5.0 / 9)*(F - 32);
	System.out.println(C);
    }
}
