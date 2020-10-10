// lab4: Родословная 
//

#include <iostream>
#include<string>
using namespace std;

class human
{
protected:
    string name;
    int age;
    int height;
public:
    human() : name("aaa"),age(0),height(0)
    {}
    human(string n,int a, int h) :name(n),age(a),height(h)
    {}
    ~human()
    {}
    void output_human()
    {
        cout << "\nMy name is "<<name<<endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
    }
};
class granny :virtual public human
{
protected:
    string eyes;
public:
    granny(string n, int a, int h, string e) : human(n, a, h), eyes(e)
    {}
    ~granny()
    {}
    void output_granny()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        cout << "My eyes are " << eyes << endl;
    }
};
class mum: public granny
{
protected:
    string hair;
public:
    mum(string n, int a, int h, string e,string ha) : human(n,a,h), granny(n,a,h,e), hair(ha)
    {}
    ~mum()
    {}
    void output_mum()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        cout << "My eyes are " << eyes << endl;
        cout << "My hair is " << hair << endl;
    }
};
class grandad:virtual public human
{
protected:
    bool freckles;
public:
    grandad(string n, int a, int h, bool f) : human(n, a, h), freckles(f)
    {}
    ~grandad()
    {}
    void output_grandad()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        if(freckles)
            cout << "I have got freckles"<< endl;
        else
            cout << "I haven't got freckles" << endl;
    }
};
class dad: public grandad
{
protected:
    string lashes;
public:
    dad(string n, int a, int h, bool f, string l) : human(n, a, h), grandad(n, a, h, f), lashes(l)
    {}
    ~dad()
    {}
    void output_dad()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        if (freckles)
            cout << "I have got freckles" << endl;
        else
            cout << "I haven't got freckles" << endl;
        cout << "My lashes are " << lashes << endl;
    }
};
class child:public dad,public mum
{
private:
    string hobby;
public:
    child(string n, int a, int h, bool f,string e, string l,string ha, string hob) : human(n, a, h), dad(n,a, h, f,l), mum(n, a, h, e,ha), hobby(hob)
    {}
    ~child()
    {}
    void output_child()
    {
        cout << "\nMy name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "My height is " << height << " cm" << endl;
        cout << "My eyes are " << eyes << endl;
        cout << "My hair is " << hair << endl;
        if (freckles)
            cout << "I have got freckles" << endl;
        else
            cout << "I haven't got freckles" << endl;
        cout << "My lashes are " << lashes << endl;
        cout << "My hobby is " << hobby << endl;
    }
};
int input_int(int min, int max)
{
    int i;
    bool fail = true;
    do
    {
        cin >> i;
        if (cin.fail()|| i < min || i>max || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}
int main()
{
    int age, height;
    bool freckles;
    string name, eyes, hair, lashes, hobby;
    cout << "What is your name? " << endl;
    rewind(stdin);
    getline(cin,name);
    cout << "How old are you? " << endl;
    age = input_int(0, 125);
    cout << "What is your height? " << endl;
    height = input_int(46, 272);
    cout << "What color are your eyes? " << endl;
    rewind(stdin);
    getline(cin, eyes);
    cout << "You have freckles. Choose true(1) or false(0)" << endl;
    freckles = input_int(0, 1);
    cout << "What color is your hair? " << endl;
    rewind(stdin);
    getline(cin,hair);
    cout << "What kind of eyelashes do you have? " << endl;
    rewind(stdin);
    getline(cin, lashes);
    cout << "What is your hobby? " << endl;
    rewind(stdin);
    getline(cin, hobby);
    child *c = new child(name,age,height,freckles,eyes,lashes,hair,hobby);
    c->output_child();
    delete c;
}

