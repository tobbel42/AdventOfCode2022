CC=g++
C_FLAGS=
BIN=day09
BIN_BONUS=$(BIN)_bonus

all:$(BIN)

$(BIN): $(BIN).cpp
	$(CC) $(C_FLAGS) $< -o $@

bonus: $(BIN_BONUS)

$(BIN_BONUS): $(BIN_BONUS).cpp
	$(CC) $(C_FLAGS) $< -o $@

clean:
	rm -rf $(BIN) $(BIN_BONUS)
