EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 5906 4724
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
L Transistor_BJT:BC548 Q?
U 1 1 61CBED9D
P 3250 1850
F 0 "Q?" H 3441 1896 50  0001 L CNN
F 1 "BC548" H 3441 1805 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3450 1775 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 3250 1850 50  0001 L CNN
	1    3250 1850
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 61CC180D
P 3250 2450
F 0 "Q?" H 3441 2496 50  0001 L CNN
F 1 "BC548" H 3441 2405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3450 2375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 3250 2450 50  0001 L CNN
	1    3250 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 61CC3111
P 3250 1250
F 0 "Q?" H 3441 1296 50  0001 L CNN
F 1 "BC548" H 3441 1205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3450 1175 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 3250 1250 50  0001 L CNN
	1    3250 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_CRGB D?
U 1 1 61CBBDEA
P 4450 1900
F 0 "D?" H 4450 2397 50  0001 C CNN
F 1 "LED_CRGB" H 4450 2306 50  0000 C CNN
F 2 "" H 4450 1850 50  0001 C CNN
F 3 "~" H 4450 1850 50  0001 C CNN
	1    4450 1900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4250 2050 4250 1900
Wire Wire Line
	4250 1450 4250 1700
Wire Wire Line
	3350 1650 2750 1650
Wire Wire Line
	2750 1650 2750 1050
Wire Wire Line
	2750 1050 3350 1050
Wire Wire Line
	2750 1650 2750 2250
Wire Wire Line
	2750 2250 3350 2250
Connection ~ 2750 1650
Wire Wire Line
	3050 1250 2250 1250
Wire Wire Line
	3050 1850 2250 1850
Wire Wire Line
	3050 2450 2250 2450
Wire Wire Line
	4650 1900 4650 750 
Wire Wire Line
	4650 750  2250 750 
Wire Wire Line
	2750 1050 2250 1050
Connection ~ 2750 1050
Text Label 2250 750  0    50   ~ 0
GND
Text Label 2250 1050 0    50   ~ 0
5V
Text Label 2250 1250 0    50   ~ 0
Red_Signal
Text Label 2250 1850 0    50   ~ 0
Green_Signal
Text Label 2250 2450 0    50   ~ 0
Blue_Signal
Wire Wire Line
	4250 2650 4250 2100
$Comp
L Device:R_Small_US R?
U 1 1 61CFB790
P 3800 1450
F 0 "R?" H 3868 1496 50  0001 L CNN
F 1 "150R" V 3687 1450 50  0000 C CNN
F 2 "" H 3800 1450 50  0001 C CNN
F 3 "~" H 3800 1450 50  0001 C CNN
	1    3800 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 1450 3700 1450
Wire Wire Line
	3900 1450 4250 1450
Wire Wire Line
	3900 2050 4250 2050
$Comp
L Device:R_Small_US R?
U 1 1 61D02EB9
P 3800 2650
F 0 "R?" H 3868 2696 50  0001 L CNN
F 1 "70R" V 3687 2650 50  0000 C CNN
F 2 "" H 3800 2650 50  0001 C CNN
F 3 "~" H 3800 2650 50  0001 C CNN
	1    3800 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 2650 3700 2650
Wire Wire Line
	3900 2650 4250 2650
Wire Wire Line
	3350 2050 3700 2050
$Comp
L Device:R_Small_US R?
U 1 1 61D027AD
P 3800 2050
F 0 "R?" H 3868 2096 50  0001 L CNN
F 1 "145R" V 3687 2050 50  0000 C CNN
F 2 "" H 3800 2050 50  0001 C CNN
F 3 "~" H 3800 2050 50  0001 C CNN
	1    3800 2050
	0    1    1    0   
$EndComp
Text Label 1550 3950 0    50   ~ 0
RGB_SIMPLE_CIRCUIT
Text Notes 1250 3100 0    50   ~ 0
This is a very simple CRGB circuit that is used with the small sample in Arduino project repo, 
Text Notes 1250 3200 0    50   ~ 0
the transistors are used to ensure that the correct supply voltage is given to the LEDs as the signal 
Text Notes 1250 3300 0    50   ~ 0
voltage is very small
Text Notes 4800 4100 0    50   ~ 0
1
Text Notes 2350 4100 0    50   ~ 0
2021-12-28
$EndSCHEMATC
