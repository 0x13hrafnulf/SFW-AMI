import java.util.*;

public class BigInt {

	private ArrayList<Integer> digits;
	int sign = 1;
	
	public BigInt(String number) throws Exception {
		digits = new ArrayList<Integer>();
		for (int i = 0; i < number.length(); ++i) {
			char ch = number.charAt(i);
			if (i == 0 && ch == '-') {
				sign *= -1;
				continue;
			}
			if (!(Character.isDigit(ch))) {
				throw new Exception("Incorrect BigInt: " + number);
			}
			digits.add(ch - '0');
		}

	}

	private BigInt(String number, int sign) throws Exception {
		this.sign = sign;
		digits = new ArrayList<Integer>();
		for (int i = 0; i < number.length(); ++i) {
			char ch = number.charAt(i);
			if (!(Character.isDigit(ch))) {
				throw new Exception("Incorrect BigInt: " + number);
			}
			digits.add(ch - '0');
		}
	}

	@Override
	public String toString() {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < digits.size(); ++i) {
			if( i == 0) result.append(digits.get(i)*this.sign);
			else result.append(digits.get(i));
		}
		return result.toString();
	}

	private BigInt addition(BigInt another) throws Exception {
		BigInt result = new BigInt("0");
		result.digits.remove(0);

		int i = digits.size() - 1;
		int j = another.digits.size() - 1;
		int carry = 0;

		while (i > -1 || j > -1 || carry != 0) {
			int sum = carry;
			if (i > -1) {
				sum += digits.get(i);
				--i;
			}
			if (j > -1) {
				sum += another.digits.get(j);
				--j;
			}
			carry = sum / 10;
			int d = sum % 10;
			result.digits.add(0, d);
		}
		return result;
	}

	private BigInt substraction(BigInt another) throws Exception {
		BigInt result = new BigInt("0");
		result.digits.remove(0);
		int i = digits.size() - 1;
		int j = another.digits.size() - 1;
		int carry = 0;
		if (comparison(another) == -1) {
			while (i > -1 || j > -1) {
				int sum = carry;
				carry = 0;
				if (i > -1) {
					sum -= digits.get(i);
					--i;
				}
				if (j > -1) {
					sum += another.digits.get(j);
					--j;
				}
				int d = 0;
				if (sum < 0) {
					d = 10 + sum;
					carry = -1;
				} else {
					d = sum;
				}
				result.digits.add(0, d);
			}
		} else {
			while (i > -1 || j > -1) {
				int sum = carry;
				carry = 0;
				if (i > -1) {
					sum += digits.get(i);
					--i;
				}
				if (j > -1) {
					sum -= another.digits.get(j);
					--j;
				}
				int d = 0;
				if (sum < 0) {
					d = 10 + sum;
					carry = -1;
				} else {
					d = sum;
				}
				result.digits.add(0, d);
			}
		}
		for (int k = result.digits.size(); k > 0; --k) {
			if (result.digits.get(0) == 0 && result.digits.size() > 1)
				result.digits.remove(0);
		}
		return result;
	}

	public BigInt multiplication(BigInt another) throws Exception {
		BigInt result = new BigInt("0");
		result.digits.remove(0);
		int i = digits.size() - 1;
		int j = another.digits.size() - 1;
		int k = j;
		while (j > -1) {
			BigInt smthg = new BigInt("0");
			smthg.digits.remove(0);
			int carry = 0;
			while (i > -1 || carry != 0) {
				int sum = carry;
				if (i > -1) {
					sum += digits.get(i) * another.digits.get(j);
					--i;
				}
				carry = sum / 10;
				int d = sum % 10;
				smthg.digits.add(0, d);
			}
			if (j < k) {
				for (int s = j; s < k; ++s) {
					smthg.digits.add(0);
				}
			}
			--j;
			result = result.addition(smthg);
			i = digits.size() - 1;
		}
		return result;
	}

	private int comparison(BigInt another) throws Exception {
		int i = digits.size() - 1;
		int j = another.digits.size() - 1;

		if (i > j)
			return 1;
		if (i < j)
			return -1;
		for (int k = 0; k <= i; ++k) {
			if (digits.get(k) < another.digits.get(k)) {
				return -1;
			}
			if (digits.get(k) > another.digits.get(k)) {
				return 1;
			}
		}
		return 0;
	}

	private BigInt divison(BigInt another) throws Exception {
		BigInt result = new BigInt("0");
		result.digits.remove(0);
		int i = digits.size();
		int j = another.digits.size();
		if (another.compareTo(new BigInt("0")) == 0) {
			throw new Exception("Divisor cannot be zero");
		} else if (comparison(another) == -1)
			result.digits.add(0);
		else if (comparison(another) == 0)
			result.digits.add(1);
		else {
			BigInt dividend = new BigInt(toString().substring(0));
			result = result.addition(div(dividend, another));
			// divide and conqueror: 0 <= remainder <= b
			BigInt remainder = dividend.substraction(another.multiplication(result));
			while(remainder.comparison(another) != -1){
				result = result.addition(div(remainder, another));
				remainder = dividend.substraction(another.multiplication(result));
			}
		}
		return result;
	}
	public BigInt remainder(BigInt another) throws Exception{		
		return this.substraction(this.divison(another).multiplication(another));
	}
	// a = b*multiplier + remainder;
	private BigInt div(BigInt a, BigInt b) throws Exception {										
		BigInt m = new BigInt("1");
		while (a.comparison(b.multiplication(m)) != -1 || a.comparison(b.multiplication(m)) == 0) {
			m = m.multiplication(new BigInt("10"));
		}
		m.digits.remove(m.digits.size() - 1);
		BigInt ml = m;
		while (a.comparison(b.multiplication(m)) != -1 || a.comparison(b.multiplication(m)) == 0) {
			m = m.addition(ml);
		}
		m = m.substraction(ml);	
		return m;
	}


	public BigInt add(BigInt another) throws Exception {
		if(sign > 0 && another.sign < 0){// check any cases
			if(comparison(another) == 0) return new BigInt(substraction(another).toString(), 1);
			else return new BigInt(substraction(another).toString(), comparison(another) == 1 ? 1 : -1);
		}
		else if(sign < 0 && another.sign > 0){// check any cases
			if(comparison(another) == 0) return new BigInt(substraction(another).toString(), 1);
			else return new BigInt(substraction(another).toString(), comparison(another) == -1 ? 1 : -1);
		}
		return new BigInt(addition(another).toString(), sign < 0 && another.sign < 0 ? -1 : 1);
	}

	public BigInt substract(BigInt another) throws Exception {
		if(sign > 0 && another.sign < 0){
			return new BigInt(addition(another).toString(), 1);
		}
		else if(sign < 0 && another.sign > 0){
			return new BigInt(addition(another).toString(), -1);
		}
		else if(sign < 0 && another.sign < 0){
			if(comparison(another) == 0) return new BigInt(substraction(another).toString(), 1);
			else return new BigInt(substraction(another).toString(), comparison(another) == -1 ? 1 : -1);
		}
		return new BigInt(substraction(another).toString(), comparison(another) == 1 ? 1 : -1);
	}

	public BigInt multiply(BigInt another) throws Exception {
		return new BigInt(multiplication(another).toString(), sign*another.sign);
	}

	public BigInt divide(BigInt another) throws Exception {
		return new BigInt(divison(another).toString(), sign*another.sign);
	}

	public int compareTo(BigInt another) throws Exception {
		if (sign < 0 && another.sign > 0)
			return -1;
		else if (sign > 0 && another.sign < 0)
			return 1;
		else if (sign + another.sign < 0) {
			if (comparison(another) == 1) {
				return -1;
			} else if (comparison(another) == -1) {
				return 1;
			} else {
				return 0;
			}
		}
		return comparison(another);
	}
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(System.in);
		BigInt a = new BigInt(input.next());
		BigInt b = new BigInt(input.next());
		System.out.println(a.remainder(b));
	}
}