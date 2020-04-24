EESchema Schematic File Version 4
LIBS:HIIT_Standalone-cache
EELAYER 30 0
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
L Switch:SW_SPST SW?
U 1 1 5EAE2586
P 2100 1250
F 0 "SW?" H 2100 1485 50  0000 C CNN
F 1 "SW_SPST" H 2100 1394 50  0000 C CNN
F 2 "" H 2100 1250 50  0001 C CNN
F 3 "~" H 2100 1250 50  0001 C CNN
	1    2100 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5EAE272E
P 3550 1400
F 0 "R?" H 3620 1446 50  0000 L CNN
F 1 "R" H 3620 1355 50  0000 L CNN
F 2 "" V 3480 1400 50  0001 C CNN
F 3 "~" H 3550 1400 50  0001 C CNN
	1    3550 1400
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U?
U 1 1 5EAE988C
P 2750 1250
F 0 "U?" H 2750 1492 50  0000 C CNN
F 1 "L7805" H 2750 1401 50  0000 C CNN
F 2 "" H 2775 1100 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2750 1200 50  0001 C CNN
	1    2750 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Jack-DC J?
U 1 1 5EAEB9AC
P 1500 1350
F 0 "J?" H 1557 1675 50  0000 C CNN
F 1 "Jack-DC" H 1557 1584 50  0000 C CNN
F 2 "" H 1550 1310 50  0001 C CNN
F 3 "~" H 1550 1310 50  0001 C CNN
	1    1500 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5EAEC5C2
P 3050 1750
F 0 "C?" H 3168 1796 50  0000 L CNN
F 1 "CP" H 3168 1705 50  0000 L CNN
F 2 "" H 3088 1600 50  0001 C CNN
F 3 "~" H 3050 1750 50  0001 C CNN
	1    3050 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5EAEC1D9
P 2400 1750
F 0 "C?" H 2518 1796 50  0000 L CNN
F 1 "CP" H 2518 1705 50  0000 L CNN
F 2 "" H 2438 1600 50  0001 C CNN
F 3 "~" H 2400 1750 50  0001 C CNN
	1    2400 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5EAE42A2
P 3550 1750
F 0 "D?" H 3543 1966 50  0000 C CNN
F 1 "LED" H 3543 1875 50  0000 C CNN
F 2 "" H 3550 1750 50  0001 C CNN
F 3 "~" H 3550 1750 50  0001 C CNN
	1    3550 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1800 1250 1900 1250
Wire Wire Line
	2300 1250 2450 1250
Wire Wire Line
	3050 1250 3550 1250
Wire Wire Line
	1800 1450 2100 1450
Wire Wire Line
	2100 1450 2100 1900
Wire Wire Line
	2100 1900 2400 1900
Wire Wire Line
	2400 1900 2750 1900
Connection ~ 2400 1900
Wire Wire Line
	3050 1900 3550 1900
Connection ~ 3050 1900
Wire Wire Line
	2750 1550 2750 1900
Connection ~ 2750 1900
Wire Wire Line
	2750 1900 3050 1900
Wire Wire Line
	3050 1250 3050 1600
Connection ~ 3050 1250
Wire Wire Line
	3550 1550 3550 1600
Wire Wire Line
	3550 1250 4000 1250
Connection ~ 3550 1250
Wire Wire Line
	3550 1900 4000 1900
Connection ~ 3550 1900
$EndSCHEMATC
