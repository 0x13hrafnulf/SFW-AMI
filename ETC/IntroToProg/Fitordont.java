import java.util.*;

public class Fitordont {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String first = input.next();
			String second = input.next();
			fit(first, second);
		}
	}

	static void fit(String first, String second) {
		int l1 = first.length();
		int l2 = second.length();
		if(l1>=l2){
			if (first.substring(l1 - l2, l1).equals(second)) {
				System.out.println("encaixa");
			}else {
				System.out.println("nao encaixa");
			}
		}else{
			System.out.println("nao encaixa");
		}
	}
}
