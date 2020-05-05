library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Sterownik_wyswietlacza_LED is
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
end Sterownik_wyswietlacza_LED;

architecture Behavioral of Sterownik_wyswietlacza_LED is
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
	
	signal QT : STD_LOGIC_VECTOR (1 downto 0);
	signal X : STD_LOGIC_VECTOR (3 downto 0);
	signal DPX : STD_LOGIC;
begin
	process(EN,RESET,CLK)
	begin
		if EN = '1' then
			if RESET = '1' then
				QT <= "00";
			elsif rising_edge(CLK) then
				if QT = "11" then
					QT <= "00";
				else
					QT <= QT + 1;
				end if;
				
				if QT = "00" then
					X <= X0;
					DPX <= DP(0);
					AN <= "1110";
				elsif QT = "01" then
					X <= X1;
					DPX <= DP(1);
					AN <= "1101";
				elsif QT = "10" then
					X <= X2;
					DPX <= DP(2);
					AN <= "1011";
				elsif QT = "11" then
					X <= X3;
					DPX <= DP(3);
					AN <= "0111";
				end if;
			end if;
		end if;
	end process;
	

	
	SEG7: BINTO7SEG port map (BIN => X, DP => DPX, EN => EN, SEG => SEG);
end Behavioral;

