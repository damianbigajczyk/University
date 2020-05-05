library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SUM1B is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           CIN : in  STD_LOGIC;
           y : out  STD_LOGIC;
           COUT : out  STD_LOGIC);
end SUM1B;

architecture Behavioral of SUM1B is

begin
	y <= A xor B xor CIN;
	COUT <= (B and A) or (CIN and A) or (CIN and B);
end Behavioral;

