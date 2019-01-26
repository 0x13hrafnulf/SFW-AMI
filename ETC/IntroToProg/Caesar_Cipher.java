import java.util.*;

public class Caesar_Cipher {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for (int i = 0; i < test; ++i) {
			String msg = input.next();
			int shift = input.nextInt();
			Decoding(msg, shift);
		}
	}
	static void Decoding(String msg, int shift) {
		String codedMsg = "";
		for (int i = 0; i < msg.length(); ++i) {
			char newchar = (char)(msg.charAt(i)-shift);
			if (newchar < 'A'){
				newchar = (char)(msg.charAt(i)+(26-shift));
			}
			codedMsg+=newchar;
		}
		System.out.println(codedMsg);
	}
}
