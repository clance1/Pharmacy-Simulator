# File Name: Makefile
# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu 
#
# This file contains the Makefile for compiling both possible 
# solutions, both struct and class, for Challenge 1 and 2.
#
# LIST OF MAKE COMMANDS AVAILABLE:
# - make C01STR 		- Compiles the version with a DATE Struct 
# - make C01CLA 		- Compiles the version with a DATE Class
# - make C02STRBOT 		- Compiles Challenge 2 testBottle with a DATE Struct 
# - make C02CLABOT 		- Compiles Challenge 2 testBottle with a DATE Class
# - make challenge01	- Compiles all possibilities for Challenge 1
# - make challenge02    - Compiles all possibilities for Challenge 2
# - make all    		- Compiles both challenge 01 simultaneously 
# - make clean			- Cleans all files to pre-compilation 

# First, identify the compiler to be used.
C++ = g++

# Next, add the compiler flags, which we call CFLAGS
# -g    			adds debugging information to the executable file
# -std::gnu++11 	GNU C++ compiler, g++, provides extensions to the C++ language
#					For more info on gnu++11 https://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Extensions.html
# -Wpedantic		Issue all the warnings demanded by strict ISO C and ISO C++	
CFLAGS = -g -std=gnu++11 -Wpedantic

########################### Executables ###############################

# Challenge 1
DATESTR = testDateStr
DATECLA = testDateCla

# Challenge 2
# testBottle using Date class 
BOTCLA = testBottleCla
BOTSTR = testBottleStr
ROWCLA = testQueueCla
ROWSTR = testQueueStr


########################### Command: make C01STR ###############################

# First, create a message to send to the user
strMsg = $(info ********COMPILING STRUCT VERSION - FILEZILLA!***********)

# Next, indicate the compilation commands
# Put together, this becomes: g++ -g -std=gnu++11 -Wpedantic testDateStr.cpp -o testDateStr
strCmp = $(C++) $(CFLAGS) $(DATESTR).cpp -o $(DATESTR)

# Command: make C01STR
# output: ********COMPILING STRUCT VERSION************
# output: g++ -g -std=gnu++11 -Wpedantic testDateStr.cpp -o testDateStr
C01STR: 
	$(strMsg) 
	$(strCmp)

######################### Command: make C01CLA ###############################

# First, create a message to send to the user
claMsg = $(info ********COMPILING CLASS VERSION************)

# Put both cpp files into claCPP, since the .h files connect them.
claCPP = $(DATECLA).cpp dateCla.cpp

# Next, indicate the compilation commands
# Put together, this becomes: g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla
claCmp =  $(C++) $(CFLAGS) $(claCPP) -o $(DATECLA)

# Command: make C01CLA
# output: ********COMPILING CLASS VERSION************
# output: g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla
C01CLA: 
	$(claMsg) 
	$(claCmp)		


######################### Command: make C02CLABOT ###############################
# Complies the testBottle file where the DATE is a Class 

# First, create a message to send to the user
claBotMsg = $(info ********COMPILING Challenge 2 testBottle - CLASS VERSION************)

# Put both cpp files into claCPP, since the .h files connect them.
# Note: bottle.h included in testBottle.cpp 
claBOT = $(BOTCLA).cpp dateCla.cpp

# Next, indicate the compilation commands
# Put together, this becomes: g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla
claBotCmp =  $(C++) $(CFLAGS) $(claBOT) -o $(BOTCLA)

# Command: make C02CLABOT
# output: ********COMPILING CLASS VERSION************
# output: g++ -g -std=gnu++11 -Wpedantic testBottleCla.cpp dateCla.cpp -o testBottleCla
C02CLABOT: 
	$(claBotMsg) 
	$(claBotCmp)	


######################### Command: make C02STRBOT ###############################
# Complies the testBottle file where the DATE is a Class 

# First, create a message to send to the user
strBotMsg = $(info ********COMPILING Challenge 2 testBottle - Date STRUCT VERSION************)

# Put both cpp files into claCPP, since the .h files connect them.
# Note: bottle.h included in testBottle.cpp, and date.h included in bottle.h 
strBOT = $(BOTSTR).cpp

# Next, indicate the compilation commands
# Put together, this becomes: g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla
strBotCmp =  $(C++) $(CFLAGS) $(strBOT) -o $(BOTSTR)

# Command: make C02CLABOT
# output: ********COMPILING CLASS VERSION************
# output: g++ -g -std=gnu++11 -Wpedantic testBottle.cpp testDateCla.cpp dateCla.cpp -o testDateCla
C02STRBOT: 
	$(strBotMsg) 
	$(strBotCmp)	


######################### Command: make C02CLAROW ###############################
# Complies the testBottle file where the DATE is a Class 

