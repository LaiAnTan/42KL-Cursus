#include <iostream>
#include <string>

using std::string;

class Warlock
{
	public:
		Warlock(string name, string title);
		~Warlock();

		string getName() const;
		string getTitle() const;

		void setTitle(const string &title);

		void introduce() const;

	private:

		Warlock(const Warlock &warlock);
		Warlock& operator = (const Warlock &warlock);

		string name;
		string title;
};