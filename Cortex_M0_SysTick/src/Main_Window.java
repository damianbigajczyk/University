import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFormattedTextField;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class Main_Window extends JPanel implements ActionListener {

	private static final long serialVersionUID = 1L;
	private TitledBorder titleTimer;
	private TitledBorder titleGenerator;
	private TitledBorder titleBottom;
	private Border blacklineTimer;
	private Border blacklineGenerator;
	private Border blacklineBottom;
	
	//panele
	private JPanel topPanel, bottomPanel;
	private JPanel timer;
	private JPanel generator;
	
	//Timer
	
	private JCheckBox checkCountflag, checkClksource, checkTickint, checkEnable;
	private Label lRVR, lCVR, lInterrupt, lCSR;
	private JTextField tRVR, tCVR, tInterrupt, tCSR;
	
	private Knob knob;
	private Cortex_M0_SysTick systick;
	private Generator g;
	
	//Generator
	
	private JButton buttonWork, buttonMode, buttonSource;
	private JSpinner spinnerDelay, spinnerTicks;
	private Label lWork, lMode, lSource, lDelay, lTicks;
	private JTextField tWork, tMode, tSource, tDelay, tTicks;
	
	private boolean gen_source;
	private int gen_delay;
	private int gen_ticks;
	
	private JButton Check_CSR;
	private JButton Jtick;
	
	public Main_Window() {
		
		knob = new Knob();
		Check_CSR = new JButton();
		Check_CSR.setText("Check CSR");
		Check_CSR.setBackground(Color.yellow);
		Jtick = new JButton();
		Jtick.setText("Tick");
		Jtick.setBackground(Color.white);
		
		//Panele
		//JPanel okno = new JPanel();
		
		topPanel = new JPanel();
		topPanel.setLayout(new BorderLayout());
		//topPanel.setPreferredSize(new Dimension(500,200));
		//topPanel.setBackground(new Color(250,180,25));
		
		
		bottomPanel = new JPanel();
		bottomPanel.setLayout(new GridLayout(1,3));
		bottomPanel.setBackground(new Color(255,30,0));
		bottomPanel.setPreferredSize(new Dimension(500,400));
		blacklineBottom = BorderFactory.createLineBorder(Color.black);
		titleBottom = BorderFactory.createTitledBorder(blacklineBottom, "Knob");
		titleBottom.setTitleJustification(TitledBorder.CENTER);
		bottomPanel.setBorder(titleBottom);
		
		timer = new JPanel();
		timer.setLayout(new GridLayout(3,4));
		timer.setBackground(new Color(255,180,0));
		//timer.setPreferredSize(new Dimension(500,100));
		blacklineTimer = BorderFactory.createLineBorder(Color.black);
		titleTimer = BorderFactory.createTitledBorder(blacklineTimer, "Timer");
		titleTimer.setTitleJustification(TitledBorder.CENTER);
		timer.setBorder(titleTimer);
		
		generator = new JPanel();
		generator.setLayout(new GridLayout(3,5));
		generator.setBackground(new Color(0,180,255));
		//generator.setPreferredSize(new Dimension(500,100));
		blacklineGenerator = BorderFactory.createLineBorder(Color.black);
		titleGenerator = BorderFactory.createTitledBorder(blacklineGenerator, "Generator");
		titleGenerator.setTitleJustification(TitledBorder.CENTER);
		generator.setBorder(titleGenerator);
		
		//timer
		checkCountflag = new JCheckBox();
		checkCountflag.setBackground(Color.WHITE);
		checkCountflag.setHorizontalAlignment(JCheckBox.CENTER);
		checkCountflag.setText("Countflag");
		checkClksource = new JCheckBox();
		checkClksource.setBackground(Color.WHITE);
		checkClksource.setHorizontalAlignment(JCheckBox.CENTER);
		checkClksource.setText("Clksource");
		checkTickint = new JCheckBox();
		checkTickint.setBackground(Color.WHITE);
		checkTickint.setHorizontalAlignment(JCheckBox.CENTER);
		checkTickint.setText("TickInt");
		checkEnable = new JCheckBox();
		checkEnable.setBackground(Color.WHITE);
		checkEnable.setHorizontalAlignment(JCheckBox.CENTER);
		checkEnable.setText("Enable");
		
		lRVR = new Label("RVR");
		lRVR.setAlignment(WIDTH);
		lCVR = new Label("CVR");
		lCVR.setAlignment(WIDTH);
		lInterrupt = new Label("Interrupt");
		lInterrupt.setAlignment(WIDTH);
		lCSR = new Label("CSR");
		lCSR.setAlignment(WIDTH);
		
		tRVR = new JTextField();
		tRVR.setBackground(Color.WHITE);
		tRVR.setHorizontalAlignment(JTextField.CENTER);
		tRVR.setEditable(false);
		tCVR = new JTextField();
		tCVR.setHorizontalAlignment(JTextField.CENTER);
		tCVR.setBackground(Color.WHITE);
		tCVR.setEditable(false);
		tInterrupt = new JTextField();
		tInterrupt.setBackground(Color.WHITE);
		tInterrupt.setHorizontalAlignment(JTextField.CENTER);
		tInterrupt.setEditable(false);
		tCSR = new JTextField();
		tCSR.setBackground(Color.WHITE);
		tCSR.setHorizontalAlignment(JTextField.CENTER);
		tCSR.setEditable(false);
		
		timer.add(checkCountflag);
		timer.add(checkClksource);
		timer.add(checkTickint);
		timer.add(checkEnable);
		
		timer.add(lRVR);
		timer.add(lCVR);
		timer.add(lInterrupt);
		timer.add(lCSR);
		
		timer.add(tRVR);
		timer.add(tCVR);
		timer.add(tInterrupt);
		timer.add(tCSR);
		
		//generator
		buttonWork = new JButton("Start");
		buttonWork.setBackground(Color.green);
		buttonMode = new JButton("Continuous");
		buttonMode.setBackground(Color.green);
		buttonSource = new JButton("Internal");
		buttonSource.setBackground(Color.red);
		spinnerDelay = new JSpinner();
		spinnerDelay.setModel(new SpinnerNumberModel(100,0,1000,10));
		spinnerDelay.setEditor(new JSpinner.NumberEditor(spinnerDelay,"0000"));
		//JFormattedTextField txt1 = ((JSpinner.NumberEditor) spinnerDelay.getEditor()).getTextField();
		
		spinnerTicks = new JSpinner();
		spinnerTicks.setModel(new SpinnerNumberModel(5,0,100,1));
		spinnerTicks.setEditor(new JSpinner.NumberEditor(spinnerTicks,"000"));
		//JFormattedTextField txt2 = ((JSpinner.NumberEditor) spinnerDelay.getEditor()).getTextField();
		lWork = new Label("State");
		lWork.setAlignment(WIDTH);
		lMode = new Label("Mode");
		lMode.setAlignment(WIDTH);
		lSource = new Label("Source");
		lSource.setAlignment(WIDTH);
		lDelay = new Label("Delay");
		lDelay.setAlignment(WIDTH);
		lTicks = new Label("Ticks");
		lTicks.setAlignment(WIDTH);
		
		tWork = new JTextField();
		tWork.setBackground(Color.WHITE);
		tWork.setHorizontalAlignment(JTextField.CENTER);
		tWork.setText("Halt");
		tWork.setForeground(Color.red);
		tWork.setEditable(false);
		tMode = new JTextField();
		tMode.setBackground(Color.WHITE);
		tMode.setHorizontalAlignment(JTextField.CENTER);
		tMode.setText("Burst");
		tMode.setForeground(Color.red);
		tMode.setEditable(false);
		tSource = new JTextField();
		tSource.setText("External");
		tSource.setForeground(Color.green);
		tSource.setHorizontalAlignment(JTextField.CENTER);
		tSource.setBackground(Color.WHITE);
		tSource.setEditable(false);
		tDelay = new JTextField();
		tDelay.setBackground(Color.WHITE);
		tDelay.setHorizontalAlignment(JTextField.CENTER);
		tDelay.setEditable(false);
		tTicks = new JTextField();
		tTicks.setBackground(Color.WHITE);
		tTicks.setHorizontalAlignment(JTextField.CENTER);
		tTicks.setEditable(false);
		
		generator.add(buttonWork);
		generator.add(buttonMode);
		generator.add(buttonSource);
		generator.add(spinnerDelay);
		generator.add(spinnerTicks);
		
		generator.add(lWork);
		generator.add(lMode);
		generator.add(lSource);
		generator.add(lDelay);
		generator.add(lTicks);
		
		generator.add(tWork);
		generator.add(tMode);
		generator.add(tSource);
		generator.add(tDelay);
		generator.add(tTicks);
		
		bottomPanel.add(knob);
		bottomPanel.add(Check_CSR);
		bottomPanel.add(Jtick);
		
		topPanel.add(timer,BorderLayout.SOUTH);
		topPanel.add(generator,BorderLayout.NORTH);
		this.setLayout(new BorderLayout());
		this.setBackground(Color.white);
		add(topPanel,BorderLayout.NORTH);
		add(bottomPanel,BorderLayout.SOUTH);
		
		gen_source = false;
		gen_delay = 100;
		gen_ticks = 5;
		
		g = new Generator(true, (byte)(0),gen_delay,gen_ticks);
		g.start();
		
		systick = new Cortex_M0_SysTick();
		
        tRVR.setText(String.valueOf(systick.getRVR()));
        tCVR.setText(String.valueOf(systick.getCVR()));
        systick.setCVR(1);
        tDelay.setText(String.valueOf(gen_delay));
        tTicks.setText(String.valueOf(gen_ticks));
/*****************************************************************************/
        g.addActionListener(new ActionListener() {
        	
            public void actionPerformed(ActionEvent e) {

                if (gen_source== true) {
                    systick.tickInternal();
                } 
                else if(gen_source==false)
                    {systick.tickExternal();}
                	System.out.println("Tick");
                	
                if (systick.isInterrupt()) {
                	tInterrupt.setForeground(Color.green);
                    tInterrupt.setText("Interrupt");
                    System.out.println("Przerwanie");
                } else {
                	tInterrupt.setForeground(Color.RED);
                    tInterrupt.setText("Nothing");
                }
                
                tCVR.setText(String.valueOf(systick.getCVR()));
                tTicks.setText(String.valueOf(g.getPulseCount()));
                if(g.getMode()==0)
                {
                	if(g.getNumber()==1)
                	{
                		buttonWork.setBackground(Color.green);
                    	buttonWork.setText("Start");
                    	tWork.setText("Halt");
                    	tWork.setForeground(Color.red);
                	}
                }

            }
        });
/*******************************************************************************/        
        buttonWork.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                if(g.getHalt())
                {
                	
                	buttonWork.setBackground(Color.red);
                	buttonWork.setText("Halt");
                	tWork.setText("Start");
                	tWork.setForeground(Color.green);
                	
                	g.trigger();
                }
                else 
                {
        	
                	buttonWork.setBackground(Color.green);
                	buttonWork.setText("Start");
                	tWork.setText("Halt");
                	tWork.setForeground(Color.red);
                	
                	g.halt();
  	
                }
            }
        });
