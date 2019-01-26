import java.util.*;
public class InternationalChar {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		int n = Integer.parseInt(test);
		for(int i = 0; i < n; ++i){
			String t = input.nextLine();
			int k = Integer.parseInt(t);
			String[] s = new String[k];
			for(int j = 0; j < k; ++j){
				s[j] = input.nextLine();
			}
			Chat(s,k);
		}

	}
	static void Chat(String[] s, int k) {
		String c = s[0];
		int n = 1;
		for(int i = 1; i < k; ++i){
			if(s[i].equals(c)) ++n;
		}
		if(n == k) System.out.println(c);
		else System.out.println("ingles");
	}

}
