--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:19:08 03/16/2019
-- Design Name:   
-- Module Name:   D:/236182/Lab_4/BINTO7SEG/BINTO7SEG_test.vhd
-- Project Name:  BINTO7SEG
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: BINTO7SEG
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY BINTO7SEG_test IS
END BINTO7SEG_test;
 
ARCHITECTURE behavior OF BINTO7SEG_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT BINTO7SEG
    PORT(
         BIN : IN  std_logic_vector(3 downto 0);
         DP : IN  std_logic;
         EN : IN  std_logic;
         SEG : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal BIN : std_logic_vector(3 downto 0) := (others => '0');
   signal DP : std_logic := '0';
   signal EN : std_logic := '0';

 	--Outputs
   signal SEG : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: BINTO7SEG PORT MAP (
          BIN => BIN,
          DP => DP,
          EN => EN,
          SEG => SEG
        );


   -- Stimulus process
   stim_proc: process
   begin		
     EN <='0';
	  wait for 10 ns;
	  DP <='1';
	  wait for 10 ns;
	  BIN <="0110";
	  wait for 10 ns;
	  BIN <="0101";
	  wait for 10 ns;
	  BIN <="0110";
	  wait for 10 ns;
	  EN <='1';
	  wait for 10 ns;
	  BIN <="0101";
	  wait for 10 ns;
	  BIN<="1001";
	  wait for 10 ns;
	  DP <='0';
     wait for 10 ns;	

      wait;
   end process;

END;
