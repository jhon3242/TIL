// 메서드 사용

import java.util.Scanner;

public class Gugudan{
	public static int[] calculator(int number) {
		int[] result = new int[9];
		for (int i = 0; i < result.length ; i ++) {
			result[i] = number * (i + 1);
		}
		return result;
	}
	
	public static void print_array(int[] array) {
		for (int i= 0; i < array.length ; i++) {
			System.out.println(array[i]);
		}
	}
	
	public static void main(String[] argc) {
		System.out.println("구구단 단을 입력하시오 : ");
		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();
		int[] result = calculator(number);
		print_array(result);
	}
}