class KulcsPar {
	java.math.BigInteger d, e, m;
	
	public KulcsPar() {
		int meretBitekben = 700 * (int) (java.lang.Math.log((double) 10)
			/ java.lang.Math.log((double) 2));
			
		java.math.BigInteger p =
			new java.math.BigInteger(meretBitekben, 100, new java.util.Random());
		
		java.math.BigInteger q =
			new java.math.BigInteger(meretBitekben, 100, new java.util.Random());
			
		m= p.multiply(q);
		
		java.math.BigInteger z = p.subtract(java.math.BigInteger.ONE).
			multiply(q.subtract(java.math.BigInteger.ONE));
			
		do {
			do {
				d = new java.math.BigInteger(meretBitekben, new java.util.Random());
			} while (d.equals(java.math.BigInteger.ONE));
		} while (!z.gcd(d).equals(java.math.BigInteger.ONE));
		
		e= d.modInverse(z);
	}
}