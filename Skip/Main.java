import java.util.Scanner;
import java.lang.Math;
public class Main {
	public static int gcd(int a, int b){
		if(a == -1){
			return b;
		}

		while(b != 0){
			int temp = b;
			b = a % b;
			a = temp;
		}

		return a;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n, x;
		n = sc.nextInt();
		x = sc.nextInt();

		int[] cities = new int[n];
		int res = -1;

		for(int i = 0; i < n; i++){
			cities[i] = sc.nextInt();
			res = gcd(res, Math.abs(cities[i] - x));
		}

		System.out.println(res);
	}
}