import java.util.*;

public class LetterFrequency {
	static String alphabet = "abcdefghijklmnopqrstuvwxyz";
	static char[] alph = alphabet.toCharArray();

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String msg = input.nextLine();
			Frequency(msg);
		}
	}
	static void Frequency(String msg) {
		int[] count = new int[26];
		String ms = msg.toLowerCase();
		for (int i = 0; i < alphabet.length(); ++i) {
			for (int j = 0; j < ms.length(); ++j){
				if(alphabet.charAt(i) == ms.charAt(j)){
					++count[i];
				}
			}
		}
		for(int k = 0; k < 26; ++k){
			if(count[k] == Max(count)) System.out.print(alph[k]);
		}
		System.out.println();
	}
	static int Max(int[] count) {
		int max = count[0];
		for (int i = 1; i < 26; ++i){
			if(count[i] > max){
				max = count[i];
			}
		}
		return max;
	}
}