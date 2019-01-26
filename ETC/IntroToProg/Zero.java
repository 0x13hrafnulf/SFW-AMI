import java.util.Scanner;

public class Zero {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String one = input.next();
		String two = input.next();
		while(Integer.parseInt(one)!= 0 && Integer.parseInt(two)!= 0){
			Zero(one,two);
			one = input.next();
			two = input.next();
		}
	}

	static void Zero(String one, String two) {
//		int result = Integer.parseInt(one) + Integer.parseInt(two);
//		StringBuilder res = new StringBuilder();
//		res.append(String.valueOf(result));
//		for(int i = 0; i < res.length(); ++i){
//			if(res.charAt(i) == '0'){
//				res.deleteCharAt(i);
//			}
//		}
//		System.out.println(res);
		int result = Integer.parseInt(one) + Integer.parseInt(two);
		String res = String.valueOf(result);
		System.out.println(res.replaceAll("0", ""));
	}

}
