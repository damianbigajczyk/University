library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity DISPDRU is
    Port ( CLK : in  STD_LOGIC;
           BTN0 : in  STD_LOGIC;
           SEG : out  STD_LOGIC_VECTOR (7 downto 0);
           AN : out  STD_LOGIC_VECTOR (3 downto 0));
end DISPDRU;

architecture Behavioral of DISPDRU is

	component SUM1B is
		Port ( CIN : in  STD_LOGIC;
           A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           COUT : out  STD_LOGIC;
           Y : out  STD_LOGIC);
	end component;
	
	component BINTO7SEG is
		Port ( BIN : in  STD_LOGIC_VECTOR (3 downto 0);
           DP : in  STD_LOGIC;
           EN : in  STD_LOGIC;
           SEG : out  STD_LOGIC_VECTOR (7 downto 0));
	end component;
	
	component Sterownik_wyswietlacza_LED is
		Port ( X0 : in  STD_LOGIC_VECTOR (3 downto 0);
           X1 : in  STD_LOGIC_VECTOR (3 downto 0);
           X2 : in  STD_LOGIC_VECTOR (3 downto 0);
           X3 : in  STD_LOGIC_VECTOR (3 downto 0);
           DP : in  STD_LOGIC_VECTOR (3 downto 0);
           EN : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           SEG : out  STD_LOGIC_VECTOR (7 downto 0);
           AN : out  STD_LOGIC_VECTOR (3 downto 0));
	end component;
	
	component CNT10 is
		Port ( RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           C : out  STD_LOGIC;
			  Q : out STD_LOGIC_VECTOR (3 downto 0));
	end component;
	
	signal CNT1: STD_LOGIC_VECTOR(19 downto 0);
	signal CNT2: STD_LOGIC_VECTOR(18 downto 0);
	signal CLK1: STD_LOGIC;
	signal CLK2: STD_LOGIC;
	signal temp: STD_LOGIC_VECTOR(2 downto 0);
	signal QT0: STD_LOGIC_VECTOR(3 downto 0);
	signal QT1: STD_LOGIC_VECTOR(3 downto 0);
	signal QT2: STD_LOGIC_VECTOR(3 downto 0);
	signal QT3: STD_LOGIC_VECTOR(3 downto 0);
	signal x: STD_LOGIC;
	
	
begin

	process(CLK)
		begin
			if rising_edge(CLK) then
				CNT1 <= CNT1 + 1;
				CNT2 <= CNT2 + 1;		
				if CNT1 = 500000 then
					CLK1 <= '0';
				else
					CLK1 <='1';
				end if ;			
				if CNT2 = 250000 then
					CLK2 <= '0';
				else 
					CLK2 <= '1';
				end if ; 
			end if;
	end process;

	C0: CNT10 port map(RESET => BTN0,CLK => CLK1,    C => temp(0), Q => QT0);
	C1: CNT10 port map(RESET => BTN0,CLK => temp(0), C => temp(1), Q => QT1);
	C2: CNT10 port map(RESET => BTN0,CLK => temp(1), C => temp(2), Q => QT2);
	C3: CNT10 port map(RESET => BTN0,CLK => temp(2), C => x,       Q => QT3);
	
	DISPDRU1: Sterownik_wyswietlacza_LED port map (X0 => QT0, X1 => QT1, X2 => QT2, X3 => QT3, DP => "0000", EN => '1',  RESET => BTN0, SEG => SEG, AN => AN, CLK => CLK2);

end Behavioral;

