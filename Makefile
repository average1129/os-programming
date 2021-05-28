PROJECT_NAME = STRING_FINDER

CC = gcc

#LD_FLAGS

SRC = project_main.c\
src/string_finder.c

INC = -Iinc

TEST_SRC = unity/unity.c\
test/test_string_finder.c

TEST_INC = -Iunity

.PHONY:all clean doc

all: $(SRC)
	$(CC)  $^ $(INC) -o $(PROJECT_NAME).out

test: $(SRC) $(TEST_SRC)
	$(CC)  $^ $(INC) $(TEST_INC) -o TEST_$(PROJECT_NAME).out

test_run: test
	./TEST_$(PROJECT_NAME).out

run:all
	./$(PROJECT_NAME).out $(ARGS)

doc:
	make -C doc

analyze:
	cppcheck -i unity --enable=all .

coverage:
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) $(TEST_INC) -o TEST_$(PROJECT_NAME).out
	./TEST_$(PROJECT_NAME).out
	gcov -a string_finder.c test_string_finder.c

clean:
	make clean -C doc 
	rm -rf *.out *.gcov *.gcno *.gcda