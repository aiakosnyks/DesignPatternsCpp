#include <iostream>

//Receiver
class Receiver {
public:
	//Receiver class defines the action to be performed.
	void performAction()
	{
		std::cout << "Receiver is performing an action."
			<< std::endl;
	}
};

//Command interface
class Command {
public:
	//The execute method is declared in the Command interface.
	virtual void execute()=0;
};

//Concrete command
class ConcreteCommand : public Command {
	private:
		Receiver& receiver;

	public:
		//ConcreteCommand takes a referance to a Receiver object in its constructor.
		ConcreteCommand(Receiver& rec) : receiver(rec)
		{
		}
		
		void execute() { receiver.performAction(); }
};

//Invoker 
class Invoker {
	private:
		Command* command;

	public:
		//The setCommand method allows setting the command to be executed.
		void setCommand(Command* cmd) { command = cmd; }

		//The executeCommand triggers the execution of the command.
		void executeCommand() { command->execute(); }

		//command'i ref olarak alsayd�m setCommand'de : command(cmd) yapard�m
		//execute'ta da comman.execute() derdim de�il mi?
};

int main()
{
	//Create a Receiver instance.
	Receiver receiver;

	//Create a ConcreteCommand, passing the Receiver to it.
	ConcreteCommand command(receiver);

	//Create a Invoker.
	Invoker invoker;

	//Set the command to be executed by the invoker.
	invoker.setCommand(&command);

	//Execute the command.
	invoker.executeCommand();

	return 0;
}