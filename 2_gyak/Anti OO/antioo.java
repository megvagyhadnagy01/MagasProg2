package testProject;


	/*
	 * PiBBPBench.java
	 *
	 * DIGIT 2005, Javat tan�tok
	 * B�tfai Norbert, nbatfai@inf.unideb.hu
	 *
	 */
	/**
	 * A PiBBP.java-b�l kivett�k az "objektumorient�lts�got", �gy kaptuk
	 * ezt az oszt�lyt.
	 *
	 * (A PiBBP oszt�ly a BBP (Bailey-Borwein-Plouffe) algoritmust a Pi hexa
	 * jegyeinek sz�mol�s�t v�gz� oszt�ly. A k�nnyebb olvahat�s�g
	 * kedv��rt a v�ltoz� �s met�dus neveket megpr�b�ltuk az algoritmust
	 * bemutat� [BBP ALGORITMUS] David H. Bailey: The BBP Algorithm for Pi.
	 * cikk jel�l�seihez.)
	 *
	 * @author B�tfai Norbert, nbatfai@inf.unideb.hu
	 * @version 0.0.1
	 */
	public class PiBBPBench {
	    /**
	     * BBP algoritmus a Pi-hez, a [BBP ALGORITMUS] David H. Bailey: The
	     * BBP Algorithm for Pi. alapj�n a {16^d Sj} r�szlet kisz�m�t�sa.
	     *
	     * @param   d   a d+1. hexa jegyt�l sz�moljuk a hexa jegyeket
	     * @param   j   Sj indexe
	     */
	    public static double d16Sj(int d, int j) {
	        
	        double d16Sj = 0.0d;
	        
	        for(int k=0; k<=d; ++k)
	            d16Sj += (double)n16modk(d-k, 8*k + j) / (double)(8*k + j);
	        
	        /* (bekapcsolva a sorozat elejen az els� ut�ni jegyekben n�veli pl.
	            a pontoss�got.)
	        for(int k=d+1; k<=2*d; ++k)
	            d16Sj += Math.pow(16.0d, d-k) / (double)(8*k + j);
	         */
	        
	        return d16Sj - Math.floor(d16Sj);
	    }
	    /**
	     * Bin�ris hatv�nyoz�s mod k, a 16^n mod k kisz�m�t�sa.
	     *
	     * @param   n   kitev�
	     * @param   k   modulus
	     */
	    public static long n16modk(int n, int k) {
	        
	        int t = 1;
	        while(t <= n)
	            t *= 2;
	        
	        long r = 1;
	        
	        while(true) {
	            
	            if(n >= t) {
	                r = (16*r) % k;
	                n = n - t;
	            }
	            
	            t = t/2;
	            
	            if(t < 1)
	                break;
	            
	            r = (r*r) % k;
	            
	        }
	        
	        return r;
	    }
	    /**
	     * A [BBP ALGORITMUS] David H. Bailey: The
	     * BBP Algorithm for Pi. alapj�n a
	     * {16^d Pi} = {4*{16^d S1} - 2*{16^d S4} - {16^d S5} - {16^d S6}}
	     * kisz�m�t�sa, a {} a t�rtr�szt jel�li. A Pi hexa kifejt�s�ben a
	     * d+1. hexa jegyt�l
	     */
	    public static void main(String args[]) {
	        
	        double d16Pi = 0.0d;
	        
	        double d16S1t = 0.0d;
	        double d16S4t = 0.0d;
	        double d16S5t = 0.0d;
	        double d16S6t = 0.0d;
	        
	        int jegy = 0;
	        
	        long delta = System.currentTimeMillis();
	        
	        for(int d=100000000; d<100000001; ++d) {
	            
	            d16Pi = 0.0d;
	            
	            d16S1t = d16Sj(d, 1);
	            d16S4t = d16Sj(d, 4);
	            d16S5t = d16Sj(d, 5);
	            d16S6t = d16Sj(d, 6);
	            
	            d16Pi = 4.0d*d16S1t - 2.0d*d16S4t - d16S5t - d16S6t;
	            
	            d16Pi = d16Pi - Math.floor(d16Pi);
	            
	            jegy = (int)Math.floor(16.0d*d16Pi);
	            
	        }
	        
	        System.out.println(jegy);
	        delta = System.currentTimeMillis() - delta;
	        System.out.println(delta/1000.0);
	    }
	} 
	� 2018 GitHub, Inc.

}
