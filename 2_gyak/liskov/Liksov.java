class Madar {
    public void repul() {
        System.out.println("Rep�l.");
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
        
        Siraly siraly = new Siraly(); //szulo szulo=new gyerek() minden object referencia �s dinamikus kot�s
        siraly.repul();
        
        Pingvin pingvin = new Pingvin();
        pingvin.repul();
        
    }
    
}
