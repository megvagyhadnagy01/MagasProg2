package binfa;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ElsoTeszt {

	LZWBinfa binFa = new LZWBinfa();

	@Test
	void test() {
		
		for(char c : "01111001001001000111".toCharArray()) {
            binFa.belerak(c);
        }

        assertEquals(4, binFa.getMelyseg(), 0.000001);
        assertEquals(2.75, binFa.getAtlag(), 0.001);
        assertEquals(0.957427, binFa.getSzoras(), 0.0001);
	}
}
