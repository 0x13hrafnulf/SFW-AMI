import java.util.*;
public class FAQ {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(true){
			int a = input.nextInt();
			int b = input.nextInt();
			if(a + b == 0) break;
			ArrayList<Integer> list = new ArrayList<Integer>();
			for(int i = 0; i < a; ++i){
				list.add(input.nextInt());
			}
			FAQ(a,b,list);
		}

	}

	static void FAQ(int a, int b, ArrayList<Integer> list) {
		HashSet<Integer> check = new HashSet<Integer>();
		int count = 0;
		for(int i = 0; i < list.size(); ++i){
			check.add(list.get(i));
		}
		for(Integer d : check){
			int u = 0;
			for(int j = 0; j < list.size(); ++j){
				if(d == list.get(j)) ++u;
			}
			if(u >= b) ++ count;
		}
		System.out.println(count);
	}
}
