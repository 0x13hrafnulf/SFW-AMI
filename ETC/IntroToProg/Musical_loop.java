import java.util.*;

public class Musical_loop {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int test = input.nextInt();
			if (test == 0)
				break;
			int[] list = new int[test];
			for (int i = 0; i < test; ++i) {
				list[i] = input.nextInt();
			}
			Loop(test, list);
		}
	}

	static void Loop(int test, int[] loop) {
		int count = 0;
		if (loop.length == 2) {
			if (loop[0] != loop[1])
				count += 2;
		} else{
			for (int i = 1; i < loop.length - 1; ++i) {
				if ((loop[i] > loop[i + 1] && loop[i] > loop[i - 1])
						|| (loop[i] < loop[i + 1] && loop[i] < loop[i - 1])) {
					++count;
				}
			}
			if (loop[0] < loop[loop.length - 1] && loop[loop.length - 2] < loop[loop.length - 1]
					|| loop[0] > loop[loop.length - 1] && loop[loop.length - 2] > loop[loop.length - 1])
				++count;
			if(loop[0] > loop[loop.length - 1] && loop[0] > loop[1]
					|| loop[0] < loop[loop.length - 1] && loop[0] < loop[1]) ++count;
		}
		System.out.println(count);
	}
}