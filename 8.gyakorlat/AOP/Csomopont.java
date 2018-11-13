public class Csomopont {
    private char betu;
    private Csomopont balNulla;
    private Csomopont jobbEgy;

    Csomopont(char betu) {
        this.betu = betu;
        this.balNulla = this.jobbEgy = null;
    }
    Csomopont() {
        this.betu = '/';
        this.balNulla = this.jobbEgy = null;
    }

    public Csomopont nullasGyermek() {
        return balNulla;
    }
    public Csomopont egyesGyermek() {
        return jobbEgy;
    }
    public void ujNullasGyermek(Csomopont gyerek) {
        balNulla = gyerek;
    }
    public void ujEgyesGyermek(Csomopont gyerek) {
        jobbEgy = gyerek;
    }
    public char getBetu() {
        return betu;
    }
}