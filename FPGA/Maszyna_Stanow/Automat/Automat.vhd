library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Automat is
    Port ( I : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           O : out  STD_LOGIC);
end Automat;

architecture Behavioral of Automat is
	signal state : STD_LOGIC_VECTOR (2 downto 0);
begin
	process(CLK,RESET)
	begin
		if RESET ='1' then
			state <= "000";
			O <= '0';
		elsif rising_edge(CLK) then
			if state = "000" then --0
				if I = '0' then
					state <= "001";
				else
					state <= "000";
				end if;
				O <= '0';
			elsif state = "001" then --1
				if I = '0' then
					state <= "001";
				else
					state <= "010";
				end if;
				O <= '0';
			elsif state ="010" then --2
				if I = '0' then
					state <= "001";
				else
					state <= "011";
				end if;
				O <= '0';
			elsif state ="011" then --3
				if I = '0' then
					state <= "100";
				else
					state <= "000";
				end if;
				O <= '0';
			elsif state ="100" then --4
				if I = '0' then
					state <= "001";
				else
					state <= "000";
				end if;
				O <= '1';
			else --wystapienie bledu
				state <= "000";
				O <= '0';
			end if;
		end if;
	end process;
end Behavioral;

