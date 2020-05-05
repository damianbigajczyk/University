
/**
 * Write a description of class Cortex_M0_SysTick here.
 * Symulator SysTick'a w Cortex_M0.
 * Wartoœci poszczególnych flag w CSR:
 *      Enable - 1;
 *      tickint - 2;
 *      Clksource - 4;
 *      Countflag - 65 536;
 * Przyk³ad u¿ycia CSR,np
 * object.setCSR(number) -> cortexM01.setCSR(65543) -> wszystkie flagi true
 * 
 * W metodzie main znajduje siê test, którego zadaniem jest sprawdzenie:
 *  -czy poszczególne metody poprawnie siê uruchamiaj¹, tzn. wtedy kiedy maj¹ pozwolenie
 *   i nie w³¹czaj¹ siê samowolnie;
 *  -czy jest podzia³ na Ÿród³a taktowania (Internal and External);
 *  -jeœli RVR ustawimy na 0, to czy timer siê wy³¹czy po osi¹gniêciu przez CVR zera?
 *  -czy obs³uga przerwania jest tylko wtedy, gdy ma na to pozwolenie (Tickint);
 *  -poprawne ustawianie i resetowanie flagi Counflag.
 * 
 * Uwaga!
 * Program powsta³ w opraciu o dokumentacjê procesora CortexM0 pobranej z oficjalnej strony producenta.
 * Pozytywnie przeszed³ szereg testów, aczkolwiek nadal mo¿e zaistnieæ b³¹d w dzia³aniu.
 * Wszelkie uwagi proszê zg³aszaæ na email: 236182@student.pwr.edu.pl, a ewentualne b³êdu 
 * zostn¹ wyeliminowane w kolejnych wersjach programu.
 * 
 *
 * @author Damian Bigajczyk
 * @version 30.10.2018r.
 */
import java.util.Random;
public class Cortex_M0_SysTick
{
        //atrybuty
        private int CVR;
        private int RVR;
        private int source;
        private boolean enable;
        private boolean tickInt;
        private boolean interruptflag;
        private boolean countflag;
        private boolean tempCountflag;
        private boolean tempInterruptflag;
        
