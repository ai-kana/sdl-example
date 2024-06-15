CC = cc
BUILD = build
LIBS = -l SDL2 -l GL -l SDL2_image
FLAGS = -Wall -Wextra $(LIBS)

3dtest: $(BUILD)/main.o
	gcc $(FLAGS) -o $@ $<

$(BUILD)/main.o: main.c
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<
