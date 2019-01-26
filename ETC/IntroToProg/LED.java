import java.util.*;

public class LED {
	static int[] led = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for (int i = 0; i < test; ++i) {
			String numb = input.next();
			leds(numb);
		}
	}

	static void leds(String numb) {
		int sum = 0;
		char[] str = numb.toCharArray();
		for (int i = 0; i < numb.length(); ++i) {
			int ind = Integer.parseInt(String.valueOf(str[i]));
			sum += led[ind];
		}
		System.out.println(sum + " leds");
	}

}
