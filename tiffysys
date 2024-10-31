module tiffysys(CLOCK_50, SW, KEY, LEDR, LEDG, HEX0, HEX1, HEX2, HEX3,
HEX4, HEX5, HEX6,HEX7, SRAM_ADDR, SRAM_DQ, SRAM_LB_N,
SRAM_CE_N, SRAM_OE_N, SRAM_WE_N,SRAM_UB_N, DRAM_ADDR, DRAM_RAS_N, DRAM_BA, DRAM_CAS_N,DRAM_RAS_N, DRAM_CLK,
DRAM_CKE, DRAM_CS_N, DRAM_WE_N, DRAM_DQM, DRAM_DQ, GPIO, LCD_RS, LCD_RW, 
LCD_DATA, LCD_EN, LCD_ON, LCD_BLON
);
input wire CLOCK_50;
input wire [17:0] SW;
input wire [3:0] KEY;
output wire [31:0] GPIO;
output wire [17:0] LEDR;
output wire [7:0] LEDG;
output wire [6:0] HEX0;
output wire [6:0] HEX1;
output wire [6:0] HEX2;
output wire [6:0] HEX3;
output wire [6:0] HEX4;
output wire [6:0] HEX5;
output wire [6:0] HEX6;
output wire [6:0] HEX7;
inout wire [15:0] SRAM_DQ;
output wire[19:0] SRAM_ADDR;
output wire SRAM_LB_N;
output wire SRAM_UB_N;
output wire SRAM_CE_N;
output wire SRAM_OE_N;
output wire SRAM_WE_N;
output [12:0] DRAM_ADDR;
output [1:0] DRAM_BA;
output DRAM_CAS_N, DRAM_RAS_N,DRAM_CLK;
output DRAM_CKE, DRAM_CS_N,DRAM_WE_N;
output [3:0] DRAM_DQM;
inout [31:0] DRAM_DQ; 
inout wire [7:0] LCD_DATA;
output wire LCD_ON, LCD_BLON, LCD_EN, LCD_RS, LCD_RW;

// instainting the code
unsaved nios2_qsys_0(
.clk_clk(CLOCK_50), // clk.clk
.ledg_export(LEDG), // green_leds.export
.key_export(KEY[3:1]), // key_.export
.reset_reset(KEY[0]), // reset.reset_n
.hex0_export(HEX0), 
.hex1_export(HEX1), 
.hex2_export(HEX2), 
.hex3_export(HEX3), 
.hex4_export(HEX4), 
.hex5_export(HEX5), 
.hex6_export(HEX6), 
.hex7_export(HEX7), 
.switches_export(SW), // switches.export
.sram_DQ(SRAM_DQ), // sram.DQ
.sram_ADDR(SRAM_ADDR), // ADDR
.sram_LB_N(SRAM_LB_N), // LB_N
.sram_UB_N(SRAM_UB_N), // UB_N
.sram_CE_N(SRAM_CE_N), // CE_N
.sram_OE_N(SRAM_OE_N), // OE_N
.sram_WE_N(SRAM_WE_N),
.ledr_export(LEDR),
.jp5_export(GPIO),	
.lcd_module_DATA(LCD_DATA),
.lcd_module_ON(LCD_ON),
.lcd_module_BLON(LCD_BLON),
.lcd_module_EN(LCD_EN),
.lcd_module_RS(LCD_RS),
.lcd_module_RW(LCD_RW),
.sdram_addr(DRAM_ADDR), // sdram_wire.addr
.sdram_ba(DRAM_BA), // .ba
.sdram_cas_n(DRAM_CAS_N), // .cas_n
.sdram_cke(DRAM_CKE), // .cke
.sdram_cs_n(DRAM_CS_N), // .cs_n
.sdram_dq(DRAM_DQ), // .dq
.sdram_dqm(DRAM_DQM), // .dqm
.sdram_ras_n(DRAM_RAS_N), // .ras_n
.sdram_we_n(DRAM_WE_N), // .we_n
.sdram_clk_clk(DRAM_CLK)
);
endmodule
