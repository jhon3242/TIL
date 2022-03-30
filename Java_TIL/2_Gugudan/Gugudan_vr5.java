// 배열

public class Gugudan{
	public static void main(String[] argc) {
		int[] result = new int[9];
		for (int q = 2 ; q < 10; q ++) {
			for (int i = 0; i<result.length; i ++) {
				result[i] = q * (i + 1);
			}
			for(int i = 0; i < result.length; i++) {
				System.out.println(result[i]);
			}
		}
	}
}