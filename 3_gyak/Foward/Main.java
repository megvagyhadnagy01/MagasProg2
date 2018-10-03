import java.io.*;

class Main {

  public static void main(String[] args) {
	try{	
	if(args.length != 2){
		System.err.println("Hib�s argumentumsz�m");
		System.exit(-1);
	}
	
	FileReader inputStream = new FileReader(args[0]);
	
	int j;
	boolean inComment = false;
	char i;
	BinTree bt = new BinTree();
	
	while((j = inputStream.read()) != -1){
		
		i = (char)j;
		
		if(i == '>'){
			inComment = true;
			continue;
		}
		
		if(i == '\n'){
			inComment = false;
			continue;
		}
		
		if(inComment)
			continue;
		
		if(i == 'N')
			continue;
		
		for(int k = 0;k < 8; k++){
			
			if((i & 0x80) == 0x80)
				bt.write('1');
			else
				bt.write('0');
			
			i <<= 1;
		}
		
	}
	
	inputStream.close();
	PrintWriter pw = new PrintWriter(new FileWriter(args[1]));
	
	bt.writeOut(bt.getRoot(), pw);
	pw.println("M�lys�g: "+bt.getMelyseg());
    pw.println("�tlag: " + bt.getAtlag());
    pw.println("Sz�r�s: " + bt.getSzoras());
	pw.close();
	} catch(IOException e)
	{	
	}
  }

}