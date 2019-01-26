import java.util.ArrayList;
import java.util.Scanner;

public class Watson {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int test = input.nextInt();
			if (test == 0)
				break;

			ArrayList<Integer> list = new ArrayList<Integer>();
			for (int i = 0; i < test; ++i) {
				list.add(input.nextInt());
			}
			Test(test, list);
		}

	}

	static void Test(int test, ArrayList<Integer> list) {
		int max = 0;
		int count = 0;
		int result = 0;
		
		for(int i = 0; i < test; ++i){
			if(list.get(i) > max) max = list.get(i);	
		}
		for(int i = 0; i < test; ++i){
			if(list.get(i) > result && list.get(i) != max) {
				result = list.get(i);
				count = i;
			}
		}
		System.out.println(count+1);
	}

}