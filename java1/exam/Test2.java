import java.io.*;
import java.util.*;

public class Test2 {
    public static void main(String args[]) {
        int a[] = {347, 975, -9000};

        for (String s : args) 
            try {
                int i = Integer.parseInt(s);
                System.out.println("Access element " + i + " " + a[i]);
                System.out.println("a[0]=" + a[0]);
            } catch (NumberFormatException e) {
                System.out.println("Number format error");
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Array index error");
            } finally {
                System.out.println("The finally statement is executed");
            }
            System.out.println("Out of the try block");
    }
}