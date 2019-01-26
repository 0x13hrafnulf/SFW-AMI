import java.util.*;
public class RobotInstr {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		int position = 0;
		for(int i = 0; i < Integer.parseInt(test); ++i){
			String cases = input.nextLine();
			int[] coms = new int[Integer.parseInt(cases)];
			for(int j = 0; j < Integer.parseInt(cases); ++j){
				String com = input.nextLine();
				if(com.equals("RIGHT")){
					coms[j] = 1;
				}else if(com.equals("LEFT")){
					coms[j] = -1;
				}
				else{
					coms[j] = coms[Integer.parseInt(com.substring(8))-1];
				}
				position += coms[j];
			}
			System.out.println(position);
			position = 0;
		}
	}

}
