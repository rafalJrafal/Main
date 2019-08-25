#ifndef EXCEPTIONBASE_H
#define EXCEPTIONBASE_H

#include <string>

class ExceptionBase {
	public:
		virtual std::string toStr() {
			return "ExceptionBase";
		}
};

#endif
