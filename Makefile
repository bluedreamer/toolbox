# https://github.com/bluedreamer/cpp_project_skel
MF_VER=0.2
BINARY=toolbox_test
CC=gcc
CXX=g++
SRC=main.cpp toolbox.cpp toolbox_web.cpp trim_test.cpp find_and_replace_test.cpp urlencode_test.cpp html_build_query_test.cpp
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)
LIBS=
INCLUDES=
WARNINGS=-Wall -Wextra -Wpedantic -Weffc++ -Wconversion
DEBUG=-ggdb3
CXXFLAGS:=${DEBUG} -std=c++2a ${INCLUDES} ${WARNINGS}
LFLAGS=

${BINARY}: ${OBJS}
	${CXX} -o $@ ${OBJS} ${LIBS} ${LFLAGS}

clean:
	rm -f ${OBJS} ${DEPS} ${BINARY}

git_clean:
	git clean -xf

-include ${DEPS}

%.d: %.cpp
	${CXX} -MM $< -MF $@ ${CXXFLAGS}

# vim: ts=3 sw=3 ai et nohls mps=(\:),{\:},[\:],<\:> ff=unix ffs=unix bg=dark
