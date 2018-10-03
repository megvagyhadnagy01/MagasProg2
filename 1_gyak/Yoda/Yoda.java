public class Yoda {
    private static final String asd= null;
    public static void main(String[] args) {
        if(!"asd".equals(asd)){//Yoda condititon
	    System.out.println("Yoda conditionnal nem dob hibat!");
	}
	System.out.println("Yoda condition nelkul hibat fog dobni..");
	try {
	    if(!asd.equals("asd")){
		//nem Yoda condition"
	    }

	}catch (NullPointerException e){
	    System.out.println("Nullpointer exception!");
	    e.printStackTrace();
	}

    }
}
