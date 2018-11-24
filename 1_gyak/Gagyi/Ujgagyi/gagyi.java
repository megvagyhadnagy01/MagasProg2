package prog2gyak;

public class gagyi {
	

		public static void main(String[] args) {
			
			Integer i = 130;
			Integer j = 130;
			
			if(i <= j && i >= j && i != j) {
				System.out.println("1. Belép i = " + i + " j = " + j);
			}	
			
			i = 10;
			j = 10;
			
			if(i <= j && i >= j && i != j) {
				System.out.println("2. Belép i = " + i + " j = " + j);
			}
			
			i = new Integer(10);
			j = new Integer(10);
			
			if(i <= j && i >= j && i != j) {
				System.out.println("3. Belép i = " + i + " j = " + j);
			}
		}
	}

