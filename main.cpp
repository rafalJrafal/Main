#include <iostream>

#include "SystemCalls/inc/Memory.h"

#define new new(__FILE__, __LINE__)


#include "SystemCalls/inc/MemoryMap.h"
#include "LogSystem/inc/LogSystem.h"
#include "ParameterFile/inc/ParameterFile.h"
#include "ParameterFile/inc/ParameterFileDataType.h"
#include "Operator/inc/ClassX.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	{
	//memoryMap.setPrintOtherDeallocations(false);
	int * xxczvd = new int;
	delete xxczvd;
	
	int * asd = new int [300];
	delete [] asd;
	
	
	LogSystem::LogSystem * l = LogSystem::LogSystem::instance();
	l->log("aaa");
	
	Parameter::Parameter p("param.txt");
	//p.readParameters();
	
	int x = p.getVal<int>("exampleIntValue");
	printf("----> %d <----\n", x);
	
	OperatorTest::ClassX a, b, c, d, e, f, g, h;
	
	OperatorTest::ClassX * a_p = new OperatorTest::ClassX();
	//OperatorTest::ClassX * a2_p = new (10) OperatorTest::ClassX;
	OperatorTest::ClassX * b_p = new OperatorTest::ClassX [2];
	OperatorTest::ClassX * c_p = new OperatorTest::ClassX [3]; 
	
	delete a_p;
	//delete a2_p;
	delete [] b_p;
	delete [] c_p;
	
	a = 3;
	b = a;
	c = a + b;
    }
   	static MemoryMap & memoryMap = MemoryMap::instance();
	memoryMap.printRemainingAllocations();


	return 0;
}
