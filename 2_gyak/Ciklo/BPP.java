package bbp;
public class BPP {


	                                                            /* Ciklomatikus komplexit�s (predik�tumokkal sz�molva) */
	    
	    String d16PiHexaJegyek;
	    
	    public BBP (int d) {                                                        /* BBP f�ggv�ny */
	        double d16Pi = 0.0;
	        double d16Pi1 = sum(d, 1);
	        double d16Pi4 = sum(d, 4);
	        double d16Pi5 = sum(d, 5);
	        double d16Pi6 = sum(d, 6);
	        
	        d16Pi = 4 * d16Pi1 - 2 * d16Pi4 - d16Pi5 - d16Pi6;
	        d16Pi = d16Pi - StrictMath.floor(d16Pi);
	        
	        StringBuffer sb = new StringBuffer();
	        
	        Character hexa[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	        
	        while (d16Pi != 0.0) {                                                  /* +1 */ 
	            int szamjegy = (int)StrictMath.floor(16*d16Pi);
	            if (szamjegy < 10) {                                                /* +1 */
	                sb.append(szamjegy);
	            }
	            else {
	                sb.append(hexa[szamjegy-10]);
	            }
	            d16Pi = 16*d16Pi - (int)StrictMath.floor(16*d16Pi);
	        }
	        d16PiHexaJegyek = sb.toString();                                        /* �sszesen: 2 */
	    }
	    
	    /*
	    r = (b ^ n) mod k
	    */
	    public long mod(int n, int k) {                                             /* mod f�ggv�ny */
	        int t = 1;
	        int b = 16;
	        long r = 1;
	        while (t <= n) {                                                        /* +1 */
	            t = t * 2;
	        }
	        while(true) {                                                           /* +1 */
	            
	            if(n >= t) {                                                        /* +1 */
	                r = (b * r) % k;
	                n = n - t;
	            }
	            
	            t = t / 2;
	            
	            if (t >= 1) {                                                       /* +1 */
	                r = (r * r) % k;
	            }
	            else {
	                break;
	            }
	            
	        }
	        return r;                                                               /* �sszesen: 4 */
	    }
	    
	    public double sum(int d, int j){                                            /* sum f�ggv�ny */
	        double sum = 0.0;
	        for (int k = 0; k <= d; k++) {                                          /* +1 */
	            sum += (double)(mod(d - k, 8 * k + j)) / (double)(8 * k + j);
	        }
	        for (int k = (int) (d + 1); k <= 2 * d; k++) {                          /* +1 */
	            sum += (StrictMath.pow(16, d - k)) / (double)(8 * k + j);
	        }
	        return sum - StrictMath.floor(sum);                                     /* �sszesen: 2 */
	    }
	    
	    public String toString() {
	        
	        return d16PiHexaJegyek;
	    }

	    public static void main(String args[]) {                                    /* a teljes program ciklomatikus komplexit�sa: */
	        System.out.print(new BBP(1000000));                                     /* 2 + 4 + 2 + 1 = 9 */
	}
	}

}
