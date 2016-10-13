#include "DebugLogger.h"
using namespace OriEngine;
DebugLogger *DebugLogger::logInstance(nullptr);
DebugLogger::DebugLogger(){
	logFile = nullptr;
}
DebugLogger::~DebugLogger(){
	clean();
}
DebugLogger& DebugLogger::getInstance(){
	if (logInstance == nullptr) {
		logInstance = new DebugLogger();
	}
	return *logInstance;
}
void DebugLogger::clean() {
	if (logFile != nullptr) {
		logFile->close();
		delete logFile;
		logFile = nullptr;
	}
}
void OriEngine::DebugLogger::setLogFile(std::string & filename){
	clean();
	logFile = new std::ofstream(filename.c_str());
}
void DebugLogger::log(const MsgType threat, const std::string & _class, const std::string Method, const std::string & filename, const int line, const std::string & msg) {
	if (logFile == nullptr) {
		setLogFile(logFileName);
	}else{
		//switch statement using what type of message i should be getting
		switch (threat) {
			// for info print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
		case MsgType::INFO:
			(*logFile) << "INFO: " << _class << "::" << Method << "() - " << "\n File :: " << filename << "\n Line :: " << line << " Message :: " << msg << "\n";
			logFile->flush();
			// break for next case
			break;
			// for warning print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
		case MsgType::WARN:
			*logFile << "WARNING: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n";
			// break for next statement
			logFile->flush();
			break;
			// for Error print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
		case MsgType::FATAL_ERROR:
			*logFile << "FATAL_ERROR: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n";
			// break for next statement
			logFile->flush();
			break;
			// for NONE print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
		case MsgType::NONE:
			*logFile << "NONE: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n";
			logFile->flush();
		case MsgType::TRACE:
			*logFile << "TRACE: " << _class << "::" << Method << "() - " << "File :: " << filename << ", Line :: " << line << " Message :: " << msg << "\n";
			//final break
			logFile->flush();
			break;
		}
	}
}
