import java.util.*;
public class NumberFrequency {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0; i < n; ++i){
			list.add(input.nextInt());
		}
		freq(n, list);
	}

	static void freq(int n, ArrayList list) {
		HashSet<Integer> check = new HashSet<Integer>();
		check.addAll(list);
		
		ArrayList<Integer> sorted = new ArrayList<Integer>();
		sorted.addAll(check);
		Collections.sort(sorted);
		
		int[] count = new int[sorted.size()];

		for(int i = 0; i < sorted.size(); ++i){
			for(int j = 0; j < list.size(); ++j){
				if(sorted.get(i) == list.get(j)) ++count[i];
			}
		}
		for(int i = 0; i < sorted.size(); ++i){
			System.out.printf("%d %d\n", sorted.get(i) , count[i]);
		}
	}

}