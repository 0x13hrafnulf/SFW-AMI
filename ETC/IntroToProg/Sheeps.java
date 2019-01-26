import java.util.*;

public class Sheeps {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		
		for(int i = 0; i < test; ++i){
			int t = input.nextInt();
			HashSet<Integer> sheep = new HashSet<Integer>();
			for(int j =0; j < t; ++j){
				sheep.add(input.nextInt());				
			}
			System.out.println(sheep.size());
		}
	}
}
