package videokurzus;

public class Human {
	private String name = "Gyula";
	private int age;
	
	
	public void writeMyName() {
		System.out.println("az én nevem " + this.name);
	}
		public String getName(){
			return name;
		
	}
		public void setName(String incoming){
			this.name = incoming;
		
	}
		public int getAge() {
			return age;
		}
		public void setAge(int age) {
			this.age = age;
		}
}
