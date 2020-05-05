library IEEE;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_1164.ALL;

entity Counter is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           EN : in  STD_LOGIC;
           DIR : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           SET : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (7 downto 0));
end Counter;

architecture Behavioral of Counter is
	signal QT : STD_LOGIC_VECTOR (7 downto 0);
begin

	process (EN, CLK, RESET)
	begin
		if EN = '1' then
			if RESET = '1' then
				QT <= x"00";
			elsif rising_edge(CLK)then
				if SET = '1' then
					QT <= X;
				else
					if DIR = '1' then
						QT <= QT+1;
					else
						QT <= QT-1;
					end if;
				end if;
			end if;	
		end if;
	end process;
	
	Q <= QT;
	
end Behavioral;

