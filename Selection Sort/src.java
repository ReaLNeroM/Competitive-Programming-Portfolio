import java.util.Scanner;

public class src {
	public static void main(String[] args){
		Scanner read = new Scanner(System.in);

		int n = read.nextInt();
		int[] array = new int[n];

		for(int i = 0; i < n; i++){
			array[i] = read.nextInt();
		}

		for(int i = 0; i < n; i++){
			int bestPos = 0;
			for(int j = 0; j < n - i; j++){
				if(array[bestPos] < array[j]){
					bestPos = j;
				}
			}

			int temp = array[n - i - 1];
			array[n - i - 1] = array[bestPos];
			array[bestPos] = temp;
		}

		for(int i = 0; i < n; i++){
			System.out.print(array[i] + " ");
		}
	}
}