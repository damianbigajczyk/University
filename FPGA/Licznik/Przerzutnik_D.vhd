library IEEE;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_1164.ALL;

entity Przerzutnik_D is
    Port ( RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (7 downto 0));
end Przerzutnik_D;

architecture Behavioral of Przerzutnik_D is
	signal QT : STD_LOGIC_VECTOR (7 downto 0);
begin
	Process(CLK)
	begin 
		if rising_edge(CLK) then
			if RESET = '1' then
				QT <= x"00";
			else
				QT <= QT +1;
			end if;
		end if;
	end process;
	Q <= QT;
			

end Behavioral;

