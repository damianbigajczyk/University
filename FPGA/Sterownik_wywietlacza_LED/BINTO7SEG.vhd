library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity BINTO7SEG is
    Port ( BIN : in  STD_LOGIC_VECTOR (3 downto 0);
           DP : in  STD_LOGIC;
           EN : in  STD_LOGIC;
           SEG : out  STD_LOGIC_VECTOR (7 downto 0));
end BINTO7SEG;

architecture Behavioral of BINTO7SEG is

begin
	SEG <= 
			"11111111" when EN = '0' else

			not DP & "1000000" when (BIN = "0000") else
			not DP & "1111001" when (BIN = "0001") else
			not DP & "0100100" when (BIN = "0010") else
			not DP & "0110000" when (BIN = "0011") else
			not DP & "0011001" when (BIN = "0100") else
			not DP & "0010010" when (BIN = "0101") else
			not DP & "0000010" when (BIN = "0110") else
			not DP & "1111000" when (BIN = "0111") else
			not DP & "0000000" when (BIN = "1000") else
			not DP & "0010000" when (BIN = "1001") else
			
			not DP & "0001000" when (BIN = "1010")  else
			not DP & "0000011" when (BIN = "1011")  else
			not DP & "1000110" when (BIN = "1100")  else
			not DP & "0100001" when (BIN = "1101")  else
			not DP & "0000110" when (BIN = "1110")  else
			not DP & "0001110" when (BIN = "1111");
			
end Behavioral;

