import java.util.*;
public class Colision {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for(int i = 0; i < Integer.parseInt(test); ++i){
			int[] Rect = new int[8];
			int[] Rob = new int[2];
			for(int j = 0; j < 8; ++j) Rect[j] = input.nextInt();
			for(int j = 0; j < 2; ++j) Rob[j] = input.nextInt();
			Colision(Rect, Rob);
		}
	}

	static void Colision(int[] rect, int[] rob) {
		if(rob[0] >= rect[0] && rob[0] <= rect[2]){
			if(rob[1] >= rect[1] && rob[1] <= rect[7])
				System.out.println(1);
			else
				System.out.println(0);
		}else
			System.out.println(0);
		
	}

}
