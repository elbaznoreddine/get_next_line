# 📖 get_next_line

`get_next_line` is a focused project about reading a file descriptor one line at a time.

The idea is simple but powerful: build a reusable function that reads input efficiently without losing track of where the reader left off. It is a classic exercise in buffering, state management, and memory handling.

## ✨ Core idea

- Read from a file descriptor
- Preserve partial data between calls
- Return one complete line at a time
- Handle edge cases with care

## 🛠️ Compile

```bash
make
```

Then include the library in your C project and use the function as needed.

## 🎯 Why it matters

This project sharpens the fundamentals of file I/O and teaches how small, reusable building blocks make larger systems easier to build.

> A line at a time is still progress.
