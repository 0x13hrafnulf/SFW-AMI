import java.util.*;

public class Contract {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			String one = input.next();
			String msg = input.next();
			if (one.equals("0") && msg.equals("0"))
				break;
			Contract(one, msg);

		}

	}

	static void Contract(String one, String msg) {
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < msg.length(); ++i) {
			if (msg.charAt(i) != one.charAt(0)) {
				res.append(msg.charAt(i));
			}
		}
		for (int i = 0; i < res.length(); ++i) {
			if (res.charAt(0) == '0') {
				res.deleteCharAt(0);
			}
		}
		if (res.toString().equals("")) {
			System.out.println("0");
		} else {
			System.out.println(res);
		}

	}
}