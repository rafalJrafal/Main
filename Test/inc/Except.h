#ifndef EXCEPT_H
#define EXCEPT_H

#include "..\..\Operator\inc\BaseClass.h"
#include "ExceptionChild.h"

using OperatorTest::BaseClass;

void newTerminate();

class Except : public BaseClass {
	public:
		Except() : BaseClass("ExceptionLog.txt") {
		}
		void run();
		void throwBase() {
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
