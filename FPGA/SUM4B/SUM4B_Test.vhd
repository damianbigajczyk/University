--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   06:20:56 03/23/2019
-- Design Name:   
-- Module Name:   D:/236182/Lab_5/SUM4B/SUM4B_Test.vhd
-- Project Name:  SUM4B
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: SUM4B
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
 
ENTITY SUM4B_Test IS
END SUM4B_Test;
 
ARCHITECTURE behavior OF SUM4B_Test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT SUM4B
    PORT(
         CIN : IN  std_logic;
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(3 downto 0);
         COUT : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CIN : std_logic := '0';
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(3 downto 0);
   signal COUT : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SUM4B PORT MAP (
          CIN => CIN,
          A => A,
          B => B,
          Y => Y,
          COUT => COUT
        );

   -- Stimulus process
   stim_proc: process
   begin		
      CIN <= '1';
		A <= "1011";
		B <= "1011";
      wait for 10 ns;	


      wait;
   end process;

END;
