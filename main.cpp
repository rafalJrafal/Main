#include <iostream>

#include "SystemCalls/inc/Memory.h"

#include "LogSystem/inc/LogSystem.h"
#include "ParameterFile/inc/ParameterFile.h"
#include "ParameterFile/inc/ParameterFileDataType.h"
#include "Operator/inc/ClassX.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LogSystem::LogSystem * l = LogSystem::LogSystem::instance();
	l->log("aaa");
	
	Parameter::Parameter p("param.txt");
	p.readParameters();
	
	int x = p.getVal<int>("exampleIntValue");
	printf("----> %d <----\n", x);
	
	OperatorTest::ClassX a, b, c, d, e, f, g, h;
	a = 3;
	b = a;
	c = a + b;
	

	return 0;
}
