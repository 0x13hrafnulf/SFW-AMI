import java.util.ArrayList;
import java.util.Scanner;

public class Optical_Reader {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int test = input.nextInt();
			if (test == 0)
				break;
			for (int i = 0; i < test; ++i) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				for (int j = 0; j < 5; ++j) {
					list.add(input.nextInt());
				}
				Reader(list);
			}
		}
	}

	static void Reader(ArrayList<Integer> list) {
		char[] ans = { 'A', 'B', 'C', 'D', 'E' };
		int index = 0;
		int count = 0;
		for (int i = 0; i < 5; ++i) {
			if (list.get(i) < 128) {
				++count;
				index = i;
			}
		}
		if (count == 1)
			System.out.println(ans[index]);
		else
			System.out.println("*");
	}

}