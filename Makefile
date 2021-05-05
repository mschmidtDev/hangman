CC = cc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = end_game.o game_state.o input.o main.o gamemode.o timer.o name_helper.o
TARGET = hangman

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) *~
