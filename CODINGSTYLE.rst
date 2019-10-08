.. _codingstyle:

PINT library coding style
=========================

After much delibiration, the counsel of PINT coding style has made the 
following decrees regarding formatting of our code.

Note: The afformentioned counsel is currently comprised of one person.

1) Indentation
--------------

Tabs are 4 characters. 
Expand tabs to spaces to maintain readability across editors.

Indenting is required inside loops, if statements, etc. 

Do not indent within namespace brackets if implementing a name space. Do not 
indent within class brackets if declaring a class. Simply leave an empty line 
between braces for these.

.. code-block:: c

    namespace noop
    {

    class Cleg
    {

    public:
        int bar;

        Cleg();
        void foo();

    private:
        int _qux;

    };

    }

2) Braces and Spaces
----------------------------

Classes, functions, loops, if statements, etc. that take multiple statements to 
define must have opening and closing braces on separate lines.
This makes commenting out conditionals easier and encourages reducing the number 
of special cases in code.

Conditionals like if statements should have a space before the opening paranthesis.

Comments should have a space before actual text.

.. code-block:: c

    inline char myep(int bar, char * zork) { return zork[bar]; }

    void foo(int qux) // TODO: implement PINT
    {
        if (bar)
        {
            // do something
        }
        else
        {
            // do thingsome
        }

        do
        {
            // something do
        }
        while (!bar);
    }
