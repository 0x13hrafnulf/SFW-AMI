import java.util.*;

public class Shuffle_Console {

	public static void main(String[] args) {
		boolean run = true;
		while (run) {
			Puzzle puz = new Puzzle();
			Scanner input = new Scanner(System.in);
			puz.start();
			puz.print();
			boolean continueInput = true;
			do {
				try {
					System.out.print("Number of moves to Shuffle? ");
					int moves = input.nextInt();
					puz.shuffle(moves);
					puz.print();
					continueInput = false;
				} catch (Exception e) {
					System.out.println();
					System.out.println("Wrong input. Enter number of moves in order to shuffle the puzzle.");
					input.nextLine();
					System.out.println();
				}
			} while (continueInput);
			try {
				while (puz.gameWin() != true) {
					System.out.print("Your move (W, D, S, A): ");
					String key = input.next();
					if (!(key.toUpperCase().equals("W") || key.toUpperCase().equals("D")
							|| key.toUpperCase().equals("A") || key.toUpperCase().equals("S")))
						throw new Exception(
								"Wrong command. Use:\n<W> - to move blank space up\n<D> - to move blank space Left\n<S> - to move blank space down\n<A> - to move blank space right\n");
					puz.move(key.toUpperCase());
					puz.print();
				}
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
			if (puz.gameWin()) {
				System.out.println("GRATZZZ!!! YOU WON!!!");
				System.out.println();
			}
			input.nextLine();
			boolean answer = true;
			do {
				try{
				System.out.print("Do you want to try Again (Y/N)? ");
				String ans = input.next();
				if(!(ans.toUpperCase().equals("Y") || ans.toUpperCase().equals("N"))) throw new Exception("Incorrect command. Use:\n<Y>/<y> - yes\n<N>/<n> - no");
				if(ans.toUpperCase().equals("N")){
					answer = false;
					run = false;
					System.out.println("The game has stopped.");
					}
				else if(ans.toUpperCase().equals("Y")){
					answer = false;
					run = true;
				}
				}catch(Exception e){
					System.out.println();
					System.out.println(e.getMessage());
					input.nextLine();
					System.out.println();
				}
			} while (answer);
		}
	}
}
