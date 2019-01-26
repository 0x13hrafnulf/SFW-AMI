import java.util.Scanner;

public class SubStringComparison {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine() && input.hasNextLine()) {
			String one = input.nextLine();
			String two = input.nextLine();
			Comparison(one, two);
		}

	}

	static void Comparison(String one, String two) {
		int count = 0;
		int l1 = one.length();
		int l2 = two.length();
		char[] on = one.toCharArray();
		char[] t = two.toCharArray();
		for (int i = 0; i < l1; ++i) {
			for (int j = 0; j < l2; ++j) {
				if (on[i] == t[j]) {
					int c = 0;
					for (int k = 0; (i+k)< l1 && (k + j) < l2; ++k) {
						if (on[i + k] != t[j + k]) break;
						++c;
					}
					if (c > count)
						count = c;
				}
			}
		}
		System.out.println(count);
	}

}

// for (int i = 0; i < n1; i++) {
// for (int j = 0; j < n2; j++) {
// if (str1[i] == str2[j]) {
// int c = 0;
// for (int k = 0; k+i<n1, k+j<n2; k++) {
// if (str1[k+i] != str2[k+j])
// break;
// c++;
// }
// if (c > max)
// max = c;
// }
// }
// }
// return max;
// }
