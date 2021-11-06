# 
all:
	rm -rfvd *.elf
	g++ -o posh.elf posh.cpp -O2 -std=c++17