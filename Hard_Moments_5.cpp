#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <cstring>

///////////// exercise 1

template <typename T>
void function1(T it_begin, T it_end) {
	std::set<std::string> str_set;
	for (; it_begin != it_end; it_begin++)
	{
		str_set.insert(*it_begin);
	}
	copy(str_set.begin(), str_set.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
}

/////////////

int main()
{
	//////////// exercise 1

	std::vector<std::string> str_vec = { "hi" , "hello" , "hey" , "hi" };
	std::deque<std::string> str_deq = { "bye" , "goodbye" , "bye" , "good-bye" };
	std::vector<std::string>::const_iterator v_it_b = str_vec.begin();
	std::vector<std::string>::const_iterator v_it_e = str_vec.end();
	auto d_it_b = str_deq.begin();
	auto d_it_e = str_deq.end();
	function1(str_vec.begin(), str_vec.end());
	function1(begin(str_deq), end(str_deq));
	function1(v_it_b, v_it_e);
	function1(d_it_b, d_it_e);

	///////////

	////////// exercise 2

	std::multimap<int, std::string> words;
	std::string long_prons;
	getline(std::cin, long_prons);
	size_t del = 0;
	std::string pron;

	while ((del = long_prons.find(".")) != std::string::npos)
	{
		pron = long_prons.substr(0, del +1);
		long_prons.erase(0, del +1);
		words.insert({ pron.size(), pron });
	}
	
	for_each(words.begin(), words.end(),
		[](std::pair<int, std::string> item) {
			std::cout << item.first << " " << item.second << "\n";
		});

	//////////

	system("pause");
	return 0;
}

