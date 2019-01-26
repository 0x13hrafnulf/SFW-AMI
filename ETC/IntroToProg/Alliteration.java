import java.util.*;
public class Alliteration {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNextLine()){
			String one = input.nextLine();
			All(one);
		}
	}

	static void All(String one) {
		int count = 0;
		String[] ch = one.split(" ", 0);
		for (int i = 0; i < ch.length-1;++i){
			if (ch[i].charAt(0) == ch[i+1].charAt(0)){
				++count;
				++i;
			}
		}
		System.out.println(count);
	}

}
