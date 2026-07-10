public class Test {
    void f(int[] a) {
        for (int i = 0; i <= a.length; i++)
            try {
                a[i] = 20 / a[i];
            } catch (ArrayIndexOutOfBoundsException ex) {
                System.out.println("Array error");
                throw new InternalError();
            } catch (ArithmeticException ex) {
                System.out.println("Arithmetic error");
            } catch (NullPointerException ex) { 
                System.out.println("Null ptr");
            } finally {
                System.out.println("I am in the finally clause");
            }
        System.out.println("After try block");
    }

    public static void main(String[] args) {
        Test exp = new Test();
        int[] x = {2, 0, 5};
        try {
            exp.f(x);
        } catch (InternalError ex) {
            System.out.println("Internal Error");
        }
    }
}