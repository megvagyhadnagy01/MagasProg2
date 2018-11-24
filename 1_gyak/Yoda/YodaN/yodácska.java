package prog2gyak;

public class yodácska {
public static void main(String[] args) {
		
		final String str = null;
		
		try {
			if(str.equals("something")) {
				//Do something
			}
			System.out.println("1. Success");

		} catch(Exception e) {
			System.err.println(e.getMessage());
		}

		try {
			if("something".equals(str)) {
				//Do something
			}
			System.out.println("2. Success");

		} catch(Exception e) {
			System.err.println(e.getMessage());
		}
	}
}
