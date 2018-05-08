import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();

		int k = s.nextInt();

		int coefficient = (int) Math.pow(2, k);

		if(a >= b && a >= c){
			a *= coefficient;
		} else if (a <= b && b >= c){
			b *= coefficient;
		} else if (a <= c && b <= c){
			c *= coefficient;
		}

		System.out.println(a + b + c);
	}
}