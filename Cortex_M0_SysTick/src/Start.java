import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JFrame;

public class Start extends JFrame {

	private static final long serialVersionUID = 1L;
	
	public Start() {
		super("Cortex_M0_SysTick");

		Main_Window okno = new Main_Window();
		okno.setVisible(true);
		//okno.setPreferredSize(new Dimension(600,400));
		add(okno);
		//okno.setBackground(new Color(0,100,0));
		pack();
		//this.setSize(new Dimension(600,650));
		this.setBackground(Color.white);
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {

		new Start();
	}
}
