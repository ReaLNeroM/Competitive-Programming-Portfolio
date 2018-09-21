import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int y, x;
		y = sc.nextInt();
		x = sc.nextInt();

		System.out.println(x * (y - 1) + x - 1);

		for(int i = 1; i <= y - 1; i++){
			for(int j = 1; j <= x; j++){
				System.out.println(Integer.toString(i) + " " + Integer.toString(j) + " " + Integer.toString(i + 1) + " " + Integer.toString(j));
			}
		}
		for(int i = 1; i <= x - 1; i++){
			System.out.println(Integer.toString(y) + " " + Integer.toString(i) + " " + Integer.toString(y) + " " + Integer.toString(i + 1));
		}
	}
}