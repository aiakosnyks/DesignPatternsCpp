#include <iostream>
class Singleton {
	public:

		//Static method to access the singleton instance
		static Singleton& getInstance()
		{
			//If the instance doesn't exist, create it
			if (!instance) {
				instance = new Singleton();
			}
			return *instance;
		}

		//Public method to perform some operation
		void someOperation()
		{
			std::cout
				<< "Singleton is performing some operation."
				<< std::endl;
		}

		//Delete the copy constructor and assignement
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;

	private:
		//Private constructor to prevent external external instantiation
		Singleton()
		{
			std::cout << "Singleton instance created."
				<< std::endl;
		}

		//Private destructor to prevent external deletion
		~Singleton()
		{
			std::cout << "Singleton instance destroyed."
				<< std::endl;
		}
		static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

int main()
{
	//Access the Singleton instance
	Singleton& singleton = Singleton::getInstance();
	singleton.someOperation(); // Singleton& singleton deðil de Singleton* singleton olsaydý burada singleton -> someOperation()
	// diye çaðýrmamýz gerekirdi

	//Attempting to create another instance will not work
	//Singleton anotherInstance; //This would not compile

	return 0;
}