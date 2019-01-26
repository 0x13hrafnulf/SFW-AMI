import java.util.*;

public class ExCards {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int a = input.nextInt();
			int b = input.nextInt();
			if(a == 0 && b == 0) break;
			HashSet<Integer> one = new HashSet<Integer>();
			HashSet<Integer> two = new HashSet<Integer>();
			for (int i = 0; i < a; ++i) {
				one.add(input.nextInt());
			}
			for (int i = 0; i < b; ++i) {
				two.add(input.nextInt());
			}
			counter(one, two);
		}
	}

	public static void counter(HashSet<Integer> one, HashSet<Integer> two) {
		int c1 = 0;
		int c2 = 0;

		for (Integer i : one) {
			if (!two.contains(i))
				++c1;
		}
		for (Integer i : two) {
			if (!one.contains(i))
				++c2;
		}
		System.out.println(Math.min(c1, c2));
	}
}
