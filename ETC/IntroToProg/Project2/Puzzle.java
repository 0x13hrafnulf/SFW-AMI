import java.util.*;

public class Puzzle {
	final int n = 4;
	Random rnd = new Random();
	int[][] puzzle = new int[n][n];
	private long shufflz = 0;
	private int indBlankX = 0;
	private int indBlankY = 0;

	public Puzzle() {
		start();
	}
	public void print() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if(puzzle[i][j]/10 == 0 && puzzle[i][j] != 0) System.out.print(" ");
				if (puzzle[i][j] == 0)
					System.out.print(" [X]");
				else
					System.out.printf(" %d ", puzzle[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	public void start() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				puzzle[i][j] = n * i + j + 1;
			}
		}
		puzzle[n - 1][n - 1] = 0;
	}
	public void shuffle(long shufflz) {

		for (int i = 0; i < shufflz; ++i) {
			coordBlank();
			int temp = puzzle[indBlankY][indBlankX];
			switch (rnd.nextInt(4)) {
			case 0:// MoveUp
				if (indBlankY > 0) {
					puzzle[indBlankY][indBlankX] = puzzle[indBlankY - 1][indBlankX];
					puzzle[indBlankY - 1][indBlankX] = temp;
					break;
				}
			case 1:// MoveRight
				if (indBlankX < n-1) {
					puzzle[indBlankY][indBlankX] = puzzle[indBlankY][indBlankX + 1];
					puzzle[indBlankY][indBlankX + 1] = temp;
					break;
				}
			case 2:// MoveDown
				if (indBlankY < n-1) {
					puzzle[indBlankY][indBlankX] = puzzle[indBlankY + 1][indBlankX];
					puzzle[indBlankY + 1][indBlankX] = temp;
					break;
				}
			case 3:// MoveLeft
				if (indBlankX > 0) {
					puzzle[indBlankY][indBlankX] = puzzle[indBlankY][indBlankX - 1];
					puzzle[indBlankY][indBlankX - 1] = temp;
					break;
				}
			}
		}
	}
	public void shuffleRnd() {
		do {
			start();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int i1 = rnd.nextInt(n);
					int j1 = rnd.nextInt(n);
					int temp = puzzle[i][j];
					puzzle[i][j] = puzzle[i1][j1];
					puzzle[i1][j1] = temp;
				}
			}
		} while (!solvable());
	}
	public void coordBlank(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (this.puzzle[i][j] == 0) {
					indBlankY = i;
					indBlankX = j;
				}
			}
		}
	}
	int blankPos(int[][] puzzle) {
		int blankBox = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (puzzle[i][j] == 0) {
					blankBox = i + j;
					indBlankY = i;
					indBlankX = j;
				}
			}
		}
		return blankBox;
	}
	public int numberOfInversions(int[][] puzzle) {
		int sum = 0;
		int[] check = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[n * i + j] = puzzle[i][j];
			}
		}
		for (int i = 0; i < n * n - 1; i++) {
			for (int j = i + 1; j < n * n; j++) {
				if (check[j] == 0)
					continue;
				if (check[i] > check[j])
					++sum;
			}
		}
		return sum;
	}
	public boolean solvable() {
		if (numberOfInversions(this.puzzle) % 2 == 0 && blankPos(this.puzzle) % 2 == 0)
			return true;
		else if (numberOfInversions(this.puzzle) % 2 != 0 && blankPos(this.puzzle) % 2 != 0)
			return true;
		else
			return false;
	}
	public void move(String key) {
		coordBlank();
		int temp = puzzle[indBlankY][indBlankX];
		switch (key) {
		case "S":// MoveUp
			if (indBlankY > 0) {
				puzzle[indBlankY][indBlankX] = puzzle[indBlankY - 1][indBlankX];
				puzzle[indBlankY - 1][indBlankX] = temp;
			}
			break;
		case "A":// MoveRight
			if (indBlankX < n-1) {
				puzzle[indBlankY][indBlankX] = puzzle[indBlankY][indBlankX + 1];
				puzzle[indBlankY][indBlankX + 1] = temp;
				
			}
			break;
		case "W":// MoveDown
			if (indBlankY < n-1) {
				puzzle[indBlankY][indBlankX] = puzzle[indBlankY + 1][indBlankX];
				puzzle[indBlankY + 1][indBlankX] = temp;
			}
			break;
		case "D":// MoveLeft
			if (indBlankX > 0) {
				puzzle[indBlankY][indBlankX] = puzzle[indBlankY][indBlankX - 1];
				puzzle[indBlankY][indBlankX - 1] = temp;
			}
			break;
		}
	}
	
	public int getBlankX(){
		return indBlankX;
	}
	public int getBlankY(){
		return indBlankY;
		
	}
	public boolean gameWin(){
		return numberOfInversions(this.puzzle) == 0 && blankPos(this.puzzle) % 2 == 0 && indBlankX == 3 && indBlankY == 3;
	}
	public void move(int y, int x){
		coordBlank();
		int temp = puzzle[indBlankY][indBlankX];
		puzzle[indBlankY][indBlankX] = puzzle[y][x];
		puzzle[y][x] = temp;
	}
	public boolean blankNeighbor(int y, int x){
		coordBlank();
		if(Math.abs(indBlankY - y) == 1 && Math.abs(indBlankX - x) == 0){
			return true;
		}
		else if(Math.abs(indBlankY - y) == 0 && Math.abs(indBlankX - x) == 1){
			return true;
		}		
		return false;
	}
}


