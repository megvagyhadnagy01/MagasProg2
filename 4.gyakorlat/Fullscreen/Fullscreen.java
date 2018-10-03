import java.awt.*;
import javax.swing.*;

public class Fullscreen {

    public static void main(String[] args) {
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();

        final int screen_Width = dim.width;
        final int screen_Height = dim.height;

        JFrame frame = new JFrame();

        frame.setSize(screen_Width , screen_Height);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setUndecorated(true);
        frame.setLayout( null );

        frame.setVisible(true);
    }
}
