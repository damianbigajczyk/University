LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY MUL4x4_test IS
END MUL4x4_test;
 
ARCHITECTURE behavior OF MUL4x4_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT MUL4x4
    PORT(
         X0 : IN  std_logic_vector(3 downto 0);
         X1 : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X0 : std_logic_vector(3 downto 0) := (others => '0');
   signal X1 : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: MUL4x4 PORT MAP (
          X0 => X0,
          X1 => X1,
          Y => Y
        );
   -- Stimulus process
   stim_proc: process
   begin		
		X0 <= "1010";
		X1 <= "1101";
      wait for 10 ns;
		X0 <= "1111";
		X1 <= "1111";
      wait;
   end process;

END;
