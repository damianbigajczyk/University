library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Koder_NRZI is
    Port ( I : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           O : out  STD_LOGIC);
end Koder_NRZI;

architecture Behavioral of Koder_NRZI is
		signal state : STD_LOGIC;
begin
	process(CLK,RESET)
	begin
		if RESET ='1' then
			state <= '0';
			O <= '0';
		elsif rising_edge(CLK) then
			if state = '0'; then --0
				if I = '0' then
					state <= '1';
				else
					state <= '0';
				end if;
				O <= '1';
			elsif state = "001" then --1
				O <= "0101";
				state <= "010";
			elsif state ="010" then --2
				O <= "0100";
				state <= "011";
			elsif state ="011" then --3
				O <= "0010";
				state <= "100";
			elsif state ="100" then --4
				if I = '0' then
					state <= "000";
				else
					state <= "001";
				end if;
				O <= "0011";
			else --wystapienie bledu
				state <= "000";
				O <= "1111";
			end if;
		end if;
	end process;

end Behavioral;

