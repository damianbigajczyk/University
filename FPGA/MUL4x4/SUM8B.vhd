library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SUM8B is
    Port ( CIN : in  STD_LOGIC;
           A : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0);
           COUT : out  STD_LOGIC);
end SUM8B;

architecture Behavioral of SUM8B is
	component SUM1B is
		Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           CIN : in  STD_LOGIC;
           y : out  STD_LOGIC;
           COUT : out  STD_LOGIC);
	end component;
	signal C : STD_LOGIC_VECTOR(6 downto 0);
begin
	S0: SUM1B port map (A => A(0), B => B(0), CIN => CIN, y => Y(0), COUT => C(0));
	S1: SUM1B port map (A => A(1), B => B(1), CIN => C(0), y => Y(1), COUT => C(1));
	S2: SUM1B port map (A => A(2), B => B(2), CIN => C(1), y => Y(2), COUT => C(2));
	S3: SUM1B port map (A => A(3), B => B(3), CIN => C(2), y => Y(3), COUT => C(3));
	S4: SUM1B port map (A => A(4), B => B(4), CIN => C(3), y => Y(4), COUT => C(4));
	S5: SUM1B port map (A => A(5), B => B(5), CIN => C(4), y => Y(5), COUT => C(5));
	S6: SUM1B port map (A => A(6), B => B(6), CIN => C(5), y => Y(6), COUT => C(6));
	S7: SUM1B port map (A => A(7), B => B(7), CIN => C(6), y => Y(7), COUT => COUT);

end Behavioral;

