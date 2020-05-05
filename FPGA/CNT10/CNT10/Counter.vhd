library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Counter is
    Port ( RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           C : out  STD_LOGIC;
           X0 : out  STD_LOGIC_VECTOR (3 downto 0);
			  X1 : out  STD_LOGIC_VECTOR (3 downto 0);
			  X2: out  STD_LOGIC_VECTOR (3 downto 0);
			  X3: out  STD_LOGIC_VECTOR (3 downto 0));
end Counter;

architecture Behavioral of Counter is
	component CNT10 is
	Port ( RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           C : out  STD_LOGIC;
			  Q : out STD_LOGIC_VECTOR (3 downto 0));
	end component;
	signal temp: STD_LOGIC_VECTOR(2 downto 0);
begin
	CNT10_0: CNT10 port map(RESET => RESET,CLK => CLK, C => temp(0), Q => X0);
	CNT10_1: CNT10 port map(RESET => RESET,CLK => temp(0), C => temp(1), Q => X1);
	CNT10_2: CNT10 port map(RESET => RESET,CLK => temp(1), C => temp(2), Q => X2);
	CNT10_3: CNT10 port map(RESET => RESET,CLK => temp(2), C => C , Q => X3);

end Behavioral;

