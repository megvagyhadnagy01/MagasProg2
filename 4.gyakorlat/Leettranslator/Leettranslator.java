package leettranslator;

import java.io.*;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toSet;

public class Leettranslator {

    static String readFile(String path, Charset encoding) throws IOException {
        byte[] encoded = Files.readAllBytes(Paths.get(path));
        return new String(encoded, encoding);
    }
    
    static String translator(String text) {
        //Számok
        if (text.contains("o")) {
            text = text.replace('o','0');
        }
        if (/*text.contains("i") || */text.contains("l")) {
            /*text = text.replace('i','1');*/
            text = text.replace('l','1');
        }
        if (text.contains("z")) {
            text = text.replace('z','2');
        }
        if (text.contains("e")) {
            text = text.replace('e','3');
        }
        if (text.contains("a")) {
            text = text.replace('a','4');
        }
        /*if (text.contains("s")) {
            text = text.replace('s','5');
        }*/
        if (text.contains("g")) {
            text = text.replace('g','6');
        }
        if (text.contains("t")) {
            text = text.replace('t','7');
        }
        if (text.contains("b")) {
            text = text.replace('b','8');
        }
        
        //Egyéb
        if (text.contains("c")) {
            text = text.replace('c','(');
        }
        if (text.contains("s")) {
            text = text.replace('s','$');
        }
        if (text.contains("i")) {
            text = text.replace('i','!');
        }
        return text;      
    }
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Kérem a fálj nevét: ");
        String fileName = scanner.nextLine();
        String fullFileContents = readFile(fileName,StandardCharsets.UTF_8);  
        System.out.println("File beolvasva.");
        fullFileContents = fullFileContents.toLowerCase();
        fullFileContents = translator(fullFileContents);
        System.out.println("File lefordítva.");
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        writer.print(fullFileContents);
        writer.close();
        System.out.println("A fordított szöveg az output.txt-ben megtalálható.");
    }
    
}
