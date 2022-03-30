// 조건문 & 반복문

import java.util.Scanner;
public class Gugudan{
	public static void main(String[] argc) {
		System.out.println("구구단의 단은? : ");
		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();
		if (number > 1 && number < 10) {
			for (int i = 1; i < 10; i++) {
				System.out.println(number * i);
			}
		}
		else
			System.out.println("2단에서 9단 사이의 값을 입력하세요.");
	}
}