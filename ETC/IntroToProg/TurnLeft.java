import java.util.*;
public class TurnLeft {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true){
			int test = input.nextInt();
			if(test == 0) break;
			String c = input.next();
			
			Command(test, c);
		}
	}

		static void Command(int test, String c) {
		int dir = 0;
		char[] s = {'N','L','S','O'};
		for (int i = 0; i < test; ++i){
			//if(dir == 4 || dir == -4) dir = 0;
			if(c.charAt(i)=='D'){
				dir++;
			}
			else if(c.charAt(i)=='E'){
				dir--;
			}
			
		}
		dir%=4;
		dir+=4;
		dir%=4;
		System.out.println(s[Math.abs(dir)]);
		
		
		
	}

}
