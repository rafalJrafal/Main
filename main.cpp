#include <iostream>
#include <csetjmp>
#include <memory>

#include "SystemCalls/inc/Memory.h"

#define new new(__FILE__, __LINE__)


#include "SystemCalls/inc/MemoryMap.h"
#include "LogSystem/inc/LogSystem.h"
#include "ParameterFile/inc/ParameterFile.h"
#include "ParameterFile/inc/ParameterFileDataType.h"
#include "Operator/inc/ClassX.h"
#include "Operator/inc/Temp.h"
#include "Test/inc/Except.h"
#include "Test/inc/Aptr.h"

jmp_buf jumpBuffer;
int jmp_cnt = 0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	{
	//memoryMap.setPrintOtherDeallocations(false);

	
	setjmp(jumpBuffer);
	
	
	
	int * xxczvd = new int;
	delete xxczvd;
	
	int * asd = new int [300];
	delete [] asd;
	
	
	std::auto_ptr<Aptr> autp_p(new Aptr());
	
	NamespaceLog::LogSystem * l = NamespaceLog::LogSystem::instance();
	l->log("aaa");
	
	Parameter::Parameter p("param.txt");
	p.readParameters();
	
	int x = p.getVal<int>("exampleIntValue");
	printf("----> %d <----\n", x);
	
	autp_p->go();
	
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

	int in;

	OperatorTest::Temp<int, 3> xtmplate(2);
	OperatorTest::Temp<char> xtmplate2(2);
    xtmplate[4];
	
	if (jmp_cnt < 4) longjmp(jumpBuffer, jmp_cnt++);    
    
    Except * ex = 0;
	try{
		ex = new Except();
	}
	catch (const char * t) {
		printf("msg = %s, ptr = %p", t, ex);
	}
	
	ex->run();
	
	
	}
   	static MemoryMap & memoryMap = MemoryMap::instance();
	memoryMap.printRemainingAllocations();




	return 0;
}
