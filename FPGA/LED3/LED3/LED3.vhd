library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity LED3 is
    Port ( CLK : in  STD_LOGIC;
           BTN0 : in  STD_LOGIC;
           LED : out  STD_LOGIC_VECTOR (7 downto 0));
end LED3;

architecture Behavioral of LED3 is
	signal CNT: std_logic_vector(26 downto 0);
begin
process(CLK, BTN0)
	begin 
		if BTN0 = '1' then
			CNT <= (others => '0');
		elsif rising_edge(CLK) then
			CNT  <= CNT +1;
		end if;
	end process;
	--LED <= CNT(26 downto 19);

end Behavioral;

