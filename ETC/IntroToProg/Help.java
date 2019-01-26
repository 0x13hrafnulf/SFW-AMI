import java.util.*;

public class Help {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (true) {
			String test = input.next();
			int t = Integer.parseInt(test);
			
			if(test.equals("0")) break;
			
			String[] c = new String[t];
			int[] n = new int[t];
			String[] s = new String[t];

			for (int i = 0; i < t; ++i) {
				c[i] = input.next();
				n[i] = input.nextInt();
				s[i] = input.next();
			}
			Help(c, n, s, t);
		}
	}

	static void Help(String[] c, int[] n, String[] s, int t) {
		int count = 0;
		int result = 0;
		for (int i = 0; i < t; ++i) {
			if (s[i].equals("correct")) {
				++count;
				result += n[i];
			} else {
				for (int k = i + 1; k < t; ++k) {
					if (c[i].equals(c[k])) {
						if(s[k].equals("correct")) result += 20;
					}
				}
			}
		}
		System.out.println(count + " " + result);
	}

}
