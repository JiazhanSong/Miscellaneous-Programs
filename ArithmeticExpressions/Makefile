CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = main.o integer.o var.o binary.o unary.o expression.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q2
 
${EXEC}:${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
 
-include ${DEPENDS}
