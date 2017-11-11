# dong modified
# 2017-10-12

CUR_DIR = $(shell pwd)

MY_INCLUDE_DIR  =  -I./include

all:mjpeg move_file

mjpeg:mjpeg.o jpeg.o mp3.o riff.o read_file.o
#	arm-xilinx-linux-gnueabi-g++ -o mjpeg mjpeg.o jpeg.o mp3.o riff.o read_file.o
	g++ -o mjpeg mjpeg.o jpeg.o mp3.o riff.o read_file.o

read_file.o:src/read_file.cpp include/read_file.h
#	arm-xilinx-linux-gnueabi-g++ $(MY_INCLUDE_DIR) -c src/read_file.cpp
	g++ $(MY_INCLUDE_DIR) -c src/read_file.cpp

mjpeg.o:src/mjpeg.cpp include/jpeg.h include/mp3.h include/riff.h
#	arm-xilinx-linux-gnueabi-g++ $(MY_INCLUDE_DIR) -c src/mjpeg.cpp
	g++ $(MY_INCLUDE_DIR) -c src/mjpeg.cpp

jpeg.o:src/jpeg.cpp include/jpeg.h
#	arm-xilinx-linux-gnueabi-g++ $(MY_INCLUDE_DIR) -c src/jpeg.cpp
	g++ $(MY_INCLUDE_DIR) -c src/jpeg.cpp

mp3.o:src/mp3.cpp include/mp3.h
#	arm-xilinx-linux-gnueabi-g++ $(MY_INCLUDE_DIR) -c src/mp3.cpp
	g++ $(MY_INCLUDE_DIR) -c src/mp3.cpp

riff.o:src/riff.cpp include/riff.h
#	arm-xilinx-linux-gnueabi-g++ $(MY_INCLUDE_DIR) -c src/riff.cpp
	g++ $(MY_INCLUDE_DIR) -c src/riff.cpp

clean:
	rm -f $(CUR_DIR)/lib/*.o $(CUR_DIR)/bin/mjpeg

move_file:
	mv *.o $(CUR_DIR)/lib/
	mv mjpeg $(CUR_DIR)/bin/
