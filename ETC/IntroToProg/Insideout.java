import java.util.*;

public class Insideout {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String test = in.nextLine();
		for(int i = 0; i < Integer.parseInt(test); ++i) {
			String text = in.nextLine();
			Insideout(text);
		}
	}

	static void Insideout(String text) {
		char[] chr = text.toCharArray();
		int l = chr.length;
		char[] newtext = new char[l];
		for (int i = 0; i < l/2; ++i) {
			newtext[i] = chr[l/2-1-i];
		}
		for (int i = l-1, j = 0; i >= l/2; --i,++j) {
			newtext[i] = chr[l/2+j];
		}
		System.out.println(String.valueOf(newtext));
	}

}
