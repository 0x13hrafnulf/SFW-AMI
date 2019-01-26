import java.util.*;
public class HoursMinutes {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNextLine()){
			String ang = input.nextLine();
			if(Integer.parseInt(ang) % 6 == 0){
				System.out.println("Y");
			}else{
				System.out.println("N");
			}
		}
	}
}
