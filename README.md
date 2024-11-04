# **C++ STANDARD LIBRARY COMPLETE REFERENCE GUIDE**
## **by: Tanner Davison**

### **#include \<string>** //String Functions
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| **append()**    | add to end        | **find()**        | find content |
| **assign()**    | assign new        | **find_first_of()** | first occurrence |
| **at()**        | access char       | **find_last_of()**  | last occurrence |
| **back()**      | last char         | **front()**       | first char |
| **begin()**     | Start iterator    | **insert()**      | Insert content |
| **capacity()**  | Get capacity      | **length()**      | Get length |
| **clear()**     | Clear string      | **max_size()**    | Max size possible |
| **compare()**   | Compare strings   | **pop_back()**    | Delete last char |
| **copy()**      | Copy chars        | **push_back()**   | Add char to end |
| **c_str()**     | Get C string      | **replace()**     | Replace portion |
| **empty()**     | Check if empty    | **resize()**      | Change size |
| **end()**       | End iterator      | **size()**        | Get length |
| **erase()**     | Remove chars      | **substr()**      | Get substring |
| **swap()**      | Swap content      |                   | |

### **#include \<cctype>** //Character Functions
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| **isalnum()**   | Check alphanumeric | **isgraph()**   | Check graphical |
| **isalpha()**   | Check alphabetic   | **islower()**   | Check lowercase |
| **isblank()**   | Check blank char   | **isprint()**   | Check printable |
| **iscntrl()**   | Check control char | **ispunct()**   | Check punctuation |
| **isdigit()**   | Check decimal digit| **isspace()**   | Check whitespace |
| **isupper()**   | Check uppercase    | **isxdigit()**  | Check hex digit |
| **tolower()**   | Convert lowercase  | **toupper()**   | Convert uppercase |

### **#include \<fstream>** //File Operations
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| **.close()**    | Close stream      | **.peek()**      | View next char |
| **.eof()**      | Check end         | **.putback()**   | Put char back |
| **.fail()**     | Check fail        | **.read()**      | Read block |
| **.get()**      | Get char          | **.readsome()**  | Read buffer |
| **.getline()**  | Get line          | **.seekg()**     | Set in pos |
| **.good()**     | Check state       | **.sync()**      | Sync buffer |
| **.ignore()**   | Skip chars        | **.tellg()**     | Get in pos |
| **.open()**     | Open stream       | **.unget()**     | Return char |
| **.is_open()**  | Check open        | **.write()**     | Write block |

### **#include \<iostream>** //Stream Operations
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| **.flush()**    | Flush buffer      | **.seekp()**     | Set out pos |
| **.put()**      | Put char          | **.tellp()**     | Get out pos |
| **.write()**    | Write block       | **.clear()**     | Clear flags |

### **#include \<sstream>** //String Stream Operations
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| **getline()**   | Get line from stream | **swap()**      | Swap contents |
| **.str()**      | Get/set content     | **.rdbuf()**    | Get buffer |
**------------------------------**
