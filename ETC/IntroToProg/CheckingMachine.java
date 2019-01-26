import java.util.*;
public class CheckingMachine {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		ArrayList<Integer> one = new ArrayList<Integer>();
		ArrayList<Integer> two = new ArrayList<Integer>();
		for(int i = 0; i < 5; ++i){
			one.add(input.nextInt());
		}
		for(int i = 0; i < 5; ++i){
			two.add(input.nextInt());
		}
		Check(one,two);
	}

	static void Check(ArrayList<Integer> one, ArrayList<Integer> two) {
		int count = 0;
		for(int i = 0; i < 5; ++i){
			if(one.get(i)!= two.get(i)){
				++count;
			}
		}
		if(count == 5) System.out.println("Y");
		else System.out.println("N");
	}

}
