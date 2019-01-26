import java.util.*;

public class Queen {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int[] xy = new int[4];

			for (int i = 0; i < 4; ++i) {
				xy[i] = input.nextInt();
			}

			if (xy[0] == 0 && xy[1] == 0 && xy[2] == 0 && xy[3] == 0)
				break;
			Queen(xy);
		}
	}

	static void Queen(int[] xy) {
		int result = 0;

		if ((xy[2] - xy[0]) == (xy[3] - xy[1]))
			result = 0;
		else if (Math.abs((xy[2] - xy[0])) - Math.abs((xy[3] - xy[1])) == 0)
			result = 1;
		else if ((xy[2] == xy[0]) || (xy[3] == xy[1]))
			result = 1;
		else
			result = 2;

		System.out.println(result);
	}

}
