import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class FakeTickets {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (true) {
			int tickets = input.nextInt();
			int persons = input.nextInt();
			if (tickets == 0 && persons == 0)
				break;
			ArrayList<Integer> list = new ArrayList<Integer>();
			for (int i = 0; i < persons; ++i) {
				list.add(input.nextInt());

			}
			Fake(tickets, persons, list);

		}

	}

	static void Fake(int tickets, int persons, ArrayList<Integer> list) {
		int count = 0;
		Collections.sort(list);
		int[] seen = new int[tickets];
		HashSet<Integer> l = new HashSet<Integer>();
		for (int i = 0; i < persons; ++i) {
			l.add(list.get(i));
		}
		for(int ls : l){
			int s = 0;
			for(int j = 0; j < persons; ++j){
				if(ls == list.get(j)){
					++s;
				}
			}
			if(s > 1) ++count;
		}	
		System.out.println(count);
	}
}