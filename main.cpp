#include <iostream>

#include "LogSystem/inc/LogSystem.h"
#include "ParameterFile/inc/ParameterFile.h"
#include "ParameterFile/inc/ParameterFileDataType.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LogSystem::LogSystem l;
	l.log("aaa");
	
	Parameter::Parameter p("param.txt");
	p.readParameters();
	ParemeterFileData<string> * param = static_cast<ParemeterFileData<string> *>(p.getValue("exampleStringValue"));
	
	printf("----> %s <----\n", param->getValue().c_str());
	return 0;
}
