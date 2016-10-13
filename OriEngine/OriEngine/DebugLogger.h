#ifndef DEBUGLOGGER_H
#define DEBUGLOGGER_H
#include <memory>
#include <fstream>
#include <string>
namespace OriEngine {
	class DebugLogger {
	public:
		 enum MsgType {NONE,TRACE,FATAL_ERROR,WARN,INFO};
		
		static DebugLogger& getInstance();
        DebugLogger();
		void log(const MsgType threat,const std::string& _class, const std::string Method, const std::string& filename,const int line, const std::string& msg);
		void clean();
		void setLogFile(std::string &filename);
	private:
		static DebugLogger* logInstance;
		std::string logFileName = "debug/debugLog.log";
		std::ofstream* logFile;
		~DebugLogger();
	};
}
#endif
