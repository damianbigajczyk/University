library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Automat_2 is
    Port ( I : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           O : out  STD_LOGIC);
end Automat_2;

architecture Behavioral of Automat_2 is
	signal state : STD_LOGIC_VECTOR (2 downto 0);
	signal nstate : STD_LOGIC_VECTOR (2 downto 0); --next state

begin
	process(RESET,I,state)
	begin
		if RESET ='1' then
			nstate <= "000";
			O <= '0';
		else
			if state = "000" then --0
				if I = '0' then
					nstate <= "001";
				else
					nstate <= "000";
				end if;
				O <= '0';
			elsif state = "001" then --1
				if I = '0' then
					nstate <= "001";
				else
					nstate <= "010";
				end if;
				O <= '0';
			elsif state ="010" then --2
				if I = '0' then
					nstate <= "001";
				else
					nstate <= "011";
				end if;
				O <= '0';
			elsif state ="011" then --3
				if I = '0' then
					nstate <= "100";
				else
					nstate <= "000";
				end if;
				O <= '0';
			elsif state ="100" then --4
				if I = '0' then
					nstate <= "001";
				else
					nstate <= "000";
				end if;
				O <= '1';
			else --wystapienie bledu
				nstate <= "000";
				O <= '0';
			end if;
		end if;
	end process;
	
	process(RESET,CLK)
	begin
		if RESET = '1' then
			state <= "000";
		elsif rising_edge(CLK) then
			state <= nstate;
		end if;
	end process;
end Behavioral;

