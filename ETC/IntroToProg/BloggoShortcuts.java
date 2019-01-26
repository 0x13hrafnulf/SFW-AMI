import java.util.*;

public class BloggoShortcuts {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNextLine()){
			String one = input.nextLine();
			Blog(one);
		}
		

	}
		static void Blog(String one) {
		int space = 0;
		int b = 0;
		StringBuilder res = new StringBuilder();
		res.append(one);
		for (int i = 0; i < res.length(); ++i){
			if (res.charAt(i) == '_' && space%2 == 0){
				res.replace(i, i+1, "<i>");
				++space;
			}else if(res.charAt(i) == '_' && space%2 != 0){
				res.replace(i, i+1, "</i>");
				++space;
			}if(res.charAt(i) == '*' && b%2 == 0){
				res.replace(i, i+1, "<b>");
				++b;
			}else if(res.charAt(i) == '*' && b%2 != 0){
				res.replace(i, i+1, "</b>");
				++b;
			}
			
		}
		System.out.println(res);
	}

}
