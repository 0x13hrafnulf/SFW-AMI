import java.util.*;
public class ROCKSCISSORS {

	static String[] game = {"pedra","papel","tesoura","lagarto","spock"};
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String test = input.nextLine();
		for (int i = 0; i < Integer.parseInt(test); ++i) {
			String one = input.next();
			String two = input.next();
			Game(one,two);
		}
	}

	static void Game(String one, String two) {
		if(one.equals(two)) System.out.println("empate");
		else if(one.equals(game[2]) && two.equals(game[1])) System.out.println("rajesh");
		else if(one.equals(game[1]) && two.equals(game[0])) System.out.println("rajesh");
		else if(one.equals(game[0]) && two.equals(game[3])) System.out.println("rajesh");
		else if(one.equals(game[3]) && two.equals(game[4])) System.out.println("rajesh");
		else if(one.equals(game[4]) && two.equals(game[2])) System.out.println("rajesh");
		else if(one.equals(game[2]) && two.equals(game[3])) System.out.println("rajesh");
		else if(one.equals(game[3]) && two.equals(game[1])) System.out.println("rajesh");
		else if(one.equals(game[1]) && two.equals(game[4])) System.out.println("rajesh");
		else if(one.equals(game[4]) && two.equals(game[0])) System.out.println("rajesh");
		else if(one.equals(game[0]) && two.equals(game[2])) System.out.println("rajesh");
		else System.out.println("sheldon");

	}

}
