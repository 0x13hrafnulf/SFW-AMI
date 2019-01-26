import java.util.Scanner;

public class Justifier {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		boolean s = true;
		while (Integer.parseInt(test)!=0) {
			String[] one = new String[Integer.parseInt(test)];
			for (int i = 0; i < Integer.parseInt(test); ++i) {
				one[i] = input.nextLine();
			}
			if(s == false){
				System.out.println();
			}
			s = false;
			Justifier(one);
			test = input.nextLine();
		}

	}

	static void Justifier(String[] one) {
		int maxL = one[Max(one)].length();
		for (int i = 0; i < one.length; ++i) {
			for (int k = 0; k < maxL -one[i].length(); ++k){
				System.out.print(" ");
			}
			System.out.println(one[i]);
		}	
	}

	static int Max(String[] one) {
		int maxInd = 0;
		for (int i = 0; i < one.length; ++i) {
			if (one[i].length() > one[maxInd].length()) {
				maxInd = i;
			}
		}
		return maxInd;
	}
}
/*
import java.util.*;
public class ColumnJustifier {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int v = 0;
		while(true){
			
			String num = sc.next();
			if(num.equals("0")) break;
			String[] names = new String[Integer.parseInt(num)];
			
			for(int i = 0; i < Integer.parseInt(num); i++){
				names[i] = sc.next();
			}
			if(v != 0){
				System.out.println();
			}
			justify(names);
			v++;
			
		}

	}

	private static void justify(String[] names) {
		for(int i = 0; i < names.length; i++){
			
			for(int j = 0; j < maxName(names) - names[i].length(); j++){
				System.out.print(" ");
			}
			System.out.print(names[i]);
			System.out.println();
		}
		
	}

	private static int maxName(String[] names) {
		int max = names[0].length();
		for(int i = 0; i < names.length; i++){
			if(max < names[i].length()){
				max = names[i].length();
			}
		}
		return max;
	}

}
*/