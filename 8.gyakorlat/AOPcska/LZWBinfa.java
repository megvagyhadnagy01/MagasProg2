public class LZWBinfa {
    private final Csomopont gyoker; //konstans
    private Csomopont fa; //aktuális csomópont
    private int melyseg, maxMelyseg, atlagosszeg, atlagdb;
    private double atlag, szorasosszeg, szoras;

    LZWBinfa() {
        gyoker = new Csomopont();
        fa = gyoker;
    }

    public Csomopont getGyoker() { //ez kellett mert nem tudjuk elérni a gyökeret a Main.javaból
        return gyoker;
    }

    public void kiir(Csomopont elem, java.io.PrintWriter pw)
    {
        if (elem != null)
        {
            ++melyseg;
            kiir(elem.egyesGyermek(), pw);

            for (int i=0; i<melyseg; ++i)
                pw.print("---");

            pw.println(elem.getBetu() + "(" + (melyseg - 1) + ")");

            kiir(elem.nullasGyermek(), pw);
            --melyseg;
        }
    }

    public void belerak(char b) {
        if(b == '0') {
            if(fa.nullasGyermek() == null) {
                fa.ujNullasGyermek(new Csomopont('0'));
                fa = gyoker;
            }
            else {
                fa = fa.nullasGyermek();
            }
        }
        else {
            if(fa.egyesGyermek() == null) {
                fa.ujEgyesGyermek(new Csomopont('1'));
                fa = gyoker;
            }
            else {
                fa = fa.egyesGyermek();
            }
        }
    }

    public int getMelyseg() {
        melyseg = maxMelyseg = 0;
        rmelyseg(gyoker);
        return maxMelyseg - 1;
    }
    private void rmelyseg(Csomopont elem) {
        if(elem != null) {
            ++melyseg;
            if(melyseg > maxMelyseg) maxMelyseg = melyseg;
            rmelyseg(elem.egyesGyermek());
            rmelyseg(elem.nullasGyermek());
            --melyseg;
        }
    }
    public double getAtlag() {
        melyseg = atlagosszeg = atlagdb = 0;
        ratlag(gyoker);
        atlag = ((double) atlagosszeg) / atlagdb;
        return atlag;
    }
    private void ratlag(Csomopont elem) {
        if(elem != null) {
            ++melyseg;
            ratlag(elem.egyesGyermek());
            ratlag(elem.nullasGyermek());
            --melyseg;
            if(elem.egyesGyermek() == null && elem.nullasGyermek() == null) {
                ++atlagdb;
                atlagosszeg += melyseg;
            }
        }
    }
    public double getSzoras() {
        atlag = this.getAtlag();
        szorasosszeg = 0.0;
        melyseg = atlagdb = 0;
        rszoras(gyoker);
        if(atlagdb-1>0) szoras = Math.sqrt(szorasosszeg / (atlagdb - 1));
        else szoras = Math.sqrt(szorasosszeg);
        return szoras;
    }
    private void rszoras(Csomopont elem) {
        if(elem != null) {
            ++melyseg;
            rszoras(elem.egyesGyermek());
            rszoras(elem.nullasGyermek());
            --melyseg;
            if(elem.egyesGyermek() == null && elem.nullasGyermek() == null) {
                ++atlagdb;
                szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));
            }
        }
    }
}