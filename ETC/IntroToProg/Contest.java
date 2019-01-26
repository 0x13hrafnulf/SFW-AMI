import java.util.*;

public class Contest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int n = input.nextInt();
			int m = input.nextInt();
			if (n == 0 && m == 0)
				break;

			int[][] cont = new int[n][m];

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					cont[i][j] = input.nextInt();
				}
			}

			Contest(n, m, cont);
		}
	}

	static void Contest(int n, int m, int[][] cont) {
		int[] c = new int[m];
		int result = 0;
		int one = 0, four = 0;
		for (int i = 0; i < n; ++i) {
			int check = 0;
			int checkf = 0;
			for (int j = 0; j < m; ++j) {
				if (cont[i][j] > 0) {
					++check;
					++checkf;
				}
				c[j] += cont[i][j];
			}
			if (check < m)
				++one;
			if (checkf > 0)
				++four;
		}
		if (one == n)
			++result;
		if(four == n)
			++result;
		int two = 0, three = 0;
		for (int i = 0; i < m; ++i) {
			if (c[i] > 0)
				++two;
			if (c[i] < n)
				++three;
		}
		if (two == n)
			++result;
		if (three < m)
			++result;
		// Nobody solved all the problems.

		// Every problem was solved by at least one person (not necessarily the
		// same).

		// There is no problem solved by everyone.

		// Everyone solved at least one problem (not necessarily the same).
		System.out.println(result);
	}

}
