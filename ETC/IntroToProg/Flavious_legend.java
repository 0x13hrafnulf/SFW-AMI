import java.util.*;

public class Flavious_legend {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for (int i = 1; i <= test; ++i) {
			int n = input.nextInt();
			int k = input.nextInt();
			System.out.printf("Case %d: %d\n",i, Flav(n,k));
		}

	}

	static int Flav(int n, int k) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0; i < n; ++i){
			list.add(i+1);
		}
		int i = 0;
		while(list.size() > 1){
			i = (i+k-1)%list.size();
			list.remove(i);
		}
		return list.get(0);
	}
	
	
	
	
/*	
	static int Flavious(int n,int k){
		if( n <= 1) return 1;
		else return (Flavious(n-1, k)+k-1)%n+1;
		
	}
	*/
}