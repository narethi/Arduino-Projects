EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 7906 7063
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 8~Segment~Displays:5161AS .?
U 1 1 61CD5D43
P 1250 3650
F 0 ".?" H 1250 3700 50  0001 C CNN
F 1 "5161AS" H 1628 3625 50  0000 L CNN
F 2 "" H 1250 3700 50  0001 C CNN
F 3 "" H 1250 3700 50  0001 C CNN
	1    1250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2350 2650 2350
Wire Wire Line
	1850 2250 1250 2250
Wire Wire Line
	1850 2350 1450 2350
Wire Wire Line
	1850 2450 1550 2450
Wire Wire Line
	1850 2550 1650 2550
Wire Wire Line
	1650 4050 1550 4050
Wire Wire Line
	1850 2650 1700 2650
Wire Wire Line
	1700 4100 1450 4100
Wire Wire Line
	1450 4100 1450 4050
Wire Wire Line
	1750 4150 1250 4150
Wire Wire Line
	1250 4150 1250 4050
Wire Wire Line
	1850 2850 1800 2850
Wire Wire Line
	1800 4200 1150 4200
Wire Wire Line
	1150 4200 1150 4050
Wire Wire Line
	1850 4300 1350 4300
Wire Wire Line
	1350 4300 1350 4050
Text Notes 1600 4650 0    50   ~ 0
GND
Wire Wire Line
	1850 4300 1850 4650
Connection ~ 1850 4300
Text Label 2700 1600 0    50   ~ 0
Serial_Data_In
Text Label 2750 1750 0    50   ~ 0
Output_Enabled_(Active_LOW)
Text Label 2800 1900 0    50   ~ 0
Storage_Register_Clock
$Comp
L 8~Segment~Displays:74HC595N .?
U 1 1 61CCF0EB
P 2200 2150
F 0 ".?" H 2200 2150 50  0001 C CNN
F 1 "74HC595N" H 2175 2183 50  0000 C CNN
F 2 "" H 2200 2150 50  0001 C CNN
F 3 "" H 2200 2150 50  0001 C CNN
	1    2200 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2650 2800 2650
Wire Wire Line
	2500 2750 2850 2750
Text Label 2850 2050 0    50   ~ 0
Shift_Regist_Clock
Wire Wire Line
	2500 2550 2750 2550
Wire Wire Line
	2500 2850 2900 2850
Text Label 2900 2200 0    50   ~ 0
Master_Reset
$Comp
L Device:R_Small_US R?
U 1 1 61D21999
P 1250 2350
F 0 "R?" H 1318 2396 50  0001 L CNN
F 1 "150R" H 1318 2350 50  0000 L CNN
F 2 "" H 1250 2350 50  0001 C CNN
F 3 "~" H 1250 2350 50  0001 C CNN
	1    1250 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61D2229B
P 1650 2650
F 0 "R?" H 1718 2696 50  0001 L CNN
F 1 "150R" H 1718 2650 50  0000 L CNN
F 2 "" H 1650 2650 50  0001 C CNN
F 3 "~" H 1650 2650 50  0001 C CNN
	1    1650 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61D22A60
P 1700 3500
F 0 "R?" H 1768 3546 50  0001 L CNN
F 1 "150R" H 1768 3500 50  0000 L CNN
F 2 "" H 1700 3500 50  0001 C CNN
F 3 "~" H 1700 3500 50  0001 C CNN
	1    1700 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61D24070
P 1750 3050
F 0 "R?" H 1818 3096 50  0001 L CNN
F 1 "150R" H 1818 3050 50  0000 L CNN
F 2 "" H 1750 3050 50  0001 C CNN
F 3 "~" H 1750 3050 50  0001 C CNN
	1    1750 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61D2494A
P 1800 3350
F 0 "R?" H 1868 3396 50  0001 L CNN
F 1 "150R" H 1868 3350 50  0000 L CNN
F 2 "" H 1800 3350 50  0001 C CNN
F 3 "~" H 1800 3350 50  0001 C CNN
	1    1800 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61D24FAE
P 1550 3200
F 0 "R?" H 1618 3246 50  0001 L CNN
F 1 "150R" H 1618 3200 50  0000 L CNN
F 2 "" H 1550 3200 50  0001 C CNN
F 3 "~" H 1550 3200 50  0001 C CNN
	1    1550 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61D256F7
