import java.util.*;

public class HeadorTail {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int test = input.nextInt();
			if (test == 0)
				break;

			ArrayList<Integer> cases = new ArrayList<>();

			for (int i = 0; i < test; ++i) {
				cases.add(input.nextInt());
			}
			Check(test, cases);
		}
	}

	static void Check(int test, ArrayList<Integer> cases) {
		int marry = 0;
		int john = 0;
		for (int i = 0; i < test; ++i) {
			if (cases.get(i) == 0)
				++marry;
			else
				++john;
		}
		System.out.printf("Marry won %d times and John won %d times\n", marry, john);
	}

}
