package _ch2;

public class PrintfEx1 {

	public static void main(String[] args) {
//		System.out.printf("%d\n", 15);	// 15
//		System.out.printf("%#o\n", 15);	// 017
//		System.out.printf("%#x\n", 15);	// 0xf
//		System.out.printf("%s\n", Integer.toBinaryString(15));	// 1111
//		
//		double f = 123.456789;
//		
//		System.out.printf("%f\n", f);  
//		System.out.printf("%e\n", f);  
//		System.out.printf("%g\n", f);  
		
//		System.out.printf("[%5d]\n", 10);
//		System.out.printf("[%-5d]\n", 10);
//		System.out.printf("[%05d]\n", 10);
//		System.out.printf("[%5d]\n", 1234567);  // [1234567]
		
		double f = 1.234556789;
		
		System.out.printf("[%14.10f]\n", f);  // [  1.2345567890]
		System.out.printf("[%14.6f]\n", f);   // [      1.234557]
		
		System.out.printf("[%s]\n", "www.naver.com");  // [www.naver.com]
		System.out.printf("[%20s]\n", "www.naver.com");  // [       www.naver.com]
		System.out.printf("[%-20s]\n", "www.naver.com");  // [www.naver.com       ]
		System.out.printf("[%.3s]\n", "www.naver.com");  // [www]
	}
}
   