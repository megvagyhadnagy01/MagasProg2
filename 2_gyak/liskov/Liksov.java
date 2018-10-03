class Madar {
    public void repul() {
        System.out.println("Repül.");
    }
}

class Siraly extends Madar {   
}

class Pingvin extends Madar {    
}

public class Liskov {
    public void repul() {};
    
    
    public static void main(String[] args) {
        Madar madar = new Madar();
        madar.repul();
        
        Siraly siraly = new Siraly(); //szulo szulo=new gyerek() minden object referencia és dinamikus kotés
        siraly.repul();
        
        Pingvin pingvin = new Pingvin();
        pingvin.repul();
        
    }
    
}
