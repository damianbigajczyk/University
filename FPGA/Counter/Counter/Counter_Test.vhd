LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Counter_Test IS
END Counter_Test;
 
ARCHITECTURE behavior OF Counter_Test IS 
 
    COMPONENT Counter
    PORT(
         X : IN  std_logic_vector(7 downto 0);
         EN : IN  std_logic;
         DIR : IN  std_logic;
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         SET : IN  std_logic;
         Q : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;

   --Inputs
   signal X : std_logic_vector(7 downto 0) := (others => '0');
   signal EN : std_logic := '0';
   signal DIR : std_logic := '0';
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal SET : std_logic := '0';

 	--Outputs
   signal Q : std_logic_vector(7 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Counter PORT MAP (
          X => X,
          EN => EN,
          DIR => DIR,
          CLK => CLK,
          RESET => RESET,
          SET => SET,
          Q => Q
        );
	X <= "01110110";
	SET <= '1';
	--wait for 5 ns;
	EN <= '1';
	SET <= '0';
	DIR <= '1';
	
   CLK_process :process
   begin
		CLK <= '0';
		wait for 5 ns;
		CLK <= '1';
		wait for 5 ns;
   end process;
	
	RESET_process :process
	begin
		RESET <= '0';
		wait for 80 ns;
		RESET <= '1';
		wait for 10 ns;
	end process;

END;
