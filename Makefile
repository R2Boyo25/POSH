# 
all:
	rm -rfvd *.elf
	g++ -o posh.elf *.cpp parse/*.cpp commands/*.cpp com/*.cpp -Ofast -std=c++17