P 1450 3000
F 0 "R?" H 1518 3046 50  0001 L CNN
F 1 "150R" H 1518 3000 50  0000 L CNN
F 2 "" H 1450 3000 50  0001 C CNN
F 3 "~" H 1450 3000 50  0001 C CNN
	1    1450 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2050 1150 2550
$Comp
L Device:R_Small_US R?
U 1 1 61D1F73E
P 1150 2650
F 0 "R?" H 1218 2696 50  0001 L CNN
F 1 "150R" H 1218 2650 50  0000 L CNN
F 2 "" H 1150 2650 50  0001 C CNN
F 3 "~" H 1150 2650 50  0001 C CNN
	1    1150 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2750 1150 3300
Wire Wire Line
	1250 2450 1250 3300
Wire Wire Line
	1450 2350 1450 2900
Wire Wire Line
	1450 3100 1450 3300
Wire Wire Line
	1550 2450 1550 3100
Wire Wire Line
	1850 2950 1850 4300
Wire Wire Line
	1800 2850 1800 3250
Wire Wire Line
	1850 2750 1750 2750
Wire Wire Line
	1750 2750 1750 2950
Wire Wire Line
	1700 2650 1700 3400
Wire Wire Line
	1650 2750 1650 4050
Wire Wire Line
	1700 3600 1700 4100
Wire Wire Line
	1750 3150 1750 4150
Wire Wire Line
	1800 3450 1800 4200
Text Notes 6800 6450 0    59   ~ 0
1
Text Notes 3600 6300 0    50   ~ 0
5161AS 8 segment displays driven by HC595 8 bit registers
Text Notes 4350 6450 0    50   ~ 0
2021/12/29
$Comp
L 8~Segment~Displays:74HC595N .?
U 1 1 61D8E431
P 4200 2150
F 0 ".?" H 4200 2150 50  0001 C CNN
F 1 "74HC595N" H 4175 2183 50  0000 C CNN
F 2 "" H 4200 2150 50  0001 C CNN
F 3 "" H 4200 2150 50  0001 C CNN
	1    4200 2150
	-1   0    0    -1  
$EndComp
Wire Bus Line
	1350 4650 6200 4650
Text Label 2500 2950 0    50   ~ 0
Next_Register_(Data_OUT_SER)
Wire Wire Line
	2650 2350 2650 2050
Wire Wire Line
	2650 2050 1150 2050
Wire Bus Line
	1550 1400 5000 1400
Text Notes 1550 1400 0    50   ~ 0
5V
Wire Wire Line
	2500 2450 2700 2450
Wire Wire Line
	2700 1500 2700 2450
Wire Wire Line
	2500 1400 2500 2250
Wire Wire Line
	2750 1650 2750 2550
Wire Wire Line
	2800 1800 2800 2650
Wire Wire Line
	2850 1950 2850 2750
Wire Wire Line
	2900 2100 2900 2850
Wire Wire Line
	3900 2250 3900 1400
Wire Wire Line
	3900 2550 2750 2550
Connection ~ 2750 2550
Wire Wire Line
	3900 2650 2800 2650
Connection ~ 2800 2650
Wire Wire Line
	3900 2750 2850 2750
Connection ~ 2850 2750
Wire Wire Line
	3900 2850 2900 2850
Connection ~ 2900 2850
Wire Wire Line
	2500 2950 3650 2950
Wire Wire Line
	3650 2950 3650 2450
Wire Wire Line
	3650 2450 3900 2450
Wire Wire Line
	4550 2950 4550 4650
$Comp
L 8~Segment~Displays:5161AS .?
U 1 1 61DDCBE7
P 5150 3650
F 0 ".?" H 5150 3700 50  0001 C CNN
F 1 "5161AS" H 5528 3625 50  0000 L CNN
F 2 "" H 5150 3700 50  0001 C CNN
F 3 "" H 5150 3700 50  0001 C CNN
	1    5150 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4050 5250 4650
Wire Wire Line
	3900 2350 3850 2350
Wire Wire Line
	3850 2350 3850 2050
Wire Wire Line
	3850 2050 5050 2050
Wire Wire Line
	4550 2250 5150 2250
Wire Wire Line
	4550 2350 5350 2350
Wire Wire Line
	5350 2350 5350 3100
Wire Wire Line
	4550 2450 5450 2450
Wire Wire Line
	5450 2450 5450 2900
