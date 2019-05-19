# include <cstdlib> //std::rand()
# include <vector> //std::vector<>
# include <list> //std::list<>
# include <iostream> //std::cout
# include <iterator> //std::ostream_iterator<>
# include <algorithm> //std::reverse, std::generate

int main ()
{
    //Initializes a vector of size 10
    std::vector<int> v_0(10);

    //every Element in v_0 gets a random value assigned
    for (auto& v : v_0) {
        v = std::rand();
    }

    //Prints the vector 
    std::copy(std::cbegin(v_0), std::cend(v_0), std::ostream_iterator<int>(std::cout, "\n"));

    //Creates two new lists, l_0 with the same elements as v_0 and l_1 with the same elements as l_0
    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));

    //Reverses l_1 copies l_1 and prints it to the console
    std::reverse(std::begin(l_1), std::end(l_1));
    std::copy(std::cbegin(l_1),std::cend(l_1), std::ostream_iterator<int>(std::cout, "\n"));

    //Sorts the list
    l_1.sort();
    std::copy(l_1.cbegin(), l_1.cend(), std::ostream_iterator<int>(std::cout, "\n"));

    //Fills v_0 with random numbers and prints it
    std::generate(std::begin(v_0), std::end(v_0), std::rand);
    std::copy(v_0.crbegin(), v_0.crend(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}

/* std::generate:
It basically asigns each element in a given range a value of the function object g
Function object g is std::rand in our example
*/