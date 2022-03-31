package _ch2;

public class VarEx5 {

	public static void main(String[] args) {
		String str = "3";
		
		System.out.println(str.charAt(0));  // 숫자 3
		System.out.println('3' - '0' + 1);  // 숫자 4
		System.out.println('3' + 0);  // 숫자 51
		System.out.println((char)('3' + 0)); // 문자 3
	}
}
   