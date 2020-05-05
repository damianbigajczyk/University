LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Automat_2_TEST IS
END Automat_2_TEST;
 
ARCHITECTURE behavior OF Automat_2_TEST IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Automat_2
    PORT(
         I : IN  std_logic;
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         O : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal I : std_logic := '0';
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';

 	--Outputs
   signal O : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Automat_2 PORT MAP (
          I => I,
          CLK => CLK,
          RESET => RESET,
          O => O
        );
		  
   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for 10 ns;
		CLK <= '1';
		wait for 10 ns;
   end process;
 
	process
	begin
		RESET <= '1';
		wait for 10 ns;
		RESET <= '0';
		wait for 10 ns;
		I <= '0';
		wait for 10 ns;
		I <= '1';
		wait for 20 ns;
		I <= '1';
		wait for 20 ns;
		I <= '0';
		
		wait;
	end process;
END;
