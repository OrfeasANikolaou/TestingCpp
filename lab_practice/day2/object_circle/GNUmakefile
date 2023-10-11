CC = g++
CFLAGS = -Wall -Werror -Wextra -Wshadow -Wstrict-aliasing -Wstrict-overflow -pedantic
S = ./source/
ALL = $(S)master.cpp $(S)object_circle.cpp
OUT_NAME = object_circle
object_circle: $(ALL) 
	$(CC) $(CFLAGS) $(ALL) -o $(OUT_NAME)
