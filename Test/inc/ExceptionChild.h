#ifndef EXCEPTIONCHILD_H
#define EXCEPTIONCHILD_H

#include "ExceptionBase.h"

class ExceptionChild : public ExceptionBase {
	public:
		virtual std::string toStr() {
			return "ExceptionChild";
		}
	
};

#endif
