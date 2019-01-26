import java.util.*;
public class Sudoku {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		
		for(int i = 0; i < n; ++i){
			int[][] matrix = new int[9][9];
			for(int j = 0; j < n; ++j){
				for(int k = 0; k < n; ++k){
					matrix[j][k] = input.nextInt();
				}	
			}
			Sudoku(matrix);
		}		
	}

	static void Sudoku(int[][] matrix) {
		
		
	}

}
