library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity MUL4x4 is
    Port ( X0 : in  STD_LOGIC_VECTOR (3 downto 0);
           X1 : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end MUL4x4;

architecture Behavioral of MUL4x4 is
	component SUM8B is
		Port ( CIN : in  STD_LOGIC;
           A : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0);
           COUT : out  STD_LOGIC);
	end component;
	signal Z1 : STD_LOGIC_VECTOR (7 downto 0);
	signal Z2 : STD_LOGIC_VECTOR (7 downto 0);
	signal Z3 : STD_LOGIC_VECTOR (7 downto 0);
	signal Z4 : STD_LOGIC_VECTOR (7 downto 0);
	signal Z5 : STD_LOGIC_VECTOR (7 downto 0);
	signal Z6 : STD_LOGIC_VECTOR (7 downto 0);
	signal Z7 : STD_LOGIC_VECTOR (7 downto 0);
	signal C : STD_LOGIC_VECTOR (2 downto 0);
begin
	Z1 <= "0000" & X0 when X1(0) = '1' else x"00";
	Z2 <= "000" & X0 & '0' when X1(1) = '1' else x"00"; 
	Z3 <= "00" & X0 & "00" when X1(2) = '1' else x"00";
	Z4 <= '0' & X0 & "000" when X1(3) = '1' else x"00";
	S0: SUM8B port map (A => Z1, B => Z2, CIN => '0', Y => Z5, COUT => C(0));
	S1: SUM8B port map (A => Z5, B => Z3, CIN => '0', Y => Z6, COUT => C(1));
	S2: SUM8B port map (A => Z6, B => Z4, CIN => '0', Y => Z7, COUT => C(2));
	
	y <= Z7;

end Behavioral;

