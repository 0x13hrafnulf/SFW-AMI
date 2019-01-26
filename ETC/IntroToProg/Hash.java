import java.util.*;

public class Hash {
	static String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char[] count = alphabet.toCharArray();

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();

		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String tst = input.nextLine();
			String[] cases = new String[Integer.parseInt(tst)];
			for (int j = 0; j < Integer.parseInt(tst); ++j) {
				cases[j] = input.nextLine();
			}
			Hash(Integer.parseInt(tst), cases);
		}

	}

	static void Hash(int tst, String[] cases) {
		int result = 0;
		for (int i = 0; i < tst; ++i) {
			char[] chr = cases[i].toCharArray();
			for (int j = 0; j < chr.length; ++j) {
				for (int k = 0; k < count.length; ++k){
					if(chr[j] == count[k]){
						result += (k+j+i);
					}
				}
			}
		}
		System.out.println(result);

	}

}