# First, create a message to send to the user
claRowMsg = $(info ********COMPILING Challenge 2 testRow - Date CLASS VERSION************)

# Put both cpp files into claCPP, since the .h files connect them.
# Note: bottle.h included in testBottle.cpp, and date.h included in bottle.h 
claRow = $(ROWCLA).cpp dateCla.cpp

# Next, indicate the compilation commands
# Put together, this becomes: g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla
claRowCmp =  $(C++) $(CFLAGS) $(claRow) -o $(ROWCLA)

# Command: make C02CLABOT
# output: ********COMPILING CLASS VERSION************
# output: g++ -g -std=gnu++11 -Wpedantic testBottle.cpp testDateCla.cpp dateCla.cpp -o testDateCla
C02CLAROW: 
	$(claRowMsg) 
	$(claRowCmp)
	


######################### Command: make C02STRROW ###############################
# Complies the testBottle file where the DATE is a Class 

# First, create a message to send to the user
strRowMsg = $(info ********COMPILING Challenge 2 testRow - Date STRUCT VERSION************)

# Put both cpp files into claCPP, since the .h files connect them.
# Note: bottle.h included in testBottle.cpp, and date.h included in bottle.h 
strRow = $(ROWSTR).cpp

# Next, indicate the compilation commands
# Put together, this becomes: g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla
strRowCmp =  $(C++) $(CFLAGS) $(strRow) -o $(ROWSTR)

# Command: make C02CLABOT
# output: ********COMPILING CLASS VERSION************
# output: g++ -g -std=gnu++11 -Wpedantic testBottle.cpp testDateCla.cpp dateCla.cpp -o testDateCla
C02STRROW: 
	$(strRowMsg) 
	$(strRowCmp)	



######################### Command: make challenge01 ###############################

# First, create a message to the user that this is for both versions
bothC01Msg = $(info ********COMPILING BOTH VERSIONS - Challenge 01 - WITH make challenge01************)

# Command: make challenge01 
# ********COMPILING BOTH VERSIONS - Challenge 01 - WITH make challenge01************
# g++ -g -std=gnu++11 -Wpedantic testDateStr.cpp -o testDateStr
# g++ -g -std=gnu++11 -Wpedantic testDateCla.cpp dateCla.cpp -o testDateCla

challenge01: 
	$(bothC01Msg) 
	$(strCmp) 			
	$(claCmp)


######################### Command: make challenge02 ###############################

# First, create a message to the user that this is for both versions
bothC02Msg = $(info ********COMPILING BOTH VERSIONS - Challenge 02 - WITH make challenge02************)

# Command: make challenge02
# ********COMPILING BOTH VERSIONS - Challenge 02 - WITH make challenge02************
# g++ -g -std=gnu++11 -Wpedantic testBottleStr.cpp -o testBottleStr
# g++ -g -std=gnu++11 -Wpedantic testQueueStr.cpp -o testQueueStr
# g++ -g -std=gnu++11 -Wpedantic testBottleCla.cpp dateCla.cpp -o testBottleCla
# g++ -g -std=gnu++11 -Wpedantic testQueueCla.cpp dateCla.cpp -o testQueueCla

challenge02: 
	$(bothC02Msg) 			
	$(strBotCmp)
	$(strRowCmp)
	$(claBotCmp) 
	$(claRowCmp)


######################### Command: make challenge02 ###############################

# First, create a message to the user that this is for both versions
allMsg = $(info ********COMPILING BOTH VERSIONS - Challenge 01 and 02 - WITH make all************)

# Command: make challenge02
# ********COMPILING BOTH VERSIONS - Challenge 02 - WITH make challenge02************
# g++ -g -std=gnu++11 -Wpedantic testBottleStr.cpp -o testBottleStr
# g++ -g -std=gnu++11 -Wpedantic testQueueStr.cpp -o testQueueStr
# g++ -g -std=gnu++11 -Wpedantic testBottleCla.cpp dateCla.cpp -o testBottleCla
# g++ -g -std=gnu++11 -Wpedantic testQueueCla.cpp dateCla.cpp -o testQueueCla

all: 
	$(aMsg) 
	$(strCmp) 			
	$(claCmp)	
	$(strBotCmp)
	$(strRowCmp)
	$(claBotCmp) 
	$(claRowCmp)


######################### Command: make clean ###############################
cleanMsg = $(info ********make clean************)
cleanAll = $(RM) $(DATESTR) $(DATECLA) $(BOTSTR) $(BOTCLA) $(ROWSTR) $(ROWCLA) *.o *.out

# Command: make cleanest
# Output: ********CLEANEST VERSION************
# Output: rm -f testDateStr *.o *.out
# Output: rm -f testDateCla *.o *.out
clean: 
	$(cleanMsg)
	$(cleanAll)