import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	static Boolean prime(int x){
		for(int i = 2; i * i <= x; i++){
			if(x % i == 0){
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);

		int n = s.nextInt();

		int[] result = new int[n];

		int added = 0;

		for(int i = 11; added < n; i += 10){
			if(prime(i)){
				result[added] = i;
				added++;
			}
		}

		for(int i = 0; i < n; i++){
			System.out.print(String.valueOf(result[i]) + ' ');
		}
		System.out.print('\n');
	}
}