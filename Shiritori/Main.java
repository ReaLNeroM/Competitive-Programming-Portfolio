import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		Set<String> found = new HashSet<String>();
		String prevWord = sc.nextLine();

		boolean good = true;
		for(int i = 0; i < n; i++){
			String currWord = sc.nextLine();
			if(i != 0 && currWord.charAt(0) != prevWord.charAt(prevWord.length() - 1)){
				good = false;
			}
			if(found.contains(currWord)){
				good = false;
			}
			found.add(currWord);
			prevWord = currWord;
		}

		if(good){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}