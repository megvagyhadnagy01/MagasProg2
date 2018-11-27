package prog2gyak;

//public class full {
	import java.awt.*;
	import javax.swing.JFrame;

	public class full extends JFrame {
		public static void main(String[] args) {
		
			DisplayMode dm = new DisplayMode(1920, 1080, 16, DisplayMode.REFRESH_RATE_UNKNOWN);
			full f = new full();
			f.run(dm);
			}
		
		public void run(DisplayMode dm) {
			setBackground(Color.BLUE);
			setForeground(Color.WHITE);
			setFont(new Font("Arial", Font.PLAIN, 24));
			
			screen s = new screen();
			try {
				s.setFullScreen(dm, this);
				try {
					Thread.sleep(5000);
				}catch(Exception ex) {}
			}finally {
				s.restoreScree();
			}
		}
		
		public void paint(Graphics g) {
			g.drawString("Full Screen", 875, 540);
		}
	}

