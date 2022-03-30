// 값 입력 받음

import java.util.Scanner;

public class HelloWorld {
	public static void main(String[] argc) {
		System.out.println("구구단 중 출력할 단은? : ");
		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();
		System.out.println("Number : " + number);
		System.out.println(number * 1);
		System.out.println(number * 2);
		System.out.println(number * 3);
		System.out.println(number * 4);
		System.out.println(number * 5);
		System.out.println(number * 6);
		System.out.println(number * 7);
		System.out.println(number * 8);
		System.out.println(number * 9);
	}
}