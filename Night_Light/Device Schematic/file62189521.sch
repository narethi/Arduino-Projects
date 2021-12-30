EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 7905 7874
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1950 650  0    59   Input ~ 0
Finished_Night_Light_Circuit
Text Notes 6750 7250 0    59   ~ 0
1
Text Notes 3550 7100 0    59   ~ 0
Addressable RGB Night Light using CRGB LEDs and Shift Registers (1 Set of 8 LEDs)
Text Notes 4350 7250 0    59   ~ 0
2021-12-29
Text Notes 3200 6300 0    59   ~ 0
This is the completed circuit that contains 3 rows of 16 LEDs
$Comp
L 8~Segment~Displays:8_CRGB_LED_ARRAY 8RGB?
U 1 1 62199421
P 3750 1200
F 0 "8RGB?" H 3750 1200 59  0001 C CNN
F 1 "8_CRGB_LED_ARRAY" H 3812 -80 59  0000 C CNN
F 2 "" H 3750 1200 59  0001 C CNN
F 3 "" H 3750 1200 59  0001 C CNN
	1    3750 1200
	1    0    0    -1  
$EndComp
$Comp
L 8~Segment~Displays:8_CRGB_LED_ARRAY 8RGB?
U 1 1 6219BC80
P 5550 1200
F 0 "8RGB?" H 5550 1200 59  0001 C CNN
F 1 "8_CRGB_LED_ARRAY" H 5612 -80 59  0000 C CNN
F 2 "" H 5550 1200 59  0001 C CNN
F 3 "" H 5550 1200 59  0001 C CNN
	1    5550 1200
	1    0    0    -1  
$EndComp
$Comp
L 8~Segment~Displays:8_CRGB_LED_ARRAY 8RGB?
U 1 1 6219D53E
P 3750 2600
F 0 "8RGB?" H 3750 2600 59  0001 C CNN
F 1 "8_CRGB_LED_ARRAY" H 3812 1320 59  0000 C CNN
F 2 "" H 3750 2600 59  0001 C CNN
F 3 "" H 3750 2600 59  0001 C CNN
	1    3750 2600
	1    0    0    -1  
$EndComp
$Comp
L 8~Segment~Displays:8_CRGB_LED_ARRAY 8RGB?
U 1 1 6219F966
P 3750 4000
F 0 "8RGB?" H 3750 4000 59  0001 C CNN
F 1 "8_CRGB_LED_ARRAY" H 3812 2720 59  0000 C CNN
F 2 "" H 3750 4000 59  0001 C CNN
F 3 "" H 3750 4000 59  0001 C CNN
	1    3750 4000
	1    0    0    -1  
$EndComp
$Comp
L 8~Segment~Displays:8_CRGB_LED_ARRAY 8RGB?
U 1 1 6219F96C
P 5550 4000
F 0 "8RGB?" H 5550 4000 59  0001 C CNN
F 1 "8_CRGB_LED_ARRAY" H 5612 2720 59  0000 C CNN
F 2 "" H 5550 4000 59  0001 C CNN
F 3 "" H 5550 4000 59  0001 C CNN
	1    5550 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1800 5000 1800
Wire Wire Line
	4350 3200 5000 3200
Wire Wire Line
	4350 4600 5000 4600
Wire Wire Line
	3800 4250 5600 4250
Wire Wire Line
	3800 1450 5600 1450
Wire Wire Line
	6150 2800 3200 2800
Wire Wire Line
	3200 2800 3200 3200
Wire Wire Line
	6150 3200 6150 4200
Wire Wire Line
	6150 4200 3200 4200
Wire Wire Line
	3200 4200 3200 4600
Wire Wire Line
	4950 5350 4950 4700
Wire Wire Line
	4950 1900 4950 2550
Wire Wire Line
	4950 1900 5000 1900
Wire Wire Line
	1150 3300 3150 3300
Wire Wire Line
	3200 1900 3150 1900
Wire Wire Line
	3150 1900 3150 2550
Connection ~ 3150 2550
Wire Wire Line
	3150 2550 4950 2550
Wire Wire Line
	3150 2550 3150 3300
Connection ~ 3150 3300
Wire Wire Line
	3150 3300 3200 3300
Wire Wire Line
	3150 4700 3200 4700
Wire Wire Line
	3150 4700 3150 5350
Connection ~ 3150 4700
Wire Wire Line
	4950 3950 4950 3300
Wire Wire Line
	4950 3300 5000 3300
Wire Wire Line
	3150 3950 4950 3950
Wire Wire Line
	4950 4700 5000 4700
Wire Wire Line
	3150 5350 4950 5350
Wire Wire Line
	3200 2000 3100 2000
Wire Wire Line
	3100 2000 3100 2600
Wire Wire Line
	3100 3400 3200 3400
Connection ~ 3150 3950
Wire Wire Line
	3150 3950 3150 4700
Wire Wire Line
	3100 4800 3200 4800
Connection ~ 3100 3400
Wire Wire Line
	5000 3400 4900 3400
Wire Wire Line
	4900 3400 4900 4000
Wire Wire Line
	4900 4000 3100 4000
Connection ~ 3100 4000
Wire Wire Line
	3100 4000 3100 4800
Wire Wire Line
	3100 4800 3100 5400
Wire Wire Line
	3100 5400 4900 5400
Wire Wire Line
	4900 5400 4900 4800
Wire Wire Line
	4900 4800 5000 4800
Connection ~ 3100 4800
Wire Wire Line
	3100 3400 1150 3400
Wire Wire Line
	3100 2600 4900 2600
Wire Wire Line
	4900 2600 4900 2000
