import java.util.*;

public class AdvancingLetters {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String one = input.next();
			String two = input.next();
			Counter(one, two);
		}
	}

	static void Counter(String one, String two) {
		int count = 0;
		char[] on = one.toCharArray();
		char[] tw = two.toCharArray();
		int l = on.length;
		for (int i = 0; i < l; ++i) {// alphabet
			if (tw[i]-on[i] >= 0){
				count += tw[i]-on[i];
			}else{
				count += tw[i]-on[i] + 26;
			}
		}
		System.out.println(count);
	}

}
