# Realtime Console Ticker

This subdirectory demonstrates advanced class design concepts through a real-time console application that creates an animated ticker display.

## 📁 Files

- **main.cpp**: Real-time console ticker application
- **Screen.hpp/cpp**: Screen class with advanced features
- **Window_mgr.hpp/cpp**: Window manager class demonstrating friend classes
- **X.hpp/Y.hpp**: Forward declaration examples
- **KnowledgeComments.md**: Detailed documentation on Windows console functions

## 🎯 Learning Objectives

### Real-time Programming
- **Non-blocking Input**: Using `_kbhit()` and `_getch()` for immediate response
- **Console Manipulation**: Screen clearing and character positioning
- **Animation Loop**: Frame-based animation with timing control
- **Platform-Specific Features**: Windows console functions

### Advanced Class Design
- **Friend Classes**: Window_mgr as friend of Screen
- **Forward Declarations**: X.hpp and Y.hpp demonstrate circular dependencies
- **Class Composition**: Complex relationships between classes
- **Inline Functions**: Performance optimization techniques

## 🚀 How to Compile and Run

```bash
g++ -std=c++17 main.cpp Screen.cpp Window_mgr.cpp -o realtime_ticker
./realtime_ticker
```

## 🎮 How to Use

1. **Run the program**: Characters will start moving across the screen
2. **Press any key**: New characters will be added to the ticker
3. **Press 'q' or 'Q'**: Quit the program
4. **Watch the animation**: Characters move from right to left continuously

## 🔧 Key Concepts Demonstrated

- **Real-time Applications**: Non-blocking input and continuous updates
- **Class Relationships**: Friend classes and forward declarations
- **Console Programming**: Screen manipulation and character positioning
- **Animation**: Frame-based timing and character movement
- **Platform Integration**: Windows-specific console functions

## 📚 Documentation

**KnowledgeComments.md** contains detailed explanations of:
- `_kbhit()` and `_getch()` functions
- Windows console programming
- Non-blocking input techniques
- Platform-specific considerations

This demo showcases advanced C++ concepts in a practical, interactive application. 