import java.util.*;

public class Bingo {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int n = input.nextInt();
			int b = input.nextInt();
			if (n + b == 0)
				break;

			ArrayList<Integer> list = new ArrayList<Integer>();

			for (int i = 0; i < b; ++i) {
				list.add(input.nextInt());
			}
			if(Bingo(n,b,list)) System.out.println("Y");
			else System.out.println("N");
		}
	}

	static boolean Bingo(int n, int b, ArrayList<Integer> list) {
		   boolean[] checked = new boolean[n+1];
		   checked[0] = true;

		   for(int i = 0; i < list.size(); ++i)
		      for(int j = 0; j < i; ++j)
		         checked[Math.abs(list.get(i) - list.get(j))] = true;

		   for(int i = 0; i < n + 1; ++i)
		      if (!checked[i])
		         return false;
		   return true;
	}
}
