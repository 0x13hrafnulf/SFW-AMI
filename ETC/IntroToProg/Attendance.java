import java.util.*;

public class Attendance {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			int l = input.nextInt();
			String[] name = new String[l];
			String[] record = new String[l];
			for (int j = 0; j < l; ++j){
				name[j] = input.next();
			}
			for (int j = 0; j < l; ++j){
				record[j] = input.next();
			}
			
			Attendance(l, name, record);
		}
	}

	static void Attendance(int l, String[] name, String[] record) {
		double limit = 0.75;
		boolean first = true;
		for (int i = 0; i < l; ++i) {
			int total = record[i].length();
			int at = 0;
			for (int j = 0; j < record[i].length(); ++j) {
				if (record[i].charAt(j) == 'P') {
					++at;
				} else if (record[i].charAt(j) == 'M') {
					--total;
				}
			}
			if((double) at/total < limit){
				if(first){
					System.out.print(name[i]);
					first = false;
				}else{
					System.out.print(" " + name[i]);
				}
			}
		}
		System.out.println();
	}
}