    public Cortex_M0_SysTick(){
        Reset();
        Random r = new Random();
        RVR = r.nextInt(16777215)+1;
        CVR = r.nextInt(16777215)+1;
    }
    //SET
    public void Reset(){
        countflag = false;
        source = 0;
        interruptflag = false;
        enable = false;
    }
    public void setRVR(int a){
        RVR=(a&0xFFFFFF);
    }
    public void setCVR(int a){
        CVR=0;
        countflag = false;
    }
    public void setEnable(boolean a){
        if(a==true){
            enable = true;
        }
        else{
            enable = false;
        }
    }
    public void setSource(int a){
        if(a>0){
            source = 1;
        }
        else{
            source = 0;
        }
    }
    public void setInterrupt(boolean a){
        if(a==true){
            tickInt= true;
        }
        else{
            tickInt = false;
        }
    }
    public void setCSR(int a){
        if((a & 0x00000001)==0x00000001){
            enable=true;
        }
        else{
            enable=false;
        }
        if((a & 0x00000002)==0x00000002){
            tickInt=true;
        }
        else{
            tickInt=false;
        }
        if((a & 0x00000004)==0x00000004){
            source=1;
        }
        else{
            source=0;
        }
        if((a & 0x00010000)==0x00010000){
            countflag=true;
        }
        else{
            countflag=false;
        }
    }
    //dodatkowa
    public void setCountflag(boolean a) {

    	countflag = a;
    }
    /*
     * get
     * 
     */
    public int getRVR(){
        return RVR;
    }
    public int getCVR(){
        return CVR;
    }
    private int getEnable(){
        countflag=false;
        if(enable==true){
            return 1;
           }
        else{
            return 0;
           }
    }
    private int getInterrupt(){
        countflag=false;
        if(tickInt==true){
            return 2;
           }
        else{
            return 0;
           }
    }
    private int getSource(){
        countflag=false;
        if(source==1){
            return 4;
           }
        else{
            return 0;
           }
    }
    private int getCountflag(){
        tempCountflag = countflag;
        countflag = false;
        if(tempCountflag==true){
            return 65536;
        }
        else{
            return 0;
           }
    }
    public int getCSR(){
        int value=0;
        if(getCountflag() == 65536){
            value += 65536;
        }
        if(getEnable() == 1){
            value += 1;
        }
        if(getInterrupt() == 2){
            value += 2;
        }
        if(getSource() == 4){
            value += 4;
        }
        return value;
    }
    private void displayState(){
        System.out.println("=============================\n");
        System.out.println("RVR="+RVR+"\n");
        System.out.println("CVR="+CVR+"\n");
        System.out.println("Countfalg="+countflag+"\n");
        System.out.println("ClkSource="+source+"\n");
        System.out.println("TickInt="+tickInt+"\n");
        System.out.println("Enable="+enable+"\n");
        System.out.println("CSR="+getCSR()+"\n");
        System.out.println("was there an interruption?: "+isInterrupt());
        System.out.println("=============================\n");
    }
    private void tick(){
        if(enable==true && RVR!=0){
            if(CVR>1){
                CVR--;
            }
            else if(CVR==1){
                CVR--;
                countflag=true;
                interruptflag=true;
            }
            else if(CVR==0){
                CVR=RVR;
            }
        }
        else if(enable==true && RVR==0){
            if(CVR>1){
                CVR--;
            }
            else if(CVR==1){
                CVR--;
                countflag=true;
                interruptflag=true;
            }
            else if(CVR==0){
                enable=false;
            }
        }
    }
    public void tickInternal(){
        if(source==1){
            tick();
        }
    }
    public void tickExternal(){
        if(source==0){
            tick();
        }
    }
    public boolean isCountFlag(){
        tempCountflag = countflag;
        countflag = false;
        return tempCountflag;
    }
    public boolean isEnableFlag(){
        countflag = false;
        return enable;
    }
    public boolean isInterruptFlag(){
        countflag = false;
        return tickInt;
    }
    public boolean isInterrupt(){
        tempInterruptflag=interruptflag;
        interruptflag=false;
        if(tempInterruptflag==true && tickInt==true){
            return true;
        }
        else{
            return false;
        }
    }
  /*  public static void main(String[] args){
        Cortex_M0_SysTick cortexM01 = new Cortex_M0_SysTick();
        cortexM01.setCVR(500);
        cortexM01.setRVR(2);
        cortexM01.setEnable(true);
        cortexM01.displayState(); //(1)
        cortexM01.tickInternal();
        cortexM01.displayState(); //(2) RVR=2 CVR=0
        cortexM01.tickExternal();
        cortexM01.displayState(); //(3) RVR=2; CVR=2; interruption=false
        cortexM01.setSource(1);
        cortexM01.tickInternal();   
        cortexM01.setCSR(7);
        cortexM01.displayState(); //(4) CVR=1
        for(int i =0; i<3; i++) cortexM01.tickInternal();
        cortexM01.displayState(); //(5) CVR=1; Interruption=true
        cortexM01.setCSR(5);
        cortexM01.tickInternal();
        cortexM01.displayState(); //(6) CVR=0; Interruption=false
        cortexM01.setCSR(3);
        cortexM01.tickExternal();
        cortexM01.setRVR(0);
        cortexM01.tickExternal();
        cortexM01.displayState(); //(7) CVR=1; 
        cortexM01.tickExternal(); 
        cortexM01.displayState();//(8) CVR=0; flaga, przerwanie
        cortexM01.tickExternal();
        cortexM01.displayState(); //(9) wy³¹czenie timera
       }*/
}