/*****************************************************************************/	   	
        buttonMode.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                if (g.getMode() == 0) {
                	buttonMode.setBackground(Color.red);
                    buttonMode.setText("Burst");
                	tMode.setForeground(Color.green);
                	tMode.setText("Continous");
                	

                    g.setMode((byte) (1));   
                } 
                else {
                	buttonMode.setBackground(Color.green);
                    buttonMode.setText("Continous");
                    tMode.setForeground(Color.red);
                	tMode.setText("Burst");
                	
                	
                    g.setMode((byte) (0));
                }
            }
        });
/*****************************************************************************/ 
        buttonSource.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                if (gen_source==true) {  
                	
                	buttonSource.setBackground(Color.red);
                    buttonSource.setText("Internal");
                    tSource.setForeground(Color.green);
                    tSource.setText("External");
                    gen_source = false;
                } else {
                	
                	buttonSource.setBackground(Color.green);
                    buttonSource.setText("External");
                    tSource.setForeground(Color.red);
                    tSource.setText("Internal");
                    gen_source = true;
                }
            }
        });
/*****************************************************************************/
        spinnerDelay.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                g.setPulseDelay((Integer) spinnerDelay.getValue());
                tDelay.setText(String.valueOf(g.getPulseDelay()));
            }
        });
/*****************************************************************************/
        spinnerTicks.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                g.setPulseCount((Integer) spinnerTicks.getValue());
                tTicks.setText(String.valueOf(g.getPulseCount()));
            }
        });
