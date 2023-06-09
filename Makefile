CC=clang++
CFLAGS=-W -Wall -std=c++14
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_mixer

BINDIR=bin
SRCDIR=src
OBJDIR=obj

APP=engine
BIN=$(BINDIR)/$(APP)
OBJ=$(OBJDIR)/main.o $(OBJDIR)/Game.o $(OBJDIR)/TextureManager.o $(OBJDIR)/Entity.o \
		$(OBJDIR)/AbstractEntity.o $(OBJDIR)/LoaderParams.o \
		$(OBJDIR)/Player.o \
		$(OBJDIR)/Enemy.o

$(BIN): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/constants.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Game.o: $(SRCDIR)/Game.cpp $(SRCDIR)/Game.hpp $(SRCDIR)/constants.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/TextureManager.o: $(SRCDIR)/TextureManager.cpp $(SRCDIR)/TextureManager.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Entity.o: $(SRCDIR)/Entity.cpp $(SRCDIR)/Entity.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Player.o: $(SRCDIR)/Player.cpp $(SRCDIR)/Player.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Enemy.o: $(SRCDIR)/Enemy.cpp $(SRCDIR)/Enemy.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/AbstractEntity.o: $(SRCDIR)/AbstractEntity.cpp $(SRCDIR)/AbstractEntity.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/LoaderParams.o: $(SRCDIR)/LoaderParams.cpp $(SRCDIR)/LoaderParams.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	@rm -rf $(BIN)
	@rm -rf $(OBJ)
	@rmdir $(BINDIR)
	@rmdir $(OBJDIR)

.PHONY: run
run:
	./$(BIN)
