LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

 
ENTITY TEST IS
END TEST;
 
ARCHITECTURE behavior OF TEST IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Sterownik_wyswietlacza_LED
    PORT(
         X0 : IN  std_logic_vector(3 downto 0);
         X1 : IN  std_logic_vector(3 downto 0);
         X2 : IN  std_logic_vector(3 downto 0);
         X3 : IN  std_logic_vector(3 downto 0);
         DP : IN  std_logic_vector(3 downto 0);
         EN : IN  std_logic;
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         SEG : OUT  std_logic_vector(7 downto 0);
         AN : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X0 : std_logic_vector(3 downto 0) := (others => '0');
   signal X1 : std_logic_vector(3 downto 0) := (others => '0');
   signal X2 : std_logic_vector(3 downto 0) := (others => '0');
   signal X3 : std_logic_vector(3 downto 0) := (others => '0');
   signal DP : std_logic_vector(3 downto 0) := (others => '0');
   signal EN : std_logic := '0';
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';

 	--Outputs
   signal SEG : std_logic_vector(7 downto 0);
   signal AN : std_logic_vector(3 downto 0);

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Sterownik_wyswietlacza_LED PORT MAP (
          X0 => X0,
          X1 => X1,
          X2 => X2,
          X3 => X3,
          DP => DP,
          EN => EN,
          CLK => CLK,
          RESET => RESET,
          SEG => SEG,
          AN => AN
        );
   process
   begin
	EN <= '1';
	RESET <= '1';
	wait for 50 ns;
	RESET <= '0';
	X0 <= "1111";
	X1 <= "1010";
	X2 <= "0111";
	X3 <= "0010";
	wait;
	   end process;
 
   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for 20 ns;
		CLK <= '1';
		wait for 20 ns;
   end process;
 

END;
