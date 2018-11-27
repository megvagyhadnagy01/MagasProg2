package i334d;


	import java.io.BufferedReader;
	import java.io.FileReader;
	import java.util.Random;
	import java.util.Scanner;

	public class l334d1c4 {
	private static String[] LeetAbc= new String[36];
	private static Random rand= new Random();
	    public static void main(String[] args) throws Exception{
	        BufferedReader br = new BufferedReader(new FileReader("input2.txt"));
	        for(int i=0;i<LeetAbc.length;i++){
	            LeetAbc[i]= br.readLine();
	            //System.out.println(LeetAbc[i]);
	        }
	        br.close();
	        System.out.println("Irja be amit at akar forditani");
	        Scanner scanner = new Scanner(System.in);
	        String FromSt= scanner.nextLine();
	        FromSt = FromSt.toUpperCase();
	        String Res="";
	        for (int i = 0; i < FromSt.length() ; i++) {
	            if(FromSt.charAt(i)!=' ') Res+= changeLetter(FromSt.charAt(i));
	            else Res+= ' ';
	        }
	        System.out.println("EREDMENY:----------------");
	        System.out.println(Res);
	    }
	    private static String changeLetter( char ToChange ) {
	        int i=0;
	        String[] Chosefrom;
	        while (true){
	            if(i==LeetAbc.length ) {
	                String OtherCharacter = "" + ToChange;
	                return OtherCharacter;
	            }
	            if(LeetAbc[i].charAt(0)== ToChange ){
	                Chosefrom= LeetAbc[i].split(" ");
	                break;
	            }
	            i++;
	        }
	        if(Chosefrom.length>2) return Chosefrom[ rand.nextInt( (Chosefrom.length-1) )+1 ];
	        else return Chosefrom[1];
	    }

	}


