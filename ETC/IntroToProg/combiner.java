import java.util.*;

public class combiner {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String first = input.next();
			String second = input.next();
			combiner(first, second);
		}
	}

	static void combiner(String first, String second) {
		StringBuilder result = new StringBuilder();
		char[] one = first.toCharArray();
		char[] two = second.toCharArray();
		int max = first.length();
		if (max < second.length()) {
			max = second.length();
		}
		for (int i = 0; i < max; ++i) {
			if(i < first.length()){
				result.append(one[i]);
			}
			if(i < second.length()){
				result.append(two[i]);
			}
		}
		System.out.println(result);

	}

}
