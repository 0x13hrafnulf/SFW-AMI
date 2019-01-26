import java.util.*;
public class MultipleReading {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNextLine()){
			String a = input.nextLine();
			String p = input.nextLine();
			Multy(a, p);
			
		}
		
		
		
	}

	static void Multy(String a, String p) {
		int l = a.length();
		int procs = Integer.parseInt(p);
		int rs = 0;
		int cycle = 0;
		for(int i = 0; i < l; ++i){
			if(a.charAt(i) == 'W'){
				++cycle;
				if(rs > 0){
					rs = 0;
					++cycle;
				}
			}
			if(a.charAt(i) == 'R'){
				++rs;
				if(rs == procs){
					++cycle;
					rs = 0;
				}
			}
		}
		if(rs > 0) ++cycle;
		System.out.println(cycle);
	}
}
