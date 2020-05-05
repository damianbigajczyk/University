LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Counter_test IS
END Counter_test;
 
ARCHITECTURE behavior OF Counter_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Counter
    PORT(
         RESET : IN  std_logic;
         CLK : IN  std_logic;
         C : OUT  std_logic;
         X0 : OUT  std_logic_vector(3 downto 0);
         X1 : OUT  std_logic_vector(3 downto 0);
         X2 : OUT  std_logic_vector(3 downto 0);
         X3 : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal RESET : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal C : std_logic;
   signal X0 : std_logic_vector(3 downto 0);
   signal X1 : std_logic_vector(3 downto 0);
   signal X2 : std_logic_vector(3 downto 0);
   signal X3 : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Counter PORT MAP (
          RESET => RESET,
          CLK => CLK,
          C => C,
          X0 => X0,
          X1 => X1,
          X2 => X2,
          X3 => X3
        );


   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for 10 ns;
		CLK <= '1';
		wait for 10 ns;
   end process;
 
	RESET_process :process
	begin
	RESET <= '1';
	wait for 5ns;
	RESET <= '0';
	wait;
	end process;

END;
