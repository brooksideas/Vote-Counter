#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <limits>
#include <sstream>

using namespace std;
template <typename t1, typename t2 = int>
class hashMap
{
public:
    struct hashPair
    {
        t1 key;
        t2 value;
        hashPair *link;
    };
    struct iteratorPair
    {
        t1 *key;
        t2 *value;
        iteratorPair *link;
    };
    class iterator
    {
    public:
        friend class hashMap; // can access private members of hashMap class.
        iterator();
        const iterator &operator++(int);
        bool operator==(const iterator &) const;
        bool operator!=(const iterator &) const;
        t1 first();
        t2 second();

    private:
        iterator(iteratorPair *);
        iteratorPair *element;
    };
    hashMap();
    ~hashMap();
    t2 &operator[](t1);
    iterator begin() const;
    iterator end() const;

private:
    void resize();
    int h(std::string) const;
    int items;
    int size;
    hashPair **table;
    iteratorPair *head;
    int currentLineNumber;
};
// Seek to the required line in the file text and parse as a string and return value
std::string GotoFileLine(std::ifstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Return the specific line as a string value
    std::string lineContent((std::istreambuf_iterator<char>(file)),
                            (std::istreambuf_iterator<char>()));
    return lineContent;
}

template <typename t1, typename t2>
hashMap<t1, t2>::hashMap()
{
    cout << "Constructor" << endl;
    int numberOfCandidates;

    ifstream infile;

    string read_file_name("input01.txt");

    infile.open(read_file_name);
    // set default values
    size = 5;
    items = 0;

    if (infile.good())
    {
        // Get the number of candidates which is always on the second line
        numberOfCandidates = stoi(GotoFileLine(infile, 2)); // converts to integer
        cout << "Candidates" << numberOfCandidates << endl;
    }

    // Array of pointers to info struct
    // of size
    table = new hashPair *[size];

    // Initialize pointer array to NULL
    for (int i = 0; i < size; ++i)
    {
        *(table + i) = NULL;
    }

    // Loop through the candidates list and assign them all as key value pairs in the Hash Map
    // Candidate / Party value always starts from Line 3
    for (int i = 3; i < (numberOfCandidates + i); i + 2)
    {
        currentLineNumber = i;                              // holds the current read line of the file
        string fileLineKey = GotoFileLine(infile, i);       // this is the unique candidate key
        string fileLineValue = GotoFileLine(infile, i + 1); // this is the unique candidate key

        this->operator[](fileLineKey); // pass in the returned values to the overloaded operator
    }
}

template <typename t1, typename t2>
hashMap<t1, t2>::~hashMap()
{
    // set the destructor values
    // hashPair *temp = new hashPair;
    // temp = head;
    // head = head->key;
    // delete temp;
    // for (int i = 0; i < rows; i++)
    //     {
    // for (int j = 0; j < cols; j++)
    //     {
    //     delete table[i][j]; // delete stored pointer
    //     }
    // delete[] table[i]; // delete sub array
    // }
    // delete[] table; // delete outer array
    // table = NULL;
}

// insert/find for the hash map,
template <typename t1, typename t2>
t2 &hashMap<t1, t2>::operator[](t1 key)
{

    // Successful so insert into the hashmap
    cout << "Op KEY ===>" << key << endl;

    // Create a new hashpair node
    hashPair *node = new hashPair;

    // To track last node of the list
    hashPair *prev = NULL;
    // Input the Key value pair data

    node->key = key;    // Marylin Manson
    node->value = t2(); // default value = 0
    node->link = NULL;  // NULL
    cout << "Node KEY VAL ===>" << node->key << endl;
    cout << "NV " << node->value << endl;
    cout << " NL" << node->link << endl;

    // check table X position
    int x = h(key);
    cout << "Node X ===>"
         << " " << x << endl;
    cout << "Node TABLE X ===>"
         << " " << table[x] << endl;

    double loadFactor = items / size;

    if (table[x] == NULL || table[x] == 1 || table[x] == 2)
    {
        if (loadFactor >= 0.5) // 7 / 5  = 0 , 1/5 = 0.2 , 2/5 = 0.4 , 3/5 = 0.6
        {
            resize();
        }
    }
    // If the node is first
    if (*(table + 1) == NULL)
    {
        *(table + 1) = node;
    }
    else
    {
        prev->link = node;
    }
    prev = node;
}

template <typename t1, typename t2>
typename hashMap<t1, t2>::iterator hashMap<t1, t2>::begin() const
{
    return head = head->link;
}

template <typename t1, typename t2>
typename hashMap<t1, t2>::iterator hashMap<t1, t2>::end() const
{
    return NULL;
}

template <typename t1, typename t2>
void hashMap<t1, t2>::resize()
{
    table = table * table;
}

template <typename t1, typename t2>
int hashMap<t1, t2>::h(std::string key) const
{
    int value;
    int stringSize = key.size();
    int stringASCIISum = 0;
    // Loop through the given string and add up the ASCII values
    for (int i = 0; i < key.size(); i++)
    {
        cout << "\nThe ASCII Value of " << key[i] << " = " << (int)key[i];
        stringASCIISum = stringASCIISum + key[i];
    }

    // mods the ASCII sum by it by the string size and return value
    value = stringASCIISum % size; // stringSize;
    return value;
}

template <typename t1, typename t2>
hashMap<t1, t2>::iterator::iterator()
{
    element = NULL;
}

template <typename t1, typename t2>
hashMap<t1, t2>::iterator::iterator(iteratorPair *P)
{
    element = P;
}

template <typename t1, typename t2>
const typename hashMap<t1, t2>::iterator &hashMap<t1, t2>::iterator::operator++(int)
{
    // operator overloading
    hashPair temp = *this;
    ++*this;
    return temp;
}

template <typename t1, typename t2>
bool hashMap<t1, t2>::iterator::operator==(const hashMap<t1, t2>::iterator &rhs) const
{
    if (this->element == rhs.element)
        return true;

    return false;
}

template <typename t1, typename t2>
bool hashMap<t1, t2>::iterator::operator!=(const hashMap<t1, t2>::iterator &rhs) const
{
    if (this->element == rhs.element)
        return false;

    return true;
}

template <typename t1, typename t2>
t1 hashMap<t1, t2>::iterator::first()
{
    return *(element->key);
}

template <typename t1, typename t2>
t2 hashMap<t1, t2>::iterator::second()
{
    return *(element->value);
}

int main()
{
    /* Temporarly disabled inputs
    string entry;
     cout << "Enter filename: " << endl;
     cin >> entry;
    */

    // Create an Instance
    hashMap<std::string, int> myHash;
}