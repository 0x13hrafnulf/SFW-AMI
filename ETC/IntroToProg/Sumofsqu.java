import java.util.Scanner;
import java.util.*;

public class Sumofsqu {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNextLine()){
			String line = input.nextLine();
			int number = Integer.parseInt(line);
			Sum(number);
		}
	}

	static void Sum(int number) {
		boolean result = false;
		for(int i = 0; i < number; ++i){
			for(int j = 0; j < number; ++j){
				if((i*i + j*j) == number) result = true;
			}
		}
		if(result == true) System.out.println("YES");
		else System.out.println("NO");
	}
}
