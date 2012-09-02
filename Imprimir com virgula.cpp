#include <iostream>
#include <locale>
#include <string>

using namespace std;

template<typename CharT>
class DecimalSeparator : public std::numpunct<CharT>
{
public:
    DecimalSeparator(CharT Separator)
    : m_Separator(Separator)
    {}

protected:
    CharT do_decimal_point()const
    {
        return m_Separator;
    }

private:
    CharT m_Separator;
};

int main(){

	double pi = 3.1415;
	std::cout.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	cout << pi << endl;

	return 0;
}