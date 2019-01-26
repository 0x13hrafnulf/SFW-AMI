import java.math.BigInteger;
import java.util.*;

public class Project1 {

	public static void main(String[] args) {
		try {
			BigInt a = new BigInt("1");
			BigInt b = new BigInt("0");
			System.out.println(a.divide(b));
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

}
