public class RSAPelda {
	
	public static void main (String[] args) {
		
		KulcsPar jSzereplo = new KulcsPar();
		
		//i -> j
		String tisztaSzoveg = "Hello vilag!";
		
		//kódol i
		byte[] buffer = tisztaSzoveg.getBytes();
		java.math.BigInteger[] titkos = new java.math.BigInteger[buffer.length];
		
		for (int i = 0; i < titkos.length; ++i)  {
			titkos[i] = new java.math.BigInteger(new byte[]{buffer[i]});
			titkos[i] = titkos[i].modPow(jSzereplo.e, jSzereplo.m);
		}
		
		// ----------------------------------------------------------------------
		
		// dekódol j
		for (int i = 0; i < titkos.length; ++i) {
			titkos[i] = titkos[i].modPow(jSzereplo.e, jSzereplo.m);
			buffer[i] = titkos[i].byteValue();
		}
		
		System.out.println(new String(buffer));
		
	}
}