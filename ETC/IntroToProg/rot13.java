import java.util.*;

public class rot13 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (input.hasNextLine()) {
			String text = input.nextLine();
			Crypt(text);
		}
	}

	static void Crypt(String text) {
		StringBuilder msg = new StringBuilder();
		char[] chr = text.toCharArray();
		int shift = 13;
		for (int i = 0; i < chr.length; ++i) {

			if (Character.isLetter(chr[i])) {
				char newchar = (char) (chr[i] + shift);

				if (Character.isUpperCase(chr[i])) {
					if (newchar > 'Z') {
						newchar = (char) (chr[i] - (26 - shift));
					}
				} else {
					if (newchar > 'z') {
						newchar = (char) (chr[i] - (26 - shift));
					}
				}
				msg.append(newchar);
			} else {
				msg.append(chr[i]);
			}

		}
		System.out.println(msg);

	}

}
