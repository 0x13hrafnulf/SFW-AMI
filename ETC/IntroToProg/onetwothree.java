import java.util.*;

public class onetwothree {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String word = input.nextLine();
			Counter(word);
		}
	}
	static void Counter(String word) {
		int l = word.length();
		char[] ch = word.toCharArray();
		if(l==3){
			if((ch[0]=='o'&& ch[1]=='n')||(ch[0]=='o'&& ch[2]=='e')||(ch[1]=='n'&& ch[2]=='e')){
				System.out.println(1);
			}else{
				System.out.println(2);
			}
		}else{
			System.out.println(3);
		}
	}
}