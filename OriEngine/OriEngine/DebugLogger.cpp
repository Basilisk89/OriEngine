#include "DebugLogger.h"
using namespace OriEngine;
std::unique_ptr<DebugLogger>DebugLogger::logInstance(nullptr);
DebugLogger::DebugLogger():logFile(std::ofstream("$(ProjectDir)/../Debug/DebugLog.log")){
	
}
DebugLogger::~DebugLogger(){
	clean();
}
DebugLogger& DebugLogger::getInstance(){
	if (logInstance.get() == nullptr) {
		logInstance.reset(new DebugLogger());
	}
	return *logInstance.get();
}
void DebugLogger::removeInstance(){
	if (logInstance.get() != nullptr) {
		logInstance.release();
		logInstance = nullptr;
	}
}
void DebugLogger::clean() {
	// file stream cleaner obj
	std::fstream cleaner;
	// open the file for the cleaner obj to do its job
	cleaner.open("$ProjectDir/../Debug/DebugLog.log", std::fstream::out);
	// then close it , cleaning the whole file
	cleaner.close();
}
void DebugLogger::log(const MsgType threat, const std::string & _class, const std::string Method, const std::string & filename, const int line, const std::string & msg){
	
	//switch statement using what type of message i should be getting
	switch (threat) {
		// for info print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case MsgType::INFO:
		logFile << "INFO: " << _class << "::" << Method << "() - " << "\n File :: " << filename << "\n Line :: " << line << " Message :: " << msg << "\n\n";
		// break for next case
		break;
		// for warning print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case MsgType::WARN:
		logFile << "WARNING: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n\n";
		// break for next statement
		break;
		// for Error print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case MsgType::ERROR:
		logFile << "ERROR: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n\n";
		// break for next statement
		break;
		// for FATAL_ERROR print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case MsgType::NONE:
		logFile << "FATAL ERROR: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n\n";
		//final break
		break;
		logFile.flush();
	}
}

