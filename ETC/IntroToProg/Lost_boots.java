import java.util.*;

public class Lost_boots {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNext()) {
			int test = input.nextInt();
			ArrayList<Integer> s = new ArrayList<Integer>();
			ArrayList<String> p = new ArrayList<String>();
			for (int i = 0; i < test; ++i) {
				s.add(input.nextInt());
				p.add(input.next());
			}
			Check(test, s, p);
		}
	}

	static void Check(int test, ArrayList<Integer> s, ArrayList<String> p) {
		int count = 0;
		int[] r = new int[100];
		int[] l = new int[100];

		for (int i = 0; i < test; ++i) {
			if (p.get(i).equals("D")) {
				++r[s.get(i)];
			} else {
				++l[s.get(i)];
			}
		}

		for (int i = 0; i < 100; ++i) {
			count += Math.min(r[i], l[i]);
		}
		System.out.println(count);
	}
}
