import java.util.*;

public class DifferentDigits {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		Dig("87", "104");
	}

	static public void Dig(String n, String m) {
		int s = Integer.parseInt(n);
		int f = Integer.parseInt(m);
		int result = 0;
		for (int i = s; i <= f; ++i) {
			HashSet<Integer> list = new HashSet<Integer>();
			for (int j = 0; j < String.valueOf(i).length(); ++j) {
				list.add(String.valueOf(i).charAt(j) - '0');
			}
			if(list.size() == String.valueOf(i).length()) ++result;
		}
		System.out.println(result);
	}
}