/*****************************************************************************/
        checkCountflag.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                if(checkCountflag.isSelected()) {
                systick.setCountflag(true);
                }else systick.setCountflag(false);
            }
        });
/*****************************************************************************/
        checkClksource.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                if(checkClksource.isSelected()) {
                systick.setSource(1);
                }else systick.setSource(0);
            }
        });
/*****************************************************************************/
        checkTickint.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
               
                if(checkTickint.isSelected()) {
                systick.setInterrupt(true);
                }else systick.setInterrupt(false);
            }
        });
/*****************************************************************************/
        checkEnable.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
               
                if(checkEnable.isSelected()) {
                systick.setEnable(true);
                }else systick.setEnable(false);
            }
        });
/*****************************************************************************/
        knob.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                systick.setRVR(knob.getAlfa());
                tRVR.setText(String.valueOf(systick.getRVR()));
                if (knob.getAlfa() == 0) {
                    checkEnable.setSelected(false);
                }
            }
        });
/*****************************************************************************/
        Check_CSR.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                tCSR.setText(String.valueOf(systick.getCSR()));
                checkCountflag.setSelected(false);
            }
        });
/*****************************************************************************/
        Jtick.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                 
                if (gen_source == false) {
                    systick.tickExternal();
                } else {
                    systick.tickInternal();
                }
                if (systick.isInterrupt()) {
                	tInterrupt.setForeground(Color.green);
                    tInterrupt.setText("Interrupt");
                } else {
                	tInterrupt.setForeground(Color.RED);
                    tInterrupt.setText("Nothing");
                }
          
                tCVR.setText(String.valueOf(systick.getCVR()));
                tTicks.setText(String.valueOf(g.getPulseCount()));
            }
        });
	}
/*****************************************************************************/
    	public int get_CSR() {
    		
    		return systick.getCSR();
    	}
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}
