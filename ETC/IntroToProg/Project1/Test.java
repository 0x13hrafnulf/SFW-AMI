import java.util.*;
public class Test {

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(System.in);
		BigInt a = new BigInt(input.next());
		BigInt b = new BigInt(input.next());
		System.out.println(a.add(b));
	}

}
