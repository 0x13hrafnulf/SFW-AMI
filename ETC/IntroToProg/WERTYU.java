import java.util.Scanner;

public class WERTYU {

	static private char[] asc = new char[255];

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		asc['1'] = '`';
		asc['2'] = '1';
		asc['3'] = '2';
		asc['4'] = '3';
		asc['5'] = '4';
		asc['6'] = '5';
		asc['7'] = '6';
		asc['8'] = '7';
		asc['9'] = '8';
		asc['0'] = '9';
		asc['-'] = '0';
		asc['='] = '-';
		asc['W'] = 'Q';
		asc['E'] = 'W';
		asc['R'] = 'E';
		asc['T'] = 'R';
		asc['Y'] = 'T';
		asc['U'] = 'Y';
		asc['I'] = 'U';
		asc['O'] = 'I';
		asc['P'] = 'O';
		asc['['] = 'P';
		asc[']'] = '[';
		asc['\\'] = ']';
		asc['S'] = 'A';
		asc['D'] = 'S';
		asc['F'] = 'D';
		asc['G'] = 'F';
		asc['H'] = 'G';
		asc['J'] = 'H';
		asc['K'] = 'J';
		asc['L'] = 'K';
		asc[';'] = 'L';
		asc['\''] = ';';
		asc['X'] = 'Z';
		asc['C'] = 'X';
		asc['V'] = 'C';
		asc['B'] = 'V';
		asc['N'] = 'B';
		asc['M'] = 'N';
		asc[','] = 'M';
		asc['.'] = ',';
		asc['/'] = '.';
		asc[' '] = ' ';

		String line = input.nextLine();
		Wer(line);
	}

	private static void Wer(String line) {
		char[] ch = line.toCharArray();

		for (int i = 0; i < line.length(); ++i) {
			if(ch[i] != ' ')ch[i] = asc[ch[i]];	
		}
		System.out.println(String.valueOf(ch));
	}
}
