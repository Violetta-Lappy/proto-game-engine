#include <ae/LoggerConsole.h>

int main(int argc, char* argv[]) {		
	LoggerConsole::Info("Hello There");
	LoggerConsole::Warn("Hello There");
	LoggerConsole::Caution("Hello There");
	LoggerConsole::Fatal("Hello There");
	return 0;
}