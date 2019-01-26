import java.util.*;

public class Encription {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			StringBuilder msg = new StringBuilder(input.nextLine());
			Decoding(msg);
		}
	}
	static void Decoding(StringBuilder msg) {
		int firstshift = 3;
		int secondshift = -1;
		int l = msg.length();
		// 1st part
		msg.reverse();
		for (int i = 0; i < l; ++i) {
			if (Character.isLetter(msg.charAt(i))){
				msg.setCharAt(i, (char) (msg.charAt(i) + firstshift));	
			}
		}
//		 2nd Part
		for (int k = l/2; k<l;++k){
			msg.setCharAt(k, (char) (msg.charAt(k) + secondshift));
		}
		System.out.println(msg);
	}
}

