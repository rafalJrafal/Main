#ifndef EXCEPT_H
#define EXCEPT_H

#include "..\..\Operator\inc\BaseClass.h"
#include "ExceptionChild.h"

using OperatorTest::BaseClass;

void newTerminate();

class Except : public BaseClass {
	public:
		Except() try : BaseClass("ExceptionLog.txt")  {
			//throw 3333;
		}
		catch(...) {
			log->log("caught");
			throw "ala ma kota";
		}
		void run();
		void throwBase() throw(ExceptionBase) {
			throw ExceptionBase();
		}
		void throwChild() {
			throw ExceptionChild();
		}
		void throwInternalBase() {
			throw InternalExceptionBase();
		}
		void throwInternalChild() {
			throw InternalExceptionChild();
		}
		
	private:
		
		class InternalExceptionBase {
			public:
				virtual std::string toStr() {
					return "InternalExceptionBase";
			}
		};
		
		class InternalExceptionChild : public InternalExceptionBase {
			public:
				virtual std::string toStr() {
					return "InternalExceptionChild";
			}
		};
};

#endif
