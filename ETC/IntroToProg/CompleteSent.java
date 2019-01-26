import java.util.*;

public class CompleteSent {
	static String alphabet = "abcdefghijklmnopqrstuvwxyz";
	static char[] alph = alphabet.toCharArray();

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String msg = input.nextLine();

			if (count(msg) >= 26)
				System.out.println("frase completa");
			else if (count(msg) >= 26 / 2 && count(msg) < 26)
				System.out.println("frase quase completa");
			else if (count(msg) <= 26 / 2)
				System.out.println("frase mal elaborada");
		}

	}

	static int count(String msg) {
		int result = 0;
		int[] count = new int[26];
		for (int i = 0; i < alphabet.length(); ++i) {
			for (int k = 0; k < msg.length(); ++k) {
				if (alph[i] == msg.charAt(k)) {
					++count[i];
				}
			}

		}
		for (int j = 0; j < alphabet.length(); ++j) {
			if (count[j] >= 1) {
				++result;
			}
		}
		return result;
	}

}
