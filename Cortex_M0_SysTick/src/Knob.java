
import java.awt.AWTEventMulticaster;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JComponent ;

public class Knob extends JComponent implements MouseListener, MouseMotionListener{
	private static final long serialVersionUID = 1L;
	Color knobColor;
	Color ovalColor;
	Color insideColor;
	Color backgroundColor;
	
	//zmienna do mapowania
	int value;
	
	//zmienne do uchwytu
	int knobX;
	int knobY;
	int knobRadious;
	
	//zmienne do wyœwietlacza
	int insideX;
	int insideY;
	int insideRadious;
	
	Boolean ifPress=false;
	Dimension d;
	int radious;
	
	//zmienne potrzebne do poprawnego dzia³ania
	
	int value_max; //zmienne które ca³y czas s¹ dostarczane
	int alfa;
	int true_value; //zmienne które maj¹ byæ uznane gdy puœcimy mysz 
	int true_alfa;
	int positionX;
	int positionY;
	
	double sin_alfa;
	double cos_alfa;
	
	String RVR;
	int courier; //rozmiar czcionki na wyœwietlaczu
	
	ActionListener actionListener;
	
// Zaczynamy od konstruktorów, pierwszy aby szybciej tworzyæ	
	public Knob(){
		this(0);
	}
	
	public Knob(int value){
		this.value=value;
		this.knobColor=Color.red;
		this.ovalColor=Color.blue;
		this.insideColor=Color.white;
		this.backgroundColor=Color.gray;
		this.addMouseListener(this);
		this.addMouseMotionListener(this);
		
		//zerujemy dane
		value_max = 0;
		courier = 0;
		sin_alfa = 0;
		cos_alfa = 0;
		radious = 0;
		positionX = 0;
		positionY = 0;
	}

    private void paintKnob(Graphics g, Dimension d, int tempAlfa, int tempValue_max) {

        radious = Math.min(d.width, d.height) / 2;
        courier = radious / 5;

		//tworzymy wiêkszy okr¹g
		g.setColor(ovalColor);
		g.fillOval(d.width/2-radious, d.height/2-radious, 2*radious, 2*radious);
		g.setColor(knobColor);
		
		//tworzymy wewnêtrzny okr¹g do wyœwietlania napisu
		g.setColor(insideColor);
		insideRadious=radious/10;
		insideX=d.width/2;
		insideY=d.height/2;
		g.fillOval(insideX-(2*insideRadious), insideY-(2*insideRadious), 4*insideRadious, 4*insideRadious);
		
		//napis na wyœwietlaczu
        if (value != 0) {
            RVR = String.valueOf(tempValue_max);
        } else RVR = String.valueOf(tempAlfa);

        g.setColor(Color.BLACK);
        g.setFont(new Font("Courier", Font.PLAIN, courier));
        g.drawString(RVR, insideX-insideRadious-6, insideY+insideRadious-2);

        //tworzymy uchwyt
        sin_alfa = -Math.sin(Math.toRadians(tempAlfa));
        cos_alfa = -Math.cos(Math.toRadians(tempAlfa));
        knobRadious = 3*radious / 10;
        knobX = (int) (radious/1.25 * cos_alfa + d.width/2-knobRadious/2);
        knobY = (int) (radious/1.25 * sin_alfa + d.height/2-knobRadious/2);
       
        g.setColor(knobColor);
        g.fillOval((knobX), (knobY), knobRadious, knobRadious);

    }
    
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        d = getSize();  
            true_alfa = alfa;
            true_value = value_max;
            paintKnob(g, d, true_alfa, true_value); 
    }
    
   private int countAlfa() {
        double alfa;

        positionY = (d.height / 2 - positionY);
        positionX = (d.width / 2 - positionX);
        alfa = Math.atan2(positionY, positionX);

        //zabezpieczenie przed ujemn¹ wartoœci¹
        alfa = Math.toDegrees(alfa);
        if (alfa < 0)
            alfa = alfa + 360;
        
        return (int) (alfa);
    }
/***********************************************************************/
    public int getValue_max() {
        return true_value;
    }
/***********************************************************************/
    public int getAlfa() {
        return true_alfa;
    }
/***********************************************************************/
	@Override
	public void mouseDragged(MouseEvent arg0) {
        if (ifPress) {
            positionX = arg0.getX();
            positionY = arg0.getY();
            alfa = countAlfa();
            value = (alfa * value_max / 360);
            repaint();
        }
	}
/***********************************************************************/
	@Override
	public void mouseMoved(MouseEvent arg0) {
	}
	@Override
	public void mouseClicked(MouseEvent arg0) {
	}
	@Override
	public void mouseEntered(MouseEvent arg0) {
	}
	@Override
	public void mouseExited(MouseEvent arg0) {		
	}
/*****************************************************************/
	@Override
    public void mousePressed(MouseEvent arg0) {
        Point p = arg0.getPoint();
        if (p.distance(knobX  , knobY  ) < knobRadious) {
            ifPress = true;
        }
    }
/******************************************************************/
	@Override
    public void mouseReleased(MouseEvent arg0) {
        ifPress = false;
        true_value = value_max;
        true_alfa = alfa;
        actionListener.actionPerformed(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, "Przekaż"));
    }
/*****************************************************************/
    public void addActionListener(ActionListener pl) {
        actionListener = AWTEventMulticaster.add(actionListener, pl);
    }

    public void removeActionListener(ActionListener pl) {
        actionListener = AWTEventMulticaster.remove(actionListener, pl);
    }
}
