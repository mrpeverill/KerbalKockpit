EESchema Schematic File Version 4
LIBS:BareRotary-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
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
L Switch:SW_Rotary12 SW1
U 1 1 5C2D5E26
P 2550 1950
F 0 "SW1" H 2450 2728 50  0000 C CNN
F 1 "SW_Rotary12" H 2450 2637 50  0000 C CNN
F 2 "Custom:R25_Rotary" H 2350 2650 50  0001 C CNN
F 3 "http://cdn-reichelt.de/documents/datenblatt/C200/DS-Serie%23LOR.pdf" H 2350 2650 50  0001 C CNN
	1    2550 1950
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x06_Counter_Clockwise J1
U 1 1 5C2FCA6E
P 1850 1550
F 0 "J1" H 1900 1967 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 1900 1876 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 1850 1550 50  0001 C CNN
F 3 "~" H 1850 1550 50  0001 C CNN
	1    1850 1550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2050 1450 2150 1450
Wire Wire Line
	2050 1550 2150 1550
Wire Wire Line
	2050 1650 2150 1650
Wire Wire Line
	2050 1750 2150 1750
Wire Wire Line
	2050 1850 2150 1850
Wire Wire Line
	2050 1350 2050 1300
Wire Wire Line
	2050 1300 3150 1300
Wire Wire Line
	3150 1300 3150 1950
Wire Wire Line
	1550 1850 1550 2050
Wire Wire Line
	1550 2050 2150 2050
Wire Wire Line
	1550 1750 1500 1750
Wire Wire Line
	1500 1750 1500 2150
Wire Wire Line
	1500 2150 2150 2150
Wire Wire Line
	1550 1650 1450 1650
Wire Wire Line
	1450 1650 1450 2250
Wire Wire Line
	1450 2250 2150 2250
Wire Wire Line
	1550 1550 1400 1550
Wire Wire Line
	1400 1550 1400 2350
Wire Wire Line
	1400 2350 2150 2350
Wire Wire Line
	1550 1450 1350 1450
Wire Wire Line
	1350 1450 1350 2450
Wire Wire Line
	1350 2450 2150 2450
Wire Wire Line
	1550 1350 1300 1350
Wire Wire Line
	1300 1350 1300 2550
Wire Wire Line
	1300 2550 2150 2550
$EndSCHEMATC
