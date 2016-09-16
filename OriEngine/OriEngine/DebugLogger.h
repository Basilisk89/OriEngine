#ifndef DEBUGLOGGER_H
#define DEBUGLOGGER_H
#include <memory>
#include <fstream>
#include <string>
namespace OriEngine {
	class DebugLogger {
	public:
		static enum MsgType {NONE,TRACE,ERROR,WARN,INFO};
			~DebugLogger();
		static DebugLogger& getInstance();
		void removeInstance();
		void log(const MsgType threat,const std::string& _class, const std::string Method, const std::string& filename,const int line, const std::string& msg);
		void clean();
	private:
		static std::unique_ptr<DebugLogger> logInstance;
		 std::default_delete<DebugLogger> logDeleter;
		std::ofstream logFile;
		DebugLogger();
	
	};
}
#endif
