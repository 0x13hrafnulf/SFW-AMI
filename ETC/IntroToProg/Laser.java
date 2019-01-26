import java.util.*;
public class Laser {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true){
			int a = input.nextInt();
			int c = input.nextInt();
			if(a + c == 0) break;
			ArrayList<Integer> list = new ArrayList<Integer>();
			for (int i = 0; i < c; ++i){
				list.add(input.nextInt());
			}
			Laser(a,list);
		}
	}

	static void Laser(int a, ArrayList<Integer> list) {
		int result = 0;
		int last = a;
		for(int i = 0; i < list.size(); ++i){
			if(last > list.get(i)) result += last -list.get(i);
			last = list.get(i);
		}
		System.out.println(result);
	}

}
//for(int i = 0; i < list.size(); ++i){
//	if(i>0){
//		if(list.get(i-1)>list.get(i)){
//			result += list.get(i-1)-list.get(i);
//		}
//	}else{
//		result += a - list.get(i);
//	}
//}