Wire Wire Line
	4550 2550 5600 2550
Wire Wire Line
	5600 4050 5450 4050
Wire Wire Line
	5350 4100 5350 4050
Wire Wire Line
	5150 4150 5150 4050
Wire Wire Line
	5050 4200 5050 4050
Text Label 5900 4400 0    50   ~ 0
Next_Register_(Data_OUT_SER)
$Comp
L Device:R_Small_US R?
U 1 1 61E36DD4
P 5150 3000
F 0 "R?" H 5218 3046 50  0001 L CNN
F 1 "150R" H 5218 3000 50  0000 L CNN
F 2 "" H 5150 3000 50  0001 C CNN
F 3 "~" H 5150 3000 50  0001 C CNN
	1    5150 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E38C5E
P 5900 3500
F 0 "R?" H 5968 3546 50  0001 L CNN
F 1 "150R" H 5968 3500 50  0000 L CNN
F 2 "" H 5900 3500 50  0001 C CNN
F 3 "~" H 5900 3500 50  0001 C CNN
	1    5900 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E3AB11
P 5050 3200
F 0 "R?" H 5118 3246 50  0001 L CNN
F 1 "150R" H 5118 3200 50  0000 L CNN
F 2 "" H 5050 3200 50  0001 C CNN
F 3 "~" H 5050 3200 50  0001 C CNN
	1    5050 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E3CC16
P 5750 3000
F 0 "R?" H 5818 3046 50  0001 L CNN
F 1 "150R" H 5818 3000 50  0000 L CNN
F 2 "" H 5750 3000 50  0001 C CNN
F 3 "~" H 5750 3000 50  0001 C CNN
	1    5750 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E3F38C
P 5450 3000
F 0 "R?" H 5518 3046 50  0001 L CNN
F 1 "150R" H 5518 3000 50  0000 L CNN
F 2 "" H 5450 3000 50  0001 C CNN
F 3 "~" H 5450 3000 50  0001 C CNN
	1    5450 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E40BA1
P 6050 3000
F 0 "R?" H 6118 3046 50  0001 L CNN
F 1 "150R" H 6118 3000 50  0000 L CNN
F 2 "" H 6050 3000 50  0001 C CNN
F 3 "~" H 6050 3000 50  0001 C CNN
	1    6050 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E42BED
P 5600 3400
F 0 "R?" H 5668 3446 50  0001 L CNN
F 1 "150R" H 5668 3400 50  0000 L CNN
F 2 "" H 5600 3400 50  0001 C CNN
F 3 "~" H 5600 3400 50  0001 C CNN
	1    5600 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 61E452C7
P 5350 3200
F 0 "R?" H 5418 3246 50  0001 L CNN
F 1 "150R" H 5418 3200 50  0000 L CNN
F 2 "" H 5350 3200 50  0001 C CNN
F 3 "~" H 5350 3200 50  0001 C CNN
	1    5350 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2650 5750 2650
Wire Wire Line
	5050 2050 5050 3100
Wire Wire Line
	5150 2250 5150 2900
Wire Wire Line
	5150 3100 5150 3300
Wire Wire Line
	5450 3100 5450 3300
Wire Wire Line
	5600 3500 5600 4050
Wire Wire Line
	5600 2550 5600 3300
Wire Wire Line
	5750 2650 5750 2900
Wire Wire Line
	5750 3100 5750 4100
Wire Wire Line
	5350 4100 5750 4100
Wire Wire Line
	5900 2750 5900 3400
Wire Wire Line
	4550 2750 5900 2750
Wire Wire Line
	5150 4150 5900 4150
Wire Wire Line
	6050 4200 6050 3100
Wire Wire Line
	6050 2850 4550 2850
Wire Wire Line
	5050 4200 6050 4200
Wire Wire Line
	5900 3600 5900 4150
Wire Wire Line
	6050 2900 6050 2850
Wire Wire Line
	3900 4400 7250 4400
Wire Wire Line
	3900 2950 3900 4400
Text Notes 3250 5800 0    50   ~ 0
This is the diagram for the 8-Segment display that is driven by the project in this folder,\nthis is showing how to connect 2 registers together and which lines are shared, in \ntheory this can be extend to n displays by chaining the overflow from each previous\nchip. The HC595 is a 100MHz chip so for low speed applications such as switching\nswitching displays, this chip is a great choice
$EndSCHEMATC
