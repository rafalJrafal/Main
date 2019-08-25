#include "../inc/Except.h"

void newTerminate() {
	printf("terminated!!!");
}

void Except::run() {
	void (*p) () = newTerminate;
	std::set_terminate(newTerminate);
	
	try {
		//throwBase();
		//throwChild();
		//throw 3;	
		throwInternalChild();
	}
	catch (ExceptionChild & c) {
		log->log("catch (ExceptionChild & c) %s", c.toStr().c_str());
	}
	catch (ExceptionBase & b){
		log->log("catch (ExceptionBase & b) %s", b.toStr().c_str());
	}
	catch (InternalExceptionChild & c) {
		log->log("catch (InternalExceptionChild & c) %s", c.toStr().c_str());
	}
	catch (InternalExceptionBase & b) {
		log->log("catch (InternalExceptionBase & b) %s", b.toStr().c_str());
	}
	/*catch (...){
		log->log("defauld catch");
	}*/
}
