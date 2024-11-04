# **C++ STANDARD LIBRARY COMPLETE REFERENCE GUIDE**
## **by: Tanner Davison**

### **#include \<string>** //String Functions
**append()** //Add to end               **find()** //Find content
**assign()** //Assign new              **find_first_of()** //First occurrence
**at()** //Access char                 **find_last_of()** //Last occurrence
**back()** //Last char                 **front()** //First char
**begin()** //Start iterator           **insert()** //Insert content
**capacity()** //Get capacity          **length()** //Get length
**clear()** //Clear string             **max_size()** //Max size possible
**compare()** //Compare strings        **pop_back()** //Delete last char
**copy()** //Copy chars                **push_back()** //Add char to end
**c_str()** //Get C string             **replace()** //Replace portion
**empty()** //Check if empty           **resize()** //Change size
**end()** //End iterator               **size()** //Get length
**erase()** //Remove chars             **substr()** //Get substring
**swap()** //Swap content

### **#include \<cctype>** //Character Functions (char)
**isalnum()** //Check alphanumeric     **isgraph()** //Check graphical
**isalpha()** //Check alphabetic       **islower()** //Check lowercase
**isblank()** //Check blank char       **isprint()** //Check printable
**iscntrl()** //Check control char     **ispunct()** //Check punctuation
**isdigit()** //Check decimal digit    **isspace()** //Check whitespace
**isupper()** //Check uppercase        **isxdigit()** //Check hex digit
**tolower()** //Convert lowercase      **toupper()** //Convert uppercase

### FILE & STREAM OPERATIONS
#### **#include \<fstream>** - File Operations
**.close()** //Close stream            **.peek()** //View next char
**.eof()** //Check end                 **.putback()** //Put char back
**.fail()** //Check fail               **.read()** //Read block
**.get()** //Get char                  **.readsome()** //Read buffer
**.getline()** //Get line              **.seekg()** //Set in pos
**.good()** //Check state              **.sync()** //Sync buffer
**.ignore()** //Skip chars             **.tellg()** //Get in pos
**.open()** //Open stream              **.unget()** //Return char
**.is_open()** //Check open            **.write()** //Write block

#### **#include \<iostream>** - Stream Operations
**.flush()** //Flush buffer            **.seekp()** //Set out pos
**.put()** //Put char                  **.tellp()** //Get out pos
**.write()** //Write block             **.clear()** //Clear flags

#### **#include \<sstream>** - String Stream Operations
**getline()** //Get line from stream
**swap()** //Swap stream contents

#### **------String Streams Only-----**
**.str()** //Get/set content           **.rdbuf()** //Get buffer
**------------------------------**
