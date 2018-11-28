package videokurzus;

public class ElsoProject {

	public static void main(String[] args) {
		Human first = new Human();
		Human second = new Human();
		first.setName("Margit");
		first.setAge(18);
		
		
		String firstName=first.getName();
		int firstAge=first.getAge();
		
		boolean empty = (firstName == null);
		System.out.println(empty);
		System.out.println("");
		System.out.println(empty == true ? "Üres!" : "nem Üres!");
		
//		if(firstName== null) {
//			System.out.println("Nincs név!");
//		}else {
//			System.out.println("Van név! " + firstName +" "+ firstAge);
//		}
//			System.out.println("");
		
			System.out.println("");
			System.out.println(first.getName());
			System.out.println(second.getName());
			System.out.println(first.getAge());
			System.out.println("");
			
			System.out.println(firstName.charAt(2) +" "+ firstName.length());
			
	}
	
}
