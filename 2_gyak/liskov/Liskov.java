
class Madar {
    public void repul() {
        System.out.println("Repül.");
    }
}

class Sas extends Madar {   
}

class Pingvin extends Madar {    
}

public class Liskov {
    public void repul() {};
    
    
    public static void main(String[] args) {
        Madar madar = new Madar();
        madar.repul();
        
        Sas sas = new Sas();
        sas.repul();
        
        Pingvin pingvin = new Pingvin();
        pingvin.repul();
        
    }
    
}
