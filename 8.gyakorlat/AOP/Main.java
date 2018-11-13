import java.io.*;

public class Main {

    public static void main(String[] args)
    {
        if(args.length != 3)
            System.err.println("Usage: java Main in_file -o out_file");

        if(!args[1].equals("-o"))
            System.err.println("Usage: java Main in_file -o out_file");

        try
        {
            FileReader beFile = new FileReader(args[0]);
            LZWBinfa binFa = new LZWBinfa();

            int j;
            char i;
            boolean kommentben = false;
            while((j = beFile.read()) != -1)
            {
                i = (char)j;

                if(i == '>'){
        			kommentben = true;
        			continue;
        		}
        		if(i == '\n'){
        			kommentben = false;
        			continue;
        		}
        		if(kommentben)
        			continue;
        		if(i == 'N')
        			continue;

                for(int k = 0;k < 8; k++)
                {
            		if((i & 0x80) == 0x80)
            		      binFa.belerak('1');
            		else
            		      binFa.belerak('0');
            		i <<= 1;
                }
            }
            beFile.close();

            //kiírás
            PrintWriter kiFile = new PrintWriter(new FileWriter(args[2]));
            binFa.kiir(binFa.getGyoker(), kiFile);

            kiFile.println("depth = " + binFa.getMelyseg());
            kiFile.println("mean = " + binFa.getAtlag());
            kiFile.println("var = " + binFa.getSzoras());

            kiFile.close();
        }
        catch (IOException exception)
        {
            System.err.println("A megadott bemeneti file nem letezik...");
        }
    }
}