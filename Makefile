# CC = gcc
# GCOV = -fprofile-arcs -ftest-coverage
# REPORTDIR = gcovdir
# FILE_LIB = s21_string
# FILE1 = s21_string_test

# OS = $(shell uname)

# ifeq ($(OS),Darwin)
#     CHECKFLAGS=-lcheck
# else
#     CHECKFLAGS=-lcheck -lpthread -lrt -lm -lsubunit
# endif

# all: clean s21_string.a test

# s21_string.a: s21_string.c
# 	$(CC) -c s21_string.c -o s21_string.o 
# 	ar rcs s21_string.a s21_string.o

# test: s21_string.a
# 	$(CC) -c s21_string_test.c -o s21_string_test.o 
# 	$(CC) s21_string_test.o s21_string.o $(CHECKFLAGS) -o s21_test

# 	./s21_test

# gcov_report: s21_string.a
# 	rm -rf *.o *.a *.gcno *.gcda *.gcov *.info $(REPORTDIR)
# 	$(CC) $(GCOV) s21_string_test.c $(CHECKFLAGS) s21_string.c -o $(FILE_LIB) 

# 	./$(FILE_LIB)
# 	lcov -t "Unit-tests of $(FILE_LIB)" -o $(FILE_LIB).info -c -d .
# 	genhtml -o $(REPORTDIR) $(FILE_LIB).info

# clean:
# 	rm -rf *.o *.a *.gcno *.gcda *.gcov *.info $(REPORTDIR) s21_test s21_string

CC = gcc
GCOV = -fprofile-arcs -ftest-coverage
REPORTDIR = gcovdir
FILE_LIB = s21_string
FILE1 = s21_string_test

OS = $(shell uname)

ifeq ($(OS),Darwin)
    CHECKFLAGS=-lcheck
else
    CHECKFLAGS=-lcheck -lpthread -lrt -lm -lsubunit
endif

CFLAGS = -g

OBJFILES = s21_string.o s21_string_test.o

all: clean s21_string.a test

s21_string.a: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o 
	ar rcs s21_string.a s21_string.o

test: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(CHECKFLAGS) -o s21_test
	./s21_test

gcov_report: s21_string.a
	rm -rf *.o *.a *.gcno *.gcda *.gcov *.info $(REPORTDIR)
	$(CC) $(GCOV) s21_string_test.c $(CHECKFLAGS) s21_string.c -o $(FILE_LIB) 
	./$(FILE_LIB)
	lcov -t "Unit-tests of $(FILE_LIB)" -o $(FILE_LIB).info -c -d .
	genhtml -o $(REPORTDIR) $(FILE_LIB).info

clean:
	rm -rf *.o *.a s21_test s21_string

clean_all: clean
	rm -rf *.gcno *.gcda *.gcov *.info $(REPORTDIR)