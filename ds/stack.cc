#include <iostream>

using namespace std;

#define DISPLAY(X) for(int _i=0; _i<X; _i++) cout<<'*'; cout<<endl;

typedef int T;

class Stack{
    private:
        size_t size;
        int top;
        T *stack;
    public:
        Stack(size_t sz);
        Stack(const Stack &s);
        //void operator=(const Stack &s);
        Stack& operator= (const Stack &s);
        ~Stack();

        bool isfull() const;
        bool isempty() const;
        void display() const;

        void push(const T &element);
        void pop(T &item);
        int max() const;

        class Overflow{ };
        class Underflow{ };
};

Stack::Stack(size_t sz):size(sz), top(-1), stack(new T[sz])
{
    cout<<"Created a new stack @ "<<this<<endl;
}

Stack::Stack(const Stack &s):size(s.size), top(s.top), stack(new T[s.size])
{
    int i;
    cout<<"copy constructor overloaded and created new object @ "<<this<<endl;

    // copy each element form original stack to this new one
    for(i=0; i <= s.top; ++i)
        stack[i] = s.stack[i];
}

Stack& Stack::operator= (const Stack &s)
{
    cout<<"Assignment operator overloaded with our own and new "<<endl;
    if(this == &s) {
        cout<<"SelF Assignement done"<<endl;
        return *this;
    }

    top = s.top;
    size = s.size;
    delete []stack;
    stack = NULL;

    stack = new T[s.size];
    for(int i=0; i<s.size; i++)
        stack[i] = s.stack[i];
}

/*void Stack::operator=(const Stack &ref)
{
    int i;
    cout<<"Assignement operator overloaded"<<endl;
    if(this == &ref) {
        cout<<"Self Assignment"<<endl;
        return;
    }

    top = ref.top;
    size = ref.size;
    delete []stack;
    stack = NULL;

    stack = new T[ref.size];
    for(i=0; i<ref.size; i++)
        stack[i] = ref.stack[i];
}*/

Stack::~Stack()
{
    cout<<"Destructor invoked for : "<<this<<endl;
    delete []stack;
}

void Stack::display()const
{
    int i;

    if(isempty()) {
        cout<<"Stack empty, Nothing to display"<<endl;
        return;
    }

    cout<<"Stack elements are : ";
    for(i=0; i <= top; i++)
        cout << stack[i] << " ";
    cout<<endl;
}

bool Stack::isfull() const
{
    return (top+1 == size ? 1 : 0);
}

bool Stack::isempty() const
{
    return (top == -1 ? 1 : 0);
}

void Stack::push(const T &element)
{
    if(isfull()) {
        cout<<"Stack is full, Can't insert"<<endl;
        throw Stack::Overflow();
        return;
    }
    stack[++top] = element;
}

void Stack::pop(T &item)
{
    if(isempty()) {
        cout<<"Stack empty, nothing to delete"<<endl;
        throw Stack::Underflow();
    }
    item = stack[top--];
}

int Stack::max() const
{
    return size;
}

int main()
{
    Stack s(5);
    Stack s1 = s, s2(1);
    int i, item;

    s1.display();
    s.display();

    for(i=0; i<s.max(); i++)
        s.push(i + 76);

    s2 = s;
    
#if 0
//  s.push(765);
    for(i=0; i < s.max() + 1; i++) {
        try {
            //s.push(item);
            //s.pop(item);
            //throw exception();
            //throw 20;
            cout<<"Popped item : "<<item<<endl;
        } catch(exception &e) {
            cout<<"Exception caught as : "<<e.what()<<endl;
        } 
        catch(Stack::Underflow) {
            cout<<"Stack underflow detected"<<endl;
            break;
        } catch(Stack::Overflow) {
            cout<<"Stack overflow detected" <<endl;
            break;
        } catch(...) {
            cout<<"generic Exception caught" <<endl;
            throw; // rethrowing an exception
        }
    }

    s.display();
    s1.display();

    Stack s2(7);
    s2 = s;

    s.display();
    s1.display();
    s2.display();

    DISPLAY(10);
    typedef void (Stack::*spush) (int) ;
    spush sp = &Stack::push;
    s2.pop();
    (s2.*sp)(765);
    (s2.*sp)(775);
    s2.display();

    Stack s3(3);
    s3.pop();

    DISPLAY(10);
#endif

    return 0;
}
