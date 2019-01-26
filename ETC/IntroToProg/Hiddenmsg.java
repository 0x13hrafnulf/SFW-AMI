import java.util.*;

public class Hiddenmsg {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String msg = input.nextLine();
			Hidden(msg);
		}
	}

	static void Hidden(String msg) {
		char[] chr = msg.toCharArray();
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < chr.length; ++i) {
			if (Character.isLetter(chr[i])) {
				if (i == 0 || chr[i - 1] == ' ') {
					res.append(chr[i]);
				}
			}

		}
		System.out.println(res);
	}
}
