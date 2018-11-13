public aspect SzamolAspect {

	private int egy = 0;
	private int nulla = 0;

	public pointcut nullasGyermek(): call(void Csomopont.ujNullasGyermek(Csomopont));
	public pointcut egyesGyermek(): call(void Csomopont.ujEgyesGyermek(Csomopont));
	public pointcut vege(): execution(public static void main(String[]));

	after():nullasGyermek() {
		nulla++;
	}
	after():egyesGyermek() {
		egy++;
	}
	after():vege() {
		System.out.println("Sz�ml�l� aspect: ");
        System.out.println("0-k sz�ma: " + nulla + "; 1-ek sz�ma: " + egy);
	}
}