bare metal stm32 uart + can

usart2 on pa2/pa3
can1 on pa11/pa12

just registers no hal no cube

make
make flash

baud 9600
can 500k

loop sends id 0x123 and prints on uart
