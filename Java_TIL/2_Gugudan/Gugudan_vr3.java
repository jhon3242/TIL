// 반복문 사용

import java.util.Scanner;

public class Gugudan{
	public static void main(String[] argc) {
		System.out.println("구구단의 단은 ? : ");
		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();
		int i = 0;
		while (i < 10) {
			System.out.println(number * i);
			i += 1;
		}
		for (int q = 1;  q < 10 ; q++) {
			System.out.println(q);
		}
	}
}