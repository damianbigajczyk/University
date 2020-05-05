library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity CNT10 is
    Port ( RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           C : out  STD_LOGIC;
			  Q : out STD_LOGIC_VECTOR (3 downto 0));
end CNT10;

architecture Behavioral of CNT10 is
	signal QT: STD_LOGIC_VECTOR (3 downto 0);
	
begin
	process(RESET,CLK)
	begin
		if RESET = '1' then
			QT <= "0000";
		elsif rising_edge(CLK) then
			if QT = "1001" then
				C <= '1';
				QT <= "0000";
			else
				C <= '0';
				QT <= QT +1;
			end if;
		end if;
	end process;
	Q <= QT;

end Behavioral;

