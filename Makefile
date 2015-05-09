all: PICNTRLmain

PICNTRLmain: PICNTRL.o PICNTRLmain.o 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi -lpaho-mqtt3c
	
clean:
	$(RM) *.o PICNTRLmain
