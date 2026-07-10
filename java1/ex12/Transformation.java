import java.util.Scanner;

class Transformation{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    String str = sc.next();
    int n = sc.nextInt();
    
    for(int i = 0; i < n; i++){
        String order = sc.next();

        if(order.equals("print")){
          int pr_s = sc.nextInt();
          int pr_e = sc.nextInt();
        
          System.out.println(str.substring(pr_s, pr_e + 1));
        } else if(order.equals("reverse")){
           int rev_s = sc.nextInt();
           int rev_e = sc.nextInt();         
           StringBuilder tmp_str = new StringBuilder(str);
           StringBuilder rev = new StringBuilder(str.substring(rev_s, rev_e + 1));
           rev.reverse();
           tmp_str.replace(rev_s, rev_e + 1, rev.toString()); 
           str = tmp_str.toString();
           //System.out.println(str);
        } else if(order.equals("replace")){
            int rep_s = sc.nextInt();
            int rep_e = sc.nextInt();
            String rep = sc.next();
            StringBuilder tmp_str = new StringBuilder(str);
            tmp_str.replace(rep_s,rep_e + 1,rep);
            str = tmp_str.toString();
            //System.out.println(str);
        }
    }
  }
}