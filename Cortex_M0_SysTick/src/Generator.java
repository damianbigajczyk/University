import java.awt.AWTEventMulticaster;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Generator extends Thread implements PulseSource{

	//zmienne boolowskie 
	boolean enable;
	boolean halt;
	
	byte mode;
	
	//zmienne 
	int delay;
	int ticks;	//ile ticków w czasie Burst_Mode
	int number; 
	
	ActionListener actionListener;
	
	//zaczynamy od konstruktora
	
	public Generator (boolean halt, byte mode, int delay, int ticks) {
		this.halt = halt;
		this.mode = mode; //1 - ci¹g³y 0 - przerywany
		this.delay = delay;
		this.ticks = ticks;
		number=ticks;
		enable=true;
	}
	//Tworzymy pêtle aby nasz w¹tek dzia³a³ w nieskoñczonoœæ
	
	public void run() {
		while(enable==true) {

				if(halt==true) 
				{
					//nic nie rób
					try {
						Thread.sleep(1);
					}catch(InterruptedException e) {
						e.printStackTrace();
					}
				}
				else
				{
					try {
						Thread.sleep(delay);
					}catch(InterruptedException e) {
						e.printStackTrace();
					}

					if(mode == CONTINOUS_MODE/*...1...*/) 
					{
						if(actionListener != null) //mamy s³uchacza
							actionListener.actionPerformed(new ActionEvent(this,ActionEvent.ACTION_PERFORMED,"Ci¹g³y"));
						//System.out.println("tick_CONTINOUS");
					}
					else
					{

						if(actionListener != null) //mamy s³uchacza
							actionListener.actionPerformed(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, "Przerywany"));
						if(number>1)
						{
							number--;
						}
						else if(number==1)
						{
							number=ticks;
							halt();

						}						
					}
				}
		}
	}
	
	@Override
	public void addActionListener(ActionListener pl) {
		// TODO Auto-generated method stub
		actionListener = AWTEventMulticaster.add(actionListener, pl);
	}

	@Override
	public void removeActionListener(ActionListener pl) {
		// TODO Auto-generated method stub
		actionListener = AWTEventMulticaster.remove(actionListener, pl);
	}

	@Override
	public void trigger() {
		// TODO Auto-generated method stub
		//actionListener.actionPerformed(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, "Przerywany"));
		halt=false;
	}

	@Override
	public void setMode(byte mode_2) {
		// TODO Auto-generated method stub
		mode=mode_2;
	}

	@Override
	public byte getMode() {
		// TODO Auto-generated method stub
		return mode;
	}

	@Override
	public void halt() {
		// TODO Auto-generated method stub
		halt=true;
	}
	public boolean getHalt() {
		return halt;
	}

	@Override
	public void setPulseDelay(int ms) {
		// TODO Auto-generated method stub
		delay=ms;
	}

	@Override
	public int getPulseDelay() {
		// TODO Auto-generated method stub
		return delay;
	}

	@Override
	public void setPulseCount(int burst) {
		// TODO Auto-generated method stub
		ticks = burst;
	}
	
	public int getPulseCount() {
		return ticks;
	}
	public int getNumber() {
		return number;
	}
	public boolean killThread() {
		enable = false;
		return enable;
	}

}
