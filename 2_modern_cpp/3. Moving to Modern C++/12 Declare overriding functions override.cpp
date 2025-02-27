#include <vector>

class Base{
public:
    virtual void mf1() const;
    virtual void mf2(int x);
    virtual void mf3() &;
    virtual void mf4() const;
};

class Derived : public Base{
public:
    virtual void mf1() const override;
    virtual void mf2(int x) override;
    virtual void mf3() & override;
    virtual void mf4() const override;
};

class Widget{
public:
    using DataType = std::vector<double>;
    // DataType& data() // regular
    // {return values;}
    DataType& data() & // lvalue
    {return values;}
    DataType data() && // rvalue
    {return std::move(values);}
private:
    DataType values;
};

Widget makeWidget(){
    return Widget();
}

int main(){
    Widget w;
    auto vals1 = w.data(); // vals1 is lvalue
    Widget makeWidget();
    auto vals2 = makeWidget().data(); // vals2 is rvalue

    return 0;
}

// Things to Remember
// • Declare overriding functions override.
// • Member function reference qualifiers make it possible to treat lvalue and
// rvalue objects (*this) differently.