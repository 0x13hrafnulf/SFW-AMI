import java.util.*;

public class dance_sent {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine()) {
			String text = input.nextLine();
			Dancing(text);
		}
	}

	private static void Dancing(String text) {
		char[] chr = text.toCharArray();
		StringBuilder res = new StringBuilder();
		int count = 0;
		for (int i = 0; i < chr.length; ++i) {
			if (Character.isLetter(chr[i])) {
				++count;
				if (count % 2 != 0) {
					res.append(Character.toUpperCase(chr[i]));
				} else {
					res.append(Character.toLowerCase(chr[i]));
				}
			} else {
				res.append(chr[i]);
			}
		}
		System.out.println(res);
	}
}
