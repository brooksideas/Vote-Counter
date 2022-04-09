#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
#include<map>
using namespace std;
template <typename t1, typename t2>
class hashMap
{
public:
struct hashPair
{
t1 key;
t2 value;
hashPair * link;
};
struct iteratorPair
{
t1 * key;
t2 * value;
iteratorPair * link;
};
class iterator
{
public:
friend class hashMap;
iterator ();
const iterator& operator ++(int);
bool operator ==( const iterator &) const;
bool operator !=( const iterator &) const;
t1 first ();
t2 second ();
private:
iterator(iteratorPair *);
iteratorPair * element;
};
hashMap ();
~hashMap ();
t2& operator [](t1);
iterator begin () const;
iterator end() const;
private:
void resize ();
int h(std:: string) const;
int items;
int size;
hashPair ** table;
iteratorPair * head;
};


template <typename t1, typename t2>
hashMap<t1,t2>::hashMap()
{
    //set default values
    size=5;
    items=0;
    head=NULL;
    table=new hashPair *[size];
    table=NULL;
}


template<typename t1, typename t2>
hashMap<t1,t2>::~hashMap()
{
    //set the destructor values
    hashPair *temp= new hashPair;
    temp=head;
    head=head->key;
    delete temp;
    // for (int i = 0; i < rows; i++) 
    //     {
    // for (int j = 0; j < cols; j++) 
    //     {
    //     delete table[i][j]; // delete stored pointer
    //     }
    // delete[] table[i]; // delete sub array
    // }
    delete [] table; //delete outer array
    table = NULL;
}


template<typename t1, typename t2>
t2& hashMap<t1,t2>::operator[](t1 key)
{
    double loadFactor=items/size;
    if(loadFactor>=0.5)
    {
        resize();
    }
    int x=h(key);
    if(table[x]==NULL||table[x]==1||table[x]==2)
    {

    }
}

template<typename t1, typename t2>
typename hashMap<t1,t2>::iterator hashMap<t1,t2>::begin()const
{
    return head=head->link;
}


template<typename t1, typename t2>
typename hashMap<t1,t2>::iterator hashMap<t1,t2>::end() const
{
    return NULL;
}


template<typename t1,typename t2>
void hashMap<t1,t2>::resize()
{
    table=table*table;
}


template<typename t1, typename t2>
int hashMap<t1,t2>::h(std::string key)const
{
    int value=int(key);
    return value;
}


template<typename t1,typename t2>
hashMap<t1,t2>::iterator::iterator()
{
    element=NULL;
}


template<typename t1, typename t2>
hashMap<t1,t2>::iterator::iterator(iteratorPair *P)
{
    element=P;
}


template<typename t1, typename t2>
const typename hashMap<t1,t2>::iterator& hashMap<t1,t2>::iterator::operator++(int)
{
    //operator overloading
    hashPair temp= *this;
    ++*this;
    return temp;
}


template<typename t1, typename t2>
bool hashMap<t1,t2>::iterator::operator==(const hashMap<t1,t2>::iterator &rhs) const
{
    if (this->element==rhs.element)
    return true;
    
    return false;
}


template<typename t1,typename t2>
bool hashMap<t1, t2>::iterator::operator!=(const hashMap <t1,t2>::iterator &rhs) const
{
    if(this->element==rhs.element)
    return false;
    
    return true;
}


template<typename t1, typename t2>
t1 hashMap<t1,t2>::iterator::first()
{
    return *(element->key);
}


template<typename t1,typename t2>
t2 hashMap<t1,t2>::iterator::second()
{
    return *(element->value);
}

int main()
{
    string entry;
    cout<<"Enter filename: "<<endl;
    cin>>entry;
    ifstream fin;
    string read_file_name(entry);
    fin.open(read_file_name);
    
    fin.close();
}