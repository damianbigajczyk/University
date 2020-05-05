LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY CNT10_test IS
END CNT10_test;
 
ARCHITECTURE behavior OF CNT10_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CNT10
    PORT(
         RESET : IN  std_logic;
         CLK : IN  std_logic;
         C : OUT  std_logic;
         Q : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal RESET : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal C : std_logic;
   signal Q : std_logic_vector(3 downto 0);

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CNT10 PORT MAP (
          RESET => RESET,
          CLK => CLK,
          C => C,
          Q => Q
        );
	RESET_process :process
	begin
	RESET <= '1';
	wait for 5ns;
	RESET <= '0';
	wait for 1000000ns;
	end process;
	
   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for 10 ns;
		CLK <= '1';
		wait for 10 ns;
   end process;
	

	


END;
