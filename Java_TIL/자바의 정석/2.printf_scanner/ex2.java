import java.util.Scanner;
public class ScanfEx1 {
	public static void main(String[] argc) {
		// Scanner 객체 생성
		Scanner scanner = new Scanner(System.in);
		
//		int num1 = scanner.nextInt();
//		int num2 = scanner.nextInt();
//		
//		System.out.println(num1);
//		System.out.println(num2);
		String input = scanner.nextLine();
		int num = Integer.parseInt(input);
		System.out.println(num);
	}

}