Wire Wire Line
	4900 2000 5000 2000
Connection ~ 3100 2600
Wire Wire Line
	3100 2600 3100 3400
Wire Wire Line
	3200 2100 3050 2100
Wire Wire Line
	3050 3500 3200 3500
Wire Wire Line
	3050 2100 3050 2650
Wire Wire Line
	3050 2650 4850 2650
Wire Wire Line
	4850 2650 4850 2100
Wire Wire Line
	4850 2100 5000 2100
Connection ~ 3050 2650
Wire Wire Line
	3050 2650 3050 3500
Wire Wire Line
	3050 4900 3200 4900
Connection ~ 3050 3500
Wire Wire Line
	3050 4050 4850 4050
Wire Wire Line
	4850 4050 4850 3500
Wire Wire Line
	4850 3500 5000 3500
Connection ~ 3050 4050
Wire Wire Line
	3050 4050 3050 4900
Wire Wire Line
	3050 4900 3050 5450
Wire Wire Line
	3050 5450 4850 5450
Wire Wire Line
	4850 5450 4850 4900
Wire Wire Line
	4850 4900 5000 4900
Connection ~ 3050 4900
Wire Wire Line
	3200 2200 3000 2200
Wire Wire Line
	3000 2200 3000 2700
Wire Wire Line
	3000 3600 3200 3600
Wire Wire Line
	3000 2700 4800 2700
Wire Wire Line
	4800 2700 4800 2200
Wire Wire Line
	4800 2200 5000 2200
Connection ~ 3000 2700
Wire Wire Line
	3000 2700 3000 3600
Wire Wire Line
	3000 5000 3200 5000
Connection ~ 3000 3600
Wire Wire Line
	3000 4100 4800 4100
Wire Wire Line
	4800 4100 4800 3600
Wire Wire Line
	4800 3600 5000 3600
Connection ~ 3000 4100
Wire Wire Line
	3000 4100 3000 5000
Wire Wire Line
	3000 5000 3000 5500
Wire Wire Line
	3000 5500 4800 5500
Wire Wire Line
	4800 5500 4800 5000
Wire Wire Line
	4800 5000 5000 5000
Connection ~ 3000 5000
Wire Wire Line
	3050 3500 1150 3500
Wire Wire Line
	3000 3600 1150 3600
Wire Wire Line
	3200 2300 2950 2300
Wire Wire Line
	2950 2300 2950 2750
Wire Wire Line
	2950 3700 3200 3700
Wire Wire Line
	2950 2750 4750 2750
Wire Wire Line
	4750 2750 4750 2300
Wire Wire Line
	4750 2300 5000 2300
Connection ~ 2950 2750
Wire Wire Line
	2950 2750 2950 3700
Wire Wire Line
	2950 5100 3200 5100
Connection ~ 2950 3700
Wire Wire Line
	2950 4150 4750 4150
Wire Wire Line
	4750 4150 4750 3700
Wire Wire Line
	4750 3700 5000 3700
Connection ~ 2950 4150
Wire Wire Line
	2950 4150 2950 5100
Wire Wire Line
	2950 5100 2950 5550
Wire Wire Line
	2950 5550 4750 5550
Wire Wire Line
	4750 5550 4750 5100
Wire Wire Line
	4750 5100 5000 5100
Connection ~ 2950 5100
Wire Wire Line
	5600 4250 6400 4250
Connection ~ 5600 4250
Wire Wire Line
	5600 1450 6400 1450
Connection ~ 5600 1450
Wire Wire Line
	3150 3300 3150 3950
Wire Wire Line
	3100 3400 3100 4000
Wire Wire Line
	3050 3500 3050 4050
Wire Wire Line
	3000 3600 3000 4100
Wire Wire Line
	2950 3700 2950 4150
$Comp
L 8~Segment~Displays:8_CRGB_LED_ARRAY 8RGB?
U 1 1 62224AEF
P 5550 2600
F 0 "8RGB?" H 5550 2600 59  0001 C CNN
F 1 "8_CRGB_LED_ARRAY" H 5612 1320 59  0000 C CNN
F 2 "" H 5550 2600 59  0001 C CNN
F 3 "" H 5550 2600 59  0001 C CNN
	1    5550 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1450 6400 2850
Wire Wire Line
	3800 2850 5600 2850
Wire Wire Line
	5600 2850 6400 2850
Connection ~ 5600 2850
Connection ~ 6400 2850
Wire Wire Line
	6400 2850 6400 4250
Wire Wire Line
	6150 2800 6150 1800
Wire Wire Line
	3200 1800 2900 1800
Wire Wire Line
	2900 1800 2900 3200
Wire Wire Line
	2900 3200 1150 3200
Wire Wire Line
	3800 1450 2850 1450
Wire Wire Line
	2850 1450 2850 3100
Wire Wire Line
	2850 3100 1150 3100
Connection ~ 3800 1450
Text Label 1150 3100 0    59   ~ 0
GND
Text Label 1150 3200 0    59   ~ 0
Serial_Data
Text Label 1150 3300 0    59   ~ 0
5V_Vcc
Text Label 1150 3400 0    59   ~ 0
Storage_Register_Clear_MR
Text Label 1150 3500 0    59   ~ 0
Storage_Register_CLK
Text Label 1150 3600 0    59   ~ 0
Register_CLK
Wire Wire Line
	2950 3700 1150 3700
Text Label 1150 3700 0    59   ~ 0
Output_Enable_LOW
Wire Wire Line
	6150 4600 6750 4600
Text Label 6100 4600 0    59   ~ 0
Not_Connected
$EndSCHEMATC
