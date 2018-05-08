import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int y, x;
		y = s.nextInt();
		x = s.nextInt();

		char[][] mat = new char[y][x];
		mat[0] = s.nextLine().toCharArray();

		for(int i = 0; i < y; i++){
			mat[i] = s.nextLine().toCharArray();
		}

		Boolean possible = true;
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(mat[i][j] == '#'){
					if(i != 0 && mat[i - 1][j] == '#'){

					} else if(i != y - 1 && mat[i + 1][j] == '#'){

					} else if(j != 0 && mat[i][j - 1] == '#'){

					} else if(j != x - 1 && mat[i][j + 1] == '#'){

					} else {
						possible = false;
					}
				}
			}
		}

		if(possible){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}