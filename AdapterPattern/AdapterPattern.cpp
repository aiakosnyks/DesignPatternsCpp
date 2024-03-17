#include <string>
#include <iostream>

//Legacy printer (Adaptee)
class LegacyPrinter {
	public:
		void printInUpperCase(const std::string& text) {
			std::cout << "Printing:" << text << std::endl;
		}
};

//Modern computer (Client)
class ModernComputer {
public:
	void sendCommand(const std::string& command) {
		std::cout << "Sending command: " << command << std::endl;
	}
};

//Adapter class to make the LegacyPrinter compatible with Modern Computer
class PrinterAdapter {
	private:
		LegacyPrinter legacyPrinter;

	public:
		void sendCommand(const std::string& command)
		{
			//Convert command to uppercase and pass it to the LegacyPrinter
			std::string uppercaseCommand = command;
			for (char& c : uppercaseCommand) {
				c = std::toupper(c);
			}
			legacyPrinter.printInUpperCase(uppercaseCommand);
		}
};

int main()
{
	ModernComputer computer;
	PrinterAdapter adapter;

	computer.sendCommand("Print this in lowercase");
	adapter.sendCommand(
		"Print this in lowercase (adapted)");

	return 0;
